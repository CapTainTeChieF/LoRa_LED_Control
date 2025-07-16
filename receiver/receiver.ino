#include <SoftwareSerial.h>

#define LED_PIN 13
SoftwareSerial loraSerial(8, 9); // RX, TX

String lora_RX_address = "2";

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  loraSerial.begin(115200);
  delay(1000);

  // LoRa Configuration
  loraSerial.println("AT+ADDRESS=" + lora_RX_address);
  delay(300);
  loraSerial.println("AT+NETWORKID=5");
  delay(300);
  loraSerial.println("AT+BAND=868500000");
  delay(300);

  Serial.println("LoRa Receiver Ready");
}

void loop() {
  String msg = "";
  while (loraSerial.available()) {
    char c = loraSerial.read();
    if (c == '\n') break;
    msg += c;
  }

  if (msg.startsWith("+RCV=")) {
    Serial.println("Received: " + msg);

    if (msg.indexOf("LED_ON") >= 0) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED ON");
    } else if (msg.indexOf("LED_OFF") >= 0) {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED OFF");
    }
  }
}
