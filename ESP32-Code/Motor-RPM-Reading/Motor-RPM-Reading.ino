const int enablePin = 26;
const int motorPin1 = 25;
const int motorPin2 = 33;
const int encoderPin = 14;

volatile int pulseCount = 0;
unsigned long previousMillis = 0;
unsigned long interval = 1000;
const int pulsesPerRevolution = 6;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 5;

void IRAM_ATTR pulseCounter() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    pulseCount++;
  }
}

void setup() {
  pinMode(enablePin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  digitalWrite(enablePin, LOW);
  pinMode(encoderPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin), pulseCounter, RISING);
  Serial.begin(115200);
}

void loop() {
  moveForward(255);
  calculateRPM();
}

void moveBackward(int speed) {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(enablePin, speed);
}

void moveForward(int speed) {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  analogWrite(enablePin, speed);
}

void stopMotor() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(enablePin, LOW);
}

void calculateRPM() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    float revolutions = pulseCount / (float)pulsesPerRevolution;
    float rpm = revolutions * (60000 / interval);
    Serial.print("RPM: ");
    Serial.println(rpm);
    pulseCount = 0;
  }
}
