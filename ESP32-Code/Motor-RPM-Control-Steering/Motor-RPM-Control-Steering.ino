#include <ESP32Servo.h> //Servo Esp32

//Motor
const int enablePin = 26;  //PWM Control Pin
const int motorPin1 = 25;  //Motor Pin 1
const int motorPin2 = 33;  //Motor Pin 2
const int encoderPin = 14; //Encoder Pin

//Encoder RPM
volatile int pulseCount = 0;
unsigned long previousMillis = 0;
unsigned long interval = 1000;
const int pulsesPerRevolution = 6;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 5;
float revolutions;
float rpm;

//PID Parameters
float error = 0;
float error_previous = 0;
float error_integral = 0;
float error_derivative = 0;
float kp = 0.3;//0.25;            //Kp
float ki = 0.13; //0.16//0.18;    //Ki
float kd = 0.000008;              //Kd
float dt = 0.01;                  //time dt
float set_rpm = 0;              //Set RPM
float pid_cal;                    //PID Calculation
int speed;

//Servo
//Define the Servo Pin
const int servoPin = 32;
//Initial Servo Degree
int servoPos = 90;
int angle = 0;
//Create a Servo Object
Servo steeringServo;

//Encoder pulse count function
void IRAM_ATTR pulseCounter() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    pulseCount++;
  }
}

void setup() {
  // put your setup code here, to run once:
  //Serial Monitor
  Serial.begin(115200);
  Serial.println("Motor RPM and Steering Control");
  //Servo Pin setup
  steeringServo.attach(servoPin);
  steeringServo.write(servoPos);
  //Motor Pin setup
  pinMode(enablePin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  //Encoder Pin setup
  digitalWrite(enablePin, LOW);
  pinMode(encoderPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin), pulseCounter, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // Read the incoming string
    String inputString = Serial.readStringUntil('\n');
    
    // Parse the RPM and steering values
    int input_rpm = 0;
    int input_steering = 0;
    parseInput(inputString, input_rpm, input_steering);
    set_rpm =  input_rpm;
    angle = input_steering;
    // Print the extracted values
    // Serial.print("RPM: ");
    // Serial.println(rpm);
    // Serial.print("Steering: ");
    // Serial.println(steering);
  }
  steering();
  calculateRPM();
  RPM_Control();
  moveForward();
}

//RPM calculate
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

//RPM PID Control
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

//Motor Forward Function
void moveForward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  analogWrite(enablePin, pid_cal);
}

//Motor Backward Function
void moveBackward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(enablePin, speed);
}

//Motor Stop
void stopMotor() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(enablePin, LOW);
}

void parseInput(String input, int &rpm, int &steering) {
  // Find the positions of "RPM=" and "Steering="
  int rpmPos = input.indexOf("RPM=");
  int steeringPos = input.indexOf("Steering=");
  
  // Extract the RPM value
  if (rpmPos >= 0) {
    int startPos = rpmPos + 4; // Position after "RPM="
    int endPos = input.indexOf(',', startPos);
    if (endPos == -1) endPos = input.length();
    rpm = input.substring(startPos, endPos).toInt();
  }
  
  // Extract the Steering value
  if (steeringPos >= 0) {
    int startPos = steeringPos + 9; // Position after "Steering="
    int endPos = input.indexOf(',', startPos);
    if (endPos == -1) endPos = input.length();
    steering = input.substring(startPos, endPos).toInt();
  }
}

void steering(){    
    angle = map(angle, -90, 90, 0, 180);
    if (angle >= 30 && angle <= 150) {
      servoPos = angle;
      steeringServo.write(servoPos);
      Serial.print("Steering Angle: ");
      Serial.println(servoPos);
    } else {
      // Serial.println("Invalid angle. Please enter a value between 0 and 180.");
    }
}