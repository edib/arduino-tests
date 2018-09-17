#include <AFMotor.h>
#include <Servo.h>              // Add library
Servo ust;
Servo alt;

int gunes_tepe = 45;
int gunes_alt = 90;

void setup() {

  ust.attach (10);          // Define the servo signal pins
  alt.attach (9);          // Define the servo signal pins

}

void loop() {
  /* ust motorun yolu
    //90dan başlayacak. bu durumda tam karşıya bakıyor.
    45 e kadar ya da güneşin en tepede olduğu yere kadar gelecek.
    sonra geri 90a dönecek.

  */
  int bas = 180;
  for (;  gunes_alt >= gunes_tepe; gunes_alt -= 1) {

    ust.write(gunes_alt);
    alt.write(bas);
    bas = bas - 2;
    delay(200);
  }

  for (; gunes_alt <= 90; gunes_alt += 1) {

    ust.write(gunes_alt);
    alt.write(bas);
    bas = bas - 2;
    delay(200);
  }

  delay(10000);
}
