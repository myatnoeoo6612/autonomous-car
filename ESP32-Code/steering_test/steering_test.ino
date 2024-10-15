#include <ESP32Servo.h>

Servo myServo;  // Create a Servo object

void setup() {
  myServo.attach(32);  // Attach the servo on GPIO 17
  Serial.begin(115200);
}

void loop() {
  for (int angle = 0; angle <= 160; angle += 1) { // Sweep from 0 to 180 degrees
    myServo.write(angle);              // Set the servo position
    Serial.print("Angle : ");
    Serial.println(angle);
    delay(5);                         // Wait for the servo to reach the position
  }

  for (int angle = 160; angle >= 0; angle -= 1) { // Sweeping back from 180 to 0 degrees
    myServo.write(angle);
    Serial.print("Angle : ");
    Serial.println(angle);
    delay(5);
  }
}
