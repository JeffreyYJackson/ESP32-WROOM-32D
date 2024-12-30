#include <Arduino.h>
#include <ESP32Servo.h>
#include <time.h>

#define TRIG 25
#define ECHO 26
#define SERVOPIN 14

Servo servo;

float Kp = 0;
float Ki = 0;
float Kd = 0;

float currentVal;
float setVal;

float error = 0;
float errorIntegral = 0;
float errorPrev = 0;

long dt;
long de;

float measureDistance();

void pidSetValue(float distance);
int pidLoop();

long prevTime;
long currentTime;

int output;

void setup() {
  Serial.begin(115200);

  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);

  servo.attach(SERVOPIN);

  pidSetValue(5);
  prevTime = millis();
}

void loop() {
  servo.write(pidLoop());
}

float measureDistance(){
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long time = pulseIn(ECHO, HIGH);
  float distance = time * 0.034/2;
  return distance;
}

void pidSetValue(float distance){
  setVal = distance;

}

int pidLoop(){
  //Read Current Val
  currentVal = measureDistance();
  Serial.println(currentVal);

  //Read Time
  currentTime = millis();
  dt = (currentTime - prevTime) / 1000; //In seconds

  //Calculate Error
  error = setVal - currentVal;
  errorIntegral += error * dt;
  
  //Calculate Error Gradient
  de = (error - errorPrev) / dt;

  //Calculate Output
  output = (Kp * error) + (Ki * errorIntegral) + (Kd * de);

  errorPrev = error;
  prevTime = currentTime;
}