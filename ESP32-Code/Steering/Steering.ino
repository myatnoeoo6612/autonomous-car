#include <ESP32Servo.h>

// Define the servo pin
const int servoPin = 32;

// Create a Servo object
Servo steeringServo;

// Variables for the servo position
int servoPos = 90; // Starting at the center position (90 degrees)

void setup() {
  // Attach the servo to the specified pin
  steeringServo.attach(servoPin);

  // Set initial servo position
  steeringServo.write(servoPos);

  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("Ackermann Steering Control Initialized");
}

void loop() {
  // Read the desired angle from the serial monitor for testing purposes
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();
    Serial.print("Entered Angle : ");
    Serial.println(angle);
    angle = map(angle, -90, 90, 0, 180);
    if (angle >= 30 && angle <= 150) {
      servoPos = angle;
      steeringServo.write(servoPos);
      Serial.print("Steering Angle: ");
      Serial.println(servoPos);
    } else {
      Serial.println("Invalid angle. Please enter a value between 0 and 180.");
    }
  }

  // Delay for a short period to avoid flooding the serial output
  delay(100);
}