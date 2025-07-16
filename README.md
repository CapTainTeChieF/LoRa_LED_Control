# LoRa LED Control using Arduino UNO and RYLR998

This project uses two Arduino UNOs and two RYLR998 LoRa modules to remotely control an LED using a push button.

## 🧩 Components Used

- 2x Arduino UNO
- 2x LoRa RYLR998 modules
- 1x Push button
- 1x LED (using Arduino pin 13)
- Jumper wires
- 1kΩ + 2kΩ resistors for voltage divider

## 🔌 Wiring

### Common for both Arduinos:

| LoRa Module | Arduino UNO |
|-------------|--------------|
| TX (DOUT)   | Pin 8        |
| RX (DIN)    | Pin 9 (via voltage divider: 2kΩ + 1kΩ) |
| VCC         | 3.3V         |
| GND         | GND          |

### Transmitter-specific:
- Button connected to pin 6 and GND

### Receiver-specific:
- LED connected to pin 13 (built-in)

## 📡 Communication Setup

Both LoRa modules use:
- `BAND`: 868.5 MHz
- `NETWORKID`: 5
- `BAUD`: 115200
- Transmitter Address: 1
- Receiver Address: 2

## 📂 File Structure

- `transmitter/`: Code for button press sender
- `receiver/`: Code for LED controller
