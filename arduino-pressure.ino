// Messure pressure by sensor MPXV5050

double L = 100.0; // длина трубки в см

void setup() {
  Serial.begin(9600);
}

void loop() {
  double p = analogRead(A0);

  // Давление водяного столба в кПа
  double h = (p/1024 - 0.04)/0.018; // kPa

  // Расчитываем поправку в см
  // double l = L - L * 100 / (100 + h);
  double l = L * h / (100.0 + h); 

  int total = h * 10.0 + l;
  Serial.println(total); 
  delay(200);
}
