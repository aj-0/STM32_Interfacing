# 📡 **MPU6050 Sensor Interfacing using I2C with STM32F407**
<img width="2844" height="1280" alt="630213071-5d69d253-19e1-4bbc-acf5-f22d88271d0c" src="https://github.com/user-attachments/assets/07d0a7e3-f35d-4604-ae80-6dfdc40541c9" />

## 📖 Short Description

This project demonstrates how to interface the **MPU6050 6-Axis Motion Sensor** with an **STM32F407 Discovery** board using the **I2C protocol**. The STM32 initializes the sensor, reads real-time **accelerometer** and **gyroscope** data, converts raw sensor values into meaningful physical measurements, and transmits the data over UART for monitoring and debugging. This project serves as a foundation for motion detection, balancing robots, drones, gesture recognition, and automotive sensing applications.

---

# 🛠️ Hardware & Software Tools

## 🔧 Hardware

* 🖥️ STM32F407 Discovery Board
* 📡 MPU6050 (GY-521 Module)
* 🔌 Jumper Wires
* 🐞 ST-LINK Debugger
* 🔗 USB Cable

---

# ⚙️ STM32CubeMX Configuration

## 🕒 Clock Configuration

* ✅ System Clock: 168 MHz
* ✅ I2C1 Peripheral Clock Enabled
* ✅ USART2 Peripheral Clock Enabled

## 🔩 Peripheral Configuration

### 📡 I2C1

* Master Mode
* Standard Mode (100 kHz)
* 7-bit Addressing
* HAL Driver Enabled

### 📍 GPIO

| Pin | Function  |
| --- | --------- |
| PB6 | I2C1_SCL  |
| PB7 | I2C1_SDA  |

