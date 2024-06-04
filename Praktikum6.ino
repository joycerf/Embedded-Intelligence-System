// C++ code
//
int Val = 0;

void setup()
{
  pinMode(A5, INPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  Val = analogRead(A5);
  Serial.println(Val);
  if (Val >= 20) {
    digitalWrite(2, HIGH);
    tone(3, 523, 1000); // play tone 60 (C5 = 523 Hz)
  } else {
    digitalWrite(2, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}