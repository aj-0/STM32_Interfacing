# 📚 **16x2 LCD Interfacing using PCF8574 (I2C) with STM32F407**
<img width="1040" height="633" alt="image" src="https://github.com/user-attachments/assets/f10d19e4-fc26-4810-a69b-a28e5e5cd5dd" />

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



