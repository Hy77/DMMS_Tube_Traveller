#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// def servo channel
const int servo_top1 = 0;
const int servo_top2 = 1;
const int servo_under1 = 2;
const int servo_under2 = 3;

void setup() {
  Serial.begin(9600); // serial port
  pwm.begin();
  pwm.setPWMFreq(60);  // set servo frequency
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // read char
    switch (command) {
      case 'w':
        moveForward();
        break;
      case 's':
        moveBackward();
        break;
      case 'q':
        rotateCounterClockwise();
        break;
      case 'e':
        rotateClockwise();
        break;
    }
  }
}

void moveForward() {
  // moving forward
  Serial.println('w');
  pwm.setPWM(servo_top1, 0, 4096);
  pwm.setPWM(servo_top2, 0, 4096);
  pwm.setPWM(servo_under1, 0, 4096);
  pwm.setPWM(servo_under2, 0, 4096);
}

void moveBackward() {
  // moving backward

}

void rotateClockwise() {
  // rotate CW

}

void rotateCounterClockwise() {
  // rotate CCW

}
