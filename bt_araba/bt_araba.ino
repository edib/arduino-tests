#include "Arduino.h"

#include <AFMotor.h>
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 13); // RX | TX

// dc motor test
AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm



void setup() {
  motor1.setSpeed(100);     // set the speed to 200/255
  motor2.setSpeed(100);     // set the speed to 200/255

  Serial.begin(9600);
  BTserial.begin(9600);
}

void loop() {

  if (BTserial.available())
  {
    char data = BTserial.read();
  Serial.write(data);
    // char ı integer'a çevirmek için
//    int data = data_f - '0';
    
    //int state = data;
    // sola dön
    if (data == 'l') {
      motor1.run(FORWARD);      // turn it on going forward
      motor2.run(BACKWARD);      // turn it on going forward
      delay(200);
      motor1.run(RELEASE);      // stopped
      motor2.run(RELEASE);     // the other way
    }
    // ileri git
    else if (data == 'u') {
      motor1.run(FORWARD);      // turn it on going backward
      motor2.run(FORWARD);     // the other way
      delay(1000);
      motor1.run(RELEASE);      // stopped
      motor2.run(RELEASE);     // the other way
      // sağa dön
    } else if (data == 'r') {
      motor1.run(BACKWARD);      // stopped
      motor2.run(FORWARD);     // the other way
      delay(200);
      motor1.run(RELEASE);      // stopped
      motor2.run(RELEASE);     // the other way
      // geri git
    } else if (data == 'd') {
      motor1.run(BACKWARD);      // stopped
      motor2.run(BACKWARD);     // the other way
      delay(1000);
      motor1.run(RELEASE);      // stopped
      motor2.run(RELEASE);     // the other way
    }
    else if (data == 'x') {
      motor1.run(RELEASE);      // stopped
      motor2.run(RELEASE);     // the other way
      delay(1000);
    }
    

  }
}
