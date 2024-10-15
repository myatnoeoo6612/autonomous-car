#include <ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float32.h>
#include <ackermann_msgs/AckermannDriveStamped.h>
#include <Servo.h> //Servo Esp32

// Motor
const int enablePin = 5;  // PWM Control Pin
const int motorPin1 = 6;  // Motor Pin 1
const int motorPin2 = 9;  // Motor Pin 2
const int encoderPin = 2; // Encoder Pin

// Wheel
const double diameter_mm = 65.0; // in mm

// Encoder RPM
volatile int pulseCount = 0;
unsigned long previousMillis = 0;
unsigned long interval = 1000;
const int pulsesPerRevolution = 6;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 5;
float revolutions;
float rpm;

// PID Parameters
float error = 0;
float error_previous = 0;
float error_integral = 0;
float error_derivative = 0;
float kp = 0.3;              // Kp
float ki = 0.13;             // Ki
float kd = 0.000008;         // Kd
float dt = 0.01;             // time dt
float set_rpm = 0;           // Set RPM
float pid_cal;               // PID Calculation
int speed;

// Servo
const int servoPin = 3;
int servoPos = 90;
int angle = 0;
int angle_drive = 0;
int my_angle;
Servo steeringServo;
float mps;
float my_rpm;

// Define ROS node handle
ros::NodeHandle nh;

// Function to count encoder pulses
void pulseCounter() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    pulseCount++;
  }
}

// Callback function to handle incoming messages
void driveCallback(const ackermann_msgs::AckermannDriveStamped& msg) {
  angle = msg.drive.steering_angle * (180 / 3.14) * -1; // Convert radians to degrees
  steering(angle);
  mps = msg.drive.speed; // get the speed in m/s
  my_rpm = (mps * 60)/0.065;
  // set_rpm = mps;
  // RPM_Control(my_rpm);
  mps = map(mps, 0, 3.0, 0, 200);
  // moveForward(mps);
}

ros::Subscriber<ackermann_msgs::AckermannDriveStamped> sub("ackermann_cmd", driveCallback);

void setup() {
  Serial.begin(57600);
  Serial.println("Motor RPM and Steering Control");

  // Servo setup
  steeringServo.attach(servoPin);
  steeringServo.write(servoPos);

  // Motor pins setup
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(encoderPin, INPUT_PULLUP);
  
  // Attach interrupt for encoder
  attachInterrupt(digitalPinToInterrupt(encoderPin), pulseCounter, RISING);

  // ROS setup
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();
  // calculateRPM();
  // RPM_Control();
  moveForward(mps);
  
  //delay(10);
}

void calculateRPM() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    revolutions = pulseCount / (float)pulsesPerRevolution;
    rpm = revolutions * (60000 / interval);
    pulseCount = 0;
  }
}

void RPM_Control(float set_rpm) {
  calculateRPM();
  error = rpm - set_rpm;
  error_integral += error * dt;
  error_derivative = (error - error_previous) / dt;
  error_previous = error;
  pid_cal = kp * error + ki * error_integral + kd * error_derivative;

  pid_cal = constrain(pid_cal, 0, 255);
  if (pid_cal > 255)  pid_cal = 255;
  if (pid_cal < -255) pid_cal = 255;
  if (pid_cal < 0) pid_cal = pid_cal*(-1);
  // if (pid_cal <= 80 && pid_cal >= -80) pid_cal = 80; 
  speed = pid_cal;
  // moveForward(speed);
  Serial.print("  RPM: ");
  Serial.print(rpm);
  Serial.print("    Speed : ");
  Serial.println(speed);
  
}

void moveForward(int my) {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  analogWrite(enablePin, my); // Control the motor speed using PWM

  // Debug Motor PWM
  Serial.print("Motor Speed (PWM): ");
  Serial.println(my);
}

void steering(int angle_drive) { 
  my_angle = angle_drive;   
  my_angle = map(my_angle, -90, 90, 0, 180);
  if (my_angle >= 0 && my_angle <= 180) {
    servoPos = my_angle;
    steeringServo.write(servoPos);
    Serial.print("Steering Angle: ");
    Serial.println(servoPos);
  }
}

// double convertToRPM(double speed_mps) {
//   double diameter_m = diameter_mm / 1000.0;
//   double circumference = PI * diameter_m;
//   double rps = speed_mps / circumference;
//   double rpm = rps * 60.0;
//   return rpm;
// }
