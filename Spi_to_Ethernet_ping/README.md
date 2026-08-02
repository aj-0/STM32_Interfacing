# 🌐 STM32 W5500 Ethernet Interface – Ping Test 
<img width="601" height="280" alt="630212708-324180c3-0ac0-4448-825b-2a06642ea189" src="https://github.com/user-attachments/assets/a538bc55-2f39-4900-b84d-0d1f3a99ab69" />

## 📖 Short Description

This project demonstrates how to interface the **WIZnet W5500 Ethernet Controller** with an **STM32F407 Discovery** board using the **SPI protocol**. The STM32 configures the W5500 with network parameters such as MAC address, IP address, subnet mask, and gateway. After successful initialization, the board responds to **ICMP Ping (Echo Request)** from a PC, verifying Ethernet connectivity. Since the W5500 integrates a **hardware TCP/IP stack**, the STM32 communicates with it only through SPI without implementing a software TCP/IP stack.

---



# 🛠️ Hardware & Software Tools

## 🔧 Hardware
* 🖥️ STM32F407 Discovery Board
* 🌐 W5500 Ethernet Module
* 🔌 Ethernet (RJ45) & Cable
* 🐞 ST-LINK Debugger
* 
## 💻 Software
* STM32CubeIDE
* STM32CubeMX
* STM32 HAL Drivers
* WIZnet ioLibrary Driver
* Wireshark (Packet Analysis)
* Command Prompt (`ping`)
* Git & GitHub

---

# ⚙️ STM32CubeMX Configuration

## 🔩 Peripheral Configuration
### 📡 SPI2

* Master Mode
* Full Duplex
* 8-bit Data
* Software NSS
* MSB First
* Suitable SPI Prescaler

### 📍 GPIO

| Pin             | Function    |
| --------------- | ----------- |
| PB13            | SPI2_SCK    |
| PB14            | SPI2_MISO   |
| PB15            | SPI2_MOSI   |
| PB12            | W5500_CS    |
| PD11            | W5500_RESET |

### 🌐 Network Configuration

* Static MAC Address
* Static IP Address
* Subnet Mask
* Gateway Address

---

# 🐞 Debugging & Problems Solved

## Problem
PC could not ping the STM32 Ethernet device.

## 🔍 Root Cause
Possible causes included incorrect SPI communication, invalid network configuration, W5500 initialization failure, or incorrect PHY/link status.

## 🛠️ Debugging Steps
* ✔️ Verified SPI communication by reading the W5500 version register.
* ✔️ Confirmed correct MAC, IP, subnet mask, and gateway configuration.
* ✔️ Checked Ethernet cable and router/switch connection.
* ✔️ Verified Link LED on the RJ45 connector.
* ✔️ Used Wireshark to inspect ARP and ICMP packets.
* ✔️ Confirmed SPI chip-select timing.
* ✔️ Verified W5500 reset sequence.
* ✔️ Used breakpoints and UART debug messages during initialization.

## ✅ Solution
Successfully initialized the W5500, configured valid network parameters, verified SPI communication, and confirmed that the device responded to ICMP Echo Requests from the PC.

## 🎯 Skills Demonstrated
* Ethernet Interface Bring-up
* SPI Peripheral Debugging
* Network Configuration
* W5500 Driver Integration
* ICMP Connectivity Verification
* Packet-Level Network Debugging

```
