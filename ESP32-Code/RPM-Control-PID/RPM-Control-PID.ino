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
float revolutions;
float rpm;

float error = 0;
float error_previous = 0;
float error_integral = 0;
float error_derivative = 0;
float set_rpm = 350;

float kp = 0.3;//0.25;
float ki = 0.13; //0.16//0.18;
float kd = 0.000008;
float dt = 0.01;

float pid_cal;

int speed;

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
  calculateRPM();
  RPM_Control();
  moveForward();
}

void moveBackward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(enablePin, speed);
}

void moveForward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  analogWrite(enablePin, pid_cal);
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
    revolutions = pulseCount / (float)pulsesPerRevolution;
    rpm = revolutions * (60000 / interval);
    // Serial.print("RPM: ");
    // Serial.println(rpm);
    pulseCount = 0;
  }
}

void RPM_Control(){
  error = rpm - set_rpm;
  Serial.print("Error RPM: ");
  Serial.print(error);
  error_integral += error*dt;
  error_derivative = (error - error_previous)/dt;
  error_previous = error;
  pid_cal = kp*error + ki*error_integral + kd*error_derivative;

  if (pid_cal > 255)  pid_cal = 255;
  if (pid_cal < -255) pid_cal = 255;
  if (pid_cal < 0) pid_cal = pid_cal*(-1);
  // if (pid_cal <= 80 && pid_cal >= -80) pid_cal = 80; 
  speed = pid_cal;
  Serial.print("  RPM: ");
  Serial.print(rpm);
  Serial.print("    Speed : ");
  Serial.println(speed);
}


