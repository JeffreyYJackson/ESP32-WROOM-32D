#include <Arduino.h>

#define SERVO_PIN 25

const int period = 20000;
void pulse(int pulseLength);

void setup() {
  pinMode(SERVO_PIN, OUTPUT);
  pulse(400);
  delay(300);
  pulse(300);
}

void loop() {
  //for (int i = 200; i <= 2400; i+=10){
  //  pulse(i);
  //}
  //for (int i = 2400; i >= 300; i-=10){
  //  pulse(i);
  //}
}

void pulse(int pulseLength){
  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(pulseLength);
  digitalWrite(SERVO_PIN, LOW);
  delayMicroseconds(period - pulseLength);
}