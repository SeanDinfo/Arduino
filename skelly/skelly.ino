/*
 * skelly.ino
 * Oct-31-2016
 * Sean Doherty
 * sean@seand.info
 * 
 * Simple Arduino sketch to automate a servo and two LEDs that were hacked into a cheap store bought
 * skeleton. There servo moving the jaw and the oversized LEDs placed in teh eye sockets. It was a very 
 * quick build but highly effective. 
 */

#include <Servo.h>

Servo servoJaw;
int leftEye = 5;            // Left eye LED pin
int rightEye = 6;           // Righ eye LED pin

int maxAngle = 45;          // Constrained by the physical setup
int eyePWMStep = 255 / maxAngle;

void setup() {
  servoJaw.attach(9);       // Attaches the servo on pin 9
}

void loop() {

  int pauseTime1 = random(2000, 20000);
  int jawMoves = random (5, 10);

  for (int jaw = 0; jaw <= jawMoves; jaw += 1) {
    int pauseTime2 = random(10, 2000);
    int stepTime = random(5, 35);
    for (int servoPos = maxAngle; servoPos >= 0; servoPos -= 1) {
      // Move the jaw up
      servoJaw.write(servoPos);
      int eyeBrightness = 255 - (servoPos * eyePWMStep);
      analogWrite(leftEye, eyeBrightness);
      analogWrite(rightEye, eyeBrightness);

      delay(stepTime);
    }

    for (int servoPos = 0; servoPos <= maxAngle; servoPos += 1) {
      //move the jaw down
      servoJaw.write(servoPos);
      int eyeBrightness = 255 - (servoPos * eyePWMStep);
      analogWrite(leftEye, eyeBrightness);
      analogWrite(rightEye, eyeBrightness);
      delay(10);
    }
    delay(pauseTime2);
  }
  analogWrite(leftEye, 5);
  analogWrite(rightEye, 5);
  delay(pauseTime1);
}

