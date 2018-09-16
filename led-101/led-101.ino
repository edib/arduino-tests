void setup() {
  // 11-13 pini aktif et
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
//önce hepsini sırayla yak 
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(11, HIGH);
  delay(500);
  //sonra hepsini sırayla söndür
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(12, LOW);
  delay(500);
  digitalWrite(11, LOW);
  delay(500);
}
