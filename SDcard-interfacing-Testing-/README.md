# 💾 **SD Card Interfacing & Testing using SPI with STM32F407**
<img width="1140" height="654" alt="image" src="https://github.com/user-attachments/assets/ab830209-ee07-46c6-b99c-51aa9987251b" />

## 📖 Short Description

This project demonstrates how to interface a **MicroSD Card** with an **STM32F407 Discovery** board using the **SPI protocol**. The project focuses on establishing reliable communication with the SD card, initializing it correctly, mounting the file system using **FATFS**, and performing basic file operations such as creating, writing, reading, and deleting files. It serves as a foundation for embedded data logging and persistent storage applications.

---


# 🛠️ Hardware & Software Tools

## 🔧 Hardware

* 🖥️ STM32F407 Discovery Board
* 💾 MicroSD Card Module (SPI)
* 📀 MicroSD Card (FAT32)
* 🐞 ST-LINK Debugger
* 🔍 Logic Analyzer (Optional)
* 🔗 USB Cable

## 💻 Software

* STM32CubeIDE
* STM32CubeMX
* STM32 HAL Drivers
* FATFS Middleware
* Git & GitHub

---

# ⚙️ STM32CubeMX Configuration

## 🕒 Clock Configuration

* ✅ HSE/HSI System Clock
* ✅ SPI2 Peripheral Clock Enabled

## 🔩 Peripheral Configuration

### 💾 SPI2

* Master Mode
* Full Duplex
* 8-bit Data Size
* Software NSS
* MSB First
* Appropriate Baud Rate Prescaler

### 📍 GPIO

| Pin  | Function   |
| ---- | ---------- |
| PB13 | SPI2_SCK   |
| PB14 | SPI2_MISO  |
| PB15 | SPI2_MOSI  |
| PB12 | SD Card CS |

## 📦 Middleware

* ✅ FATFS
* User-defined Disk I/O Driver

---

## 🎯 Skills Demonstrated

* SPI Communication Debugging
* FATFS Integration
* Storage Driver Development
* Embedded File System Debugging
* Peripheral Initialization Verification

---


<img width="1600" height="823" alt="image" src="https://github.com/user-attachments/assets/ddad51c5-5cc0-4ee3-ae12-5f6c8200b241" />

