#include <AFMotor.h>

// dc motor test
AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm



void setup() {
  motor1.setSpeed(150);     // set the speed to 200/255
  motor2.setSpeed(150);     // set the speed to 200/255
}

void loop() {
  // motorları ileri geri oynat
  motor2.run(FORWARD);      // turn it on going forward
  motor.run(FORWARD);     // the other way
  delay(1000);
  
  motor2.run(BACKWARD);      // turn it on going backward
  motor.run(BACKWARD);     // the other way
  delay(1000);
  
  motor.run(RELEASE);      // stopped
  motor2.run(RELEASE);     // the other way
  delay(1000);
}
