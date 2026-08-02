<img width="1040" height="633" alt="image" src="https://github.com/user-attachments/assets/f10d19e4-fc26-4810-a69b-a28e5e5cd5dd" />
# 📚 **16x2 LCD Interfacing using PCF8574 (I2C) with STM32F407**

## 📖 Short Description

This project demonstrates how to interface a **16x2 Character LCD** with an **STM32F407 Discovery** board using the **PCF8574 I/O Expander** over the **I2C protocol**. By using the PCF8574 module, the LCD requires only two communication lines (SCL and SDA), significantly reducing GPIO usage compared to the traditional 8-bit or 4-bit parallel interface.

---

# ⚙️ STM32CubeMX Configuration

## 🕒 Clock Configuration

* ✅ HSI/HSE (Default System Clock)
* ✅ I2C Peripheral Clock Enabled

## 🔩 Peripheral Configuration

### 📡 I2C1

* Mode: I2C Master
* Speed: 100 kHz (Standard Mode)
* 7-bit Addressing
* HAL Driver Enabled

### 📍 GPIO

| Pin | Function |
| --- | -------- |
| PB6 | I2C1_SCL |
| PB7 | I2C1_SDA |

## 🚨 NVIC Configuration

* I2C Interrupts Disabled (Polling Mode)

## 📦 Middleware

* None

---

# 🐞 Debugging & Problems Solved

## ❌ Problem

LCD remained blank after powering the circuit.

## 🔍 Root Cause

Incorrect I2C address, wiring issue, or LCD initialization sequence.

## 🛠️ Debugging Steps

* ✔️ Verified SDA and SCL wiring.
* ✔️ Confirmed the PCF8574 I2C address.
* ✔️ Checked LCD power and contrast adjustment.
* ✔️ Verified I2C peripheral initialization.
* ✔️ Used breakpoints to confirm LCD initialization functions were executed.
* ✔️ Monitored HAL I2C API return values.

## ✅ Solution

Configured the correct I2C address, completed the LCD initialization sequence, and verified communication between the STM32 and the PCF8574 module.

## 🎯 Skills Demonstrated

* I2C Peripheral Configuration
* LCD Driver Development
* Hardware Interface Debugging
* STM32 HAL API Usage
* Peripheral Communication Verification

---

# 📂 Project Structure

```text
16x2_LCD_PCF8574/
│
├── Core/
│   ├── Inc/
│   └── Src/
│
├── Drivers/
│
├── Debug/
│
├── 16x2_LCD_PCF8574.ioc
│
└── README.md
```
