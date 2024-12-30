#include <Arduino.h>

#define TRIG 25
#define ECHO 26

float measureDistance();

void setup() {
  Serial.begin(115200);

  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  Serial.print("Distance: ");
  Serial.println(measureDistance());

  delay(20);
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