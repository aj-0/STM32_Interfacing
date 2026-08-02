/* ==========================================================
   main.c — STM32F407 Discovery
   4-LED continuous sine breathing on PD12-PD15 via TIM4
   No LUT, no table — pure live sinf() via hardware FPU
   SYSCLK = 84MHz (HSI PLL)
   ========================================================== */

#include "stm32f4xx_hal.h"
#include <math.h>

TIM_HandleTypeDef htim4;

static volatile uint16_t step = 0;   /* 0 to 255, wraps */

/* ── IRQ Callback ─────────────────────────────────────────
   Called every 10ms (100Hz).
   sinf() executes in ~14 FPU cycles on M4 — no overhead.
   ──────────────────────────────────────────────────────── */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM4)
    {
        float angle = (2.0f * 3.14159265f * step) / 256.0f;
        uint16_t ccr = (uint16_t)(50.0f + 949.0f * (1.0f - cosf(angle)) / 2.0f);
        /* faster — 1.3s */
        step = (step + 1) & 0xFF;   /* keep as is, change PSC to 419 */

        /* slower — 5s */
        step = (step + 1) & 0xFF;   /* keep as is, change PSC to 1679 */
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, ccr);
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, ccr);
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, ccr);
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, ccr);
    }
}

/* ── System Clock ─────────────────────────────────────────
   HSI → PLL → 84MHz
   ──────────────────────────────────────────────────────── */
static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef osc = {0};
    RCC_ClkInitTypeDef clk = {0};

    osc.OscillatorType      = RCC_OSCILLATORTYPE_HSI;
    osc.HSIState            = RCC_HSI_ON;
    osc.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    osc.PLL.PLLState        = RCC_PLL_ON;
    osc.PLL.PLLSource       = RCC_PLLSOURCE_HSI;
    osc.PLL.PLLM            = 8;
    osc.PLL.PLLN            = 84;
    osc.PLL.PLLP            = RCC_PLLP_DIV2;
    osc.PLL.PLLQ            = 7;
    HAL_RCC_OscConfig(&osc);

    clk.ClockType      = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                         RCC_CLOCKTYPE_PCLK1  | RCC_CLOCKTYPE_PCLK2;
    clk.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
    clk.AHBCLKDivider  = RCC_SYSCLK_DIV1;
    clk.APB1CLKDivider = RCC_HCLK_DIV2;
    clk.APB2CLKDivider = RCC_HCLK_DIV1;
    HAL_RCC_ClockConfig(&clk, FLASH_LATENCY_2);
}

/* ── TIM4 Init ────────────────────────────────────────────
   PSC=839 ARR=999 → 100Hz IRQ → 2.56s breath cycle
   ──────────────────────────────────────────────────────── */
static void MX_TIM4_Init(void)
{
    __HAL_RCC_TIM4_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    GPIO_InitTypeDef gpio = {0};
    gpio.Pin       = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    gpio.Mode      = GPIO_MODE_AF_PP;
    gpio.Pull      = GPIO_NOPULL;
    gpio.Speed     = GPIO_SPEED_FREQ_HIGH;
    gpio.Alternate = GPIO_AF2_TIM4;
    HAL_GPIO_Init(GPIOD, &gpio);

    htim4.Instance               = TIM4;
    htim4.Init.Prescaler         = 839;
    htim4.Init.CounterMode       = TIM_COUNTERMODE_UP;
    htim4.Init.Period            = 999;
    htim4.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    HAL_TIM_PWM_Init(&htim4);

    TIM_OC_InitTypeDef oc = {0};
    oc.OCMode     = TIM_OCMODE_PWM1;
    oc.Pulse      = 0;
    oc.OCPolarity = TIM_OCPOLARITY_HIGH;
    oc.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim4, &oc, TIM_CHANNEL_1);
    HAL_TIM_PWM_ConfigChannel(&htim4, &oc, TIM_CHANNEL_2);
    HAL_TIM_PWM_ConfigChannel(&htim4, &oc, TIM_CHANNEL_3);
    HAL_TIM_PWM_ConfigChannel(&htim4, &oc, TIM_CHANNEL_4);
}

/* ── main ─────────────────────────────────────────────── */
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_TIM4_Init();

    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);

    HAL_TIM_Base_Start_IT(&htim4);

    HAL_NVIC_SetPriority(TIM4_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(TIM4_IRQn);

    while (1) {}
}
