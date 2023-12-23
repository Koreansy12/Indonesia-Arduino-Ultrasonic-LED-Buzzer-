# Sensor Ultra Sonic HC-SR04 dengan Uno dengan output buzzer dan LED 
## Schematic nya bisa anda lihat dibawah ini
![image_2023-12-24_020226729](https://github.com/Koreansy12/Indonesia-Arduino-Ultrasonic-LED-Buzzer-/assets/68386928/d28bdfb8-0c62-426c-9c45-8b353c3ba69e)

## Atau Link Tinkercad
https://www.tinkercad.com/things/78FT672Kdym-arduino-us?sharecode=zlurkjA-j04iXUWs_t9mY4sSQAxPDnTJLjoXz8Cpv54

#
 ## Pendefinisian Konstanta dan Variabel
#### #define LED 4 // Pin untuk mengendalikan lampu LED
#### int trigPin = 8;    // Pin TRIG sensor ultrasonik
#### int echoPin = 9;    // Pin ECHO sensor ultrasonik
#### int Freq = 1600;    // Frekuensi untuk Speaker
#### float kecepatan_suara  = 0.034; // Kecepatan suara dalam milidetik (0.034 milidetik = 343 m/s)
#### float duration_us, distance; // Variabel untuk menyimpan waktu dan jarak
### Di bagian ini, kita mendefinisikan pin yang akan digunakan untuk mengendalikan lampu LED dan sensor ultrasonik, serta mendeklarasikan variabel-variabel untuk menyimpan waktu dan jarak yang diukur.
#
## Setup()
#### void setup() {
#####   Serial.begin(9600); // Inisialisasi komunikasi serial
#####   pinMode(trigPin, OUTPUT); // Konfigurasi pin TRIG sebagai OUTPUT
#####   pinMode(echoPin, INPUT);  // Konfigurasi pin ECHO sebagai INPUT
##### }
### Di dalam fungsi setup(), Kita melihat bahwa terdapat komunikasi serial dan mengatur mode pin untuk sensor ultrasonik (TRIG sebagai OUTPUT dan ECHO sebagai INPUT).
#
## Loop()

#### void loop() {
  ##### digitalWrite(trigPin, HIGH); // Membangkitkan pulsa 10 mikrodetik ke pin TRIG
  #####  delay(10);
  #####  digitalWrite(trigPin, LOW);

 #####   duration_us = pulseIn(echoPin, HIGH); // Mengukur durasi pulsa dari pin ECHO
  #####  distance = kecepatan_suara / 2 * duration_us; // Menghitung jarak berdasarkan durasi pulsa

  #####  Serial.print("distance: ");
   ##### Serial.print(distance);
  #####  Serial.println(" cm");

  #####  // Kondisi untuk tindakan berdasarkan jarak yang diukur
  #####  if (distance > 50) {
   #####   // Aksi saat jarak > 50 cm
  #####    // ...
 #####   } else if (distance > 30) {
  #####    // Aksi saat jarak 30-50 cm
  #####    // ...
  #####  } else if (distance > 20) {
   #####   // Aksi saat jarak 20-30 cm
   #####   // ...
  #####  } else if (distance > 10) {
  #####    // Aksi saat jarak 10-20 cm
 #####     // ...
 #####   } else if (distance < 9) {
   #####   // Aksi saat jarak < 9 cm
   #####   // ...
  #####  }

  #####  delay(1); // Delay untuk stabilisasi
 ##### }
### Di dalam loop(), Anda melakukan pengukuran menggunakan sensor ultrasonik dengan menghasilkan pulsa, mengukur durasi pulsa yang kembali, dan mengonversi durasi pulsa menjadi jarak. Selanjutnya, Anda menggunakan kondisi if untuk menentukan aksi yang harus diambil berdasarkan jarak yang diukur.




