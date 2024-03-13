const int sensorPin = A1; 

void setup() {
  Serial.begin(9600); // Mulai komunikasi serial dengan kecepatan 9600 bps

}

void loop() {
  // Membaca nilai kelembaban dari sensor
  int sensorValue = analogRead(A1);

  if (sensorValue >= 1000);
  else if ((sensorValue <= 999) && (sensorValue >=901));
  else if (sensorValue <= 900);
  else ;

  if (sensorValue >= 1000) (Serial.print("SOIL IS TOO DRY!!!!!"));
  else if ((sensorValue <= 999) && (sensorValue >=901)) (Serial.print("SOIL IS PERFECT!!!!!"));
  else if (sensorValue <= 900) (Serial.print("SOIL IS TOO WET!!!!!"));
  else;

  Serial.print("Soil Humidity is: ");
  Serial.println(sensorValue);
  
  delay(1000);
} 
