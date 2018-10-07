
// kaynak
//http://www.martyncurrey.com/arduino-and-hc-06-zs-040/




#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX

void setup()
{

  Serial.begin(9600);
  Serial.println("Enter AT commands:");

  // HC-06 default serial speed is 9600
  BTserial.begin(9600);
pinMode(12,OUTPUT);
}

void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTserial.available())
  {
    char data = BTserial.read();
    //Serial.write(data);
    
    // char ı integer'a çevirmek için
    int myint = data - '0';
    for (int i = 0; i<myint; i++) {
    digitalWrite(12, HIGH);  
    delay(200);    
    digitalWrite(12, LOW);  
    delay(100);    
    }
  }
  // Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial.available())
  {
    BTserial.write(Serial.read());
  }

}
