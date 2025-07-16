## 📖 Project Description

This project demonstrates a simple **LoRa-based wireless control system** using **two Arduino UNOs** and **RYLR998 LoRa modules**.

A push button on the transmitter Arduino sends `"LED_ON"` and `"LED_OFF"` commands over LoRa. The receiver Arduino listens for these commands and toggles an LED connected to pin 13 accordingly.

### 🔧 Key Features
- LoRa-based communication using RYLR998 (868.5 MHz)
- AT command interface via `SoftwareSerial`
- Minimal hardware: 2 Arduinos + 2 LoRa modules + button + LED
- Clean and readable code, ready for expansion

### 🌱 Use Cases
- Wireless light or fan control
- Remote signaling systems
- LoRa-based sensor-actuator links in smart agriculture or IoT

This project is ideal for anyone learning LoRa communication with Arduino or building low-power, long-range wireless control systems.
