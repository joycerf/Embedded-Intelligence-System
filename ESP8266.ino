 //Sertakan file library
#include <LiquidCrystal_I2C.h>   // Library untuk menggunakan layar LCD I2C
#include <ESP8266WiFi.h>        // Library WiFi ESP8266

//Inisialisasi tampilan LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Objek LCD I2C

char ssid[] = ""; // Masukkan nama WiFi Anda
char pass[] = ""; // Masukkan kata sandi WiFi Anda

bool Relay = 0;  // Variabel untuk menyimpan status pompa

//Tentukan pin komponen
#define sensor A0       // Pin analog untuk sensor kelembaban tanah
#define waterPump D3    // Pin digital untuk relay pompa air

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
  pinMode(waterPump, OUTPUT); // Set pin pompa air sebagai OUTPUT
  digitalWrite(waterPump, HIGH); // Matikan pompa air secara awal
  lcd.init(); // Inisialisasi LCD
  lcd.backlight(); // Nyalakan backlight LCD

  // Tampilkan pesan loading sistem di LCD
  lcd.setCursor(1, 0);
  lcd.print("Sistem Memuat");
  for (int a = 0; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(500);
  }
  lcd.clear();

  //Panggil fungsi soilMoistureSensor secara berkala
  // timer.setInterval(100L, soilMoistureSensor); // Anda dapat memanggil fungsi ini secara berkala jika diperlukan
}

// Fungsi untuk membaca sensor kelembaban tanah dan memperbarui LCD
void soilMoistureSensor() {
  int value = analogRead(sensor); // Baca nilai analog dari sensor
  value = map(value, 0, 1024, 0, 100); // Peta nilai sensor ke persentase kelembaban
  value = (value - 100) * -1; // Balikkan nilai yang dipetakan

  lcd.setCursor(0, 0);
  lcd.print("Kelembaban :");
  lcd.print(value);
  lcd.print(" ");
}

void loop() {
  // Jalankan fungsi untuk membaca sensor kelembaban tanah secara berkala
  soilMoistureSensor();

  // Kendalikan pompa berdasarkan kondisi tertentu, misalnya jika kelembaban tanah rendah
  int moisture = analogRead(sensor);
  moisture = map(moisture, 0, 1024, 0, 100); // Peta nilai sensor ke persentase kelembaban
  if (moisture < 30) { // Contoh kondisi: jika kelembaban tanah kurang dari 30%
    digitalWrite(waterPump, LOW); // Nyalakan pompa
    lcd.setCursor(0, 1);
    lcd.print("Motor Menyala ");
  } else {
    digitalWrite(waterPump, HIGH); // Matikan pompa
    lcd.setCursor(0, 1);
    lcd.print("Motor Mati");
  }

  delay(1000); // Beri sedikit keterlambatan agar tidak terlalu cepat membaca sensor dan mengontrol pompa
}
