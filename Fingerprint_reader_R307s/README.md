# 👆 Fingerprint Enrollment & Authentication using R307S ( Interrupt / Touch Pin)
<img width="1280" height="582" alt="image" src="https://github.com/user-attachments/assets/240f431b-070c-4c79-b2e3-e3a5da34b962" />

## 📖 Short Description

This project demonstrates a **Fingerprint Enrollment and Authentication System** using the **R307S Optical Fingerprint Sensor** interfaced with an **STM32F407 Discovery** board via UART. The system captures a fingerprint, generates feature templates in two internal character buffers, stores the fingerprint in the sensor's flash memory, and later performs fingerprint matching using the search command. Successful authentication turns **ON a Green LED**, while an unsuccessful match turns **ON a Red LED**, simulating a basic biometric access control system.

---

# 🛠️ Hardware & Software Tools

## 🔧 Hardware

- 🖥️ STM32F407 Discovery Board
- 👆 R307S Optical Fingerprint Sensor

---

### 🔩 UART Configuration

- USART2 Asynchronous Mode
- Baud Rate : **57600 bps**
- 8 Data Bits
- No Parity
- 1 Stop Bit
- TX & RX Enabled

### 📍 GPIO Configuration

| Pin | Function |
|------|----------|
| PA2 | USART2_TX |
| PA3 | USART2_RX |

PA1  / Any gpio pin - Interrupt with PULL UP & Falling edge detection

---

# 🐞 Debugging & Problems Solved

## Problem
Fingerprint sensor was not responding correctly to UART commands.

## 🔍 Root Cause
- Incorrect command packet format.
- **Wrong packet checksum**.
- Timeout while waiting for sensor response.
- Incorrect packet length.

## 🛠️ Debugging Steps
- ✔️ Verified UART TX/RX connections.
- ✔️ Checked baud rate configuration.
- ✔️ Validated command packet structure.
- ✔️ Calculated packet checksum manually.
- ✔️ Printed transmitted and received packets through UART.
- ✔️ Verified ACK packets returned by the sensor.
- ✔️ Used breakpoints to inspect received data.
- ✔️ Checked HAL UART return status.

## ✅ Solution
Corrected the UART packet structure, checksum calculation, and command sequence. Successfully enrolled fingerprints, stored templates in the sensor's flash memory, and authenticated fingerprints using the search command with LED indication.

## 🎯 Skills Demonstrated
- UART Communication
- Binary Packet Construction
- Fingerprint Sensor Integration
-  Protocol Debugging
- STM32 HAL Driver Usage

---

# 📚 Concepts Covered
- 👆 **Fingerprint Enrollment Process** – Capturing the same finger twice, generating two character files, and combining them into a fingerprint template.
- 💾 **Template Storage** – Storing fingerprint templates in the R307S internal flash library with a unique template ID.
- 🔍 **Fingerprint Authentication** – Searching the sensor's database to compare a live fingerprint against previously enrolled templates.
- 📦 **UART Packet Protocol** – Constructing command packets with header, address, packet identifier, length, command, parameters, and checksum.
- 📨 **ACK Packet Handling** – Receiving, decoding, and validating acknowledgement packets returned by the fingerprint sensor.
- ⚙️ **Sensor Command Sequence** – Executing the complete workflow: Handshake → Capture Image → Generate Character File → Merge Template → Store Template → Search Template.

---
<img width="1600" height="999" alt="image" src="https://github.com/user-attachments/assets/abe4a501-36b2-4586-b798-f3770baff0e4" />
