// Pin Definitions
const int enablePin = 26; // Enable pin
const int motorPin1 = 25; // Motor control pin 1
const int motorPin2 = 33; // Motor control pin 2

void setup() {
  // Set pin modes
  pinMode(enablePin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  // Start with the motor off
  digitalWrite(enablePin, LOW);
}

void loop() {
  moveForward(255); // Full speed
  delay(2000);       // Move backward for 2 seconds
}


void moveBackward(int speed) {
  digitalWrite(motorPin1, HIGH); // Set motor pin 1 high
  digitalWrite(motorPin2, LOW);   // Set motor pin 2 low
  analogWrite(enablePin, speed);   // Set speed
}


void moveForward(int speed) {
  digitalWrite(motorPin1, LOW);    // Set motor pin 1 low
  digitalWrite(motorPin2, HIGH);   // Set motor pin 2 high
  analogWrite(enablePin, speed);    // Set speed
}

// Function to stop the motor
void stopMotor() {
  digitalWrite(motorPin1, LOW);     // Set motor pin 1 low
  digitalWrite(motorPin2, LOW);     // Set motor pin 2 low
  digitalWrite(enablePin, LOW);      // Disable the motor
}
