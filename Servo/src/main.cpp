#include <Arduino.h>
#include <ESP32Servo.h>

#define SERVOPIN 25

Servo servo;


void setup() {
  servo.attach(SERVOPIN);
}

void loop() {
  for(int i = 0; i <= 180; i++){
    servo.write(i);
    delay(15);
  }
  for(int i = 180; i >= 0; i--){
    servo.write(i);
    delay(15);
  }
}
