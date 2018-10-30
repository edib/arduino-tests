// kaynak
// http://www.martyncurrey.com/arduino-and-hc-06-zs-040/
#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h> // Add library
// Servo ust;
Servo alt;
SoftwareSerial BTserial(2, 3); // RX | TX
int lp = 4;
int left; 
int right;
void setup()
{
  alt.attach(10); // Define the servo signal pins
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  // HC-06 default serial speed is 9600
  BTserial.begin(9600);
  
}

void loop()
{
  // digitalWrite(lp, HIGH);
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTserial.available())
  {
    char data = BTserial.read();

    // Serial.write(data);
    // char ı integer'a çevirmek için
    int myint = data - '0';
    int state = data;
    if (data == 'l') {
    alt.write(state + 50);  
    } 
    else if (data == 'r') {
    alt.write(state - 50);    
    } else if (data == 'x') {
    alt.write(0);    
    }
    
    /* for (int i = 0; i < myint; i++)
    {
      digitalWrite(lp, HIGH);
      delay(200);
      digitalWrite(lp, LOW);
      delay(100);
    }
    */
  }
  // Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial.available())
  {
    BTserial.write(Serial.read());
  }
}
