#include <Servo.h>

Servo miServo;
int anguloServo = 0;

void setup() {
  miServo.attach(3);
}

void loop() {
  anguloServo = 45;
  miServo.write(anguloServo);
}
