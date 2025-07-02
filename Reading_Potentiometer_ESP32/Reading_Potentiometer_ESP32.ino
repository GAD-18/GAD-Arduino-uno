const int potPin = 15;
const int ledPin = 3;

void setup() {
   pinMode(ledPin, OUTPUT);
   Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(potPin);
  int brightness = map(potValue, 0, 4095, 0, 1023);

  for ( int i = 0; i < 50; i++) {
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(brightness);
    digitalWrite(ledPin, LOW);
    delayMicroseconds(1023 - brightness);
  }

  Serial.println(brightness);
}