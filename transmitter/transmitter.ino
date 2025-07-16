#include <SoftwareSerial.h>

#define BUTTON_PIN 6
SoftwareSerial loraSerial(8, 9); // RX, TX

String lora_TX_address = "1";
String lora_RX_address = "2";

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
  loraSerial.begin(115200);
  delay(1000);

  // LoRa Configuration
  loraSerial.println("AT+ADDRESS=" + lora_TX_address);
  delay(300);
  loraSerial.println("AT+NETWORKID=5");
  delay(300);
  loraSerial.println("AT+BAND=868500000");
  delay(300);

  Serial.println("LoRa Transmitter Ready");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    loraSerial.println("AT+SEND=" + lora_RX_address + ",7,LED_ON");
    Serial.println("Sent: LED_ON");
    delay(1500); // debounce
  } else {
    loraSerial.println("AT+SEND=" + lora_RX_address + ",8,LED_OFF");
    Serial.println("Sent: LED_OFF");
    delay(1500); // debounce
  }
}
