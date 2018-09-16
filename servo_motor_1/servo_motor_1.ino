#include <AFMotor.h>
#include <Servo.h>              // Add library
Servo servo1;               
Servo servo2;               

int servo_position = 0 ;
int path = 180;

void setup() {
  
servo1.attach (10);          // Define the servo signal pins
servo2.attach (9);          // Define the servo signal pins

}

void loop() {
 for (; servo_position <=path; servo_position +=1) {

    servo1.write(servo_position);
    servo2.write(servo_position);
    delay(1000);
  }

  for (path; servo_position >= 0; servo_position -=1){

    servo1.write(servo_position);
    servo2.write(servo_position);
    delay(1000);
  }

  //delay(100000);
}
