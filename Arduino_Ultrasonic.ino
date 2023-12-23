#define LED 4 //mendefinisikan bahwa pin 4 ada lampu LED

int trigPin = 8;    // TRIG pin
int echoPin = 9;    // ECHO pin
int Freq = 1600;    // Ini frekuensi Speaker
float kecepatan_suara  = 0.034; // kecepatan suara disini dalam milidetik jadi 343m/s jadi 0.343 m/ms
float duration_us, distance; //ini buat bikin variable float

void setup() {
  // begin serial port
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

void loop() {

  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance = kecepatan_suara/2 * duration_us; //di bagi 2? Karena sensor ultrasonic kan memantulkan suara jadi ada delay untuk di terima kembali ke receiver  

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");



  if(distance > 50){ // Saat jarak 50 Cm maka:
    tone(3,Freq); // Buzzer akan berbunyi selama
    digitalWrite(4,1); // Lampu akan menyala selama
    delay(100); //100 mili deitk
    noTone(3); //Buzzer akan mati selama 
    digitalWrite(4,0); // Lampu akan mati selama
    delay(2000); // 2 Detik
    }
  if(distance>30){
    tone(3,Freq); // Buzzer akan berbunyi selama
    digitalWrite(4,1); // Lampu akan menyala selama
    delay(100); //100 mili deitk
    noTone(3); //Buzzer akan mati selama 
    digitalWrite(LED,0); // Lampu akan mati selama
    delay(1000); //1 Detik

  }
  if(distance >20 ){
    tone(3, Freq); // Buzzer akan berbunyi selama
    digitalWrite(LED,1); // Lampu akan menyala selama
    delay(100); //100 mili detik
    noTone(3); //Buzzer akan mati selama 
    digitalWrite(LED,0); // Lampu akan mati selama
    delay(250); //250 Milidetik
  }

  if(distance > 10){

    tone(3,Freq); // Buzzer akan berbunyi selama
    digitalWrite(LED,1);// Lampu akan menyala selama
    delay(100); //100 mili etik
    noTone(3); //Buzzer akan mati selama 
    digitalWrite(LED,0); // Lampu akan mati selama
    delay(100); //100 mili detik
  }
    if(distance < 9){

    tone(3,Freq); // Buzzer akan berbunyi selama
    digitalWrite(LED,1); // Lampu akan menyala selama
    //Selama jarak di bawah 9 cm

  }
  delay(1);
}