#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// def servo channel
const int servo_top1 = 0;
const int servo_top2 = 1;
const int servo_under1 = 2;
const int servo_under2 = 3;

// fake delay
unsigned long currentTime = 0; // cur time
unsigned long previousTime = 0; // pre time

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
      default:
        pwm.writeMicroseconds(servo_top1,0);
        pwm.writeMicroseconds(servo_top2,0);
        pwm.writeMicroseconds(servo_under1,0);
        pwm.writeMicroseconds(servo_under2,0);
        break;
    }
  }
}

void fakeDelay(int delayTime) {
  currentTime = millis(); // get cur time

  // 如果距离上一次旋转已经超过指定的延迟时间，就返回
  if (currentTime - previousTime >= delayTime) {
    previousTime = currentTime; // update pre time
    return;
  }
  // wait if...
  while (currentTime - previousTime < delayTime) {
    currentTime = millis(); // update cur
  }
  previousTime = currentTime; // update pre
}

void moveForward() {
  // moving forward
  Serial.println('w');
  pwm.writeMicroseconds(servo_top1,2500);
  fakeDelay(3000);
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
