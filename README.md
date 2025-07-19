# Arduino Potentiometer LED Brightness Control 🔆

![Circuit Diagram](/screenshots/circuit.png)  
ESP32 code that controls LED brightness using a potentiometer

## 📋 Project Details
- *Repository*: [GAD-18/GAD-Arduino-uni](https://github.com/GAD-18/GAD-Arduino-uno)
- *File*: Potentiometer_LED.ino
- *Hardware*:
  - ESP32 Board
  - 10KΩ Potentiometer
  - LED + 220Ω Resistor
  - Breadboard & Jumper Wires

## 🛠 Circuit Connections
| Component | ESP32 Pin |
|-----------|----------|
| Potentiometer Middle Pin | GPIO 15 (Analog Input) |
| Potentiometer VCC | 3.3V |
| Potentiometer GND | GND |
| LED Anode | GPIO 3 (PWM Output) |
| LED Cathode | GND (via resistor) |

## 💻 Code Explanation
```cpp
const int potPin = 15;  // Potentiometer on GPIO15
const int ledPin = 3;   // LED on GPIO3

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(potPin);
  int brightness = map(potValue, 0, 4095, 0, 255);
  analogWrite(ledPin, brightness);
  Serial.println(brightness);
  delay(50);
}
