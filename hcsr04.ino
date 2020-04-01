#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <TimerOne.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Sensor
const int trigPin_A = 53;
const int echoPin_A = 52;
const int trigPin_B = 51;
const int echoPin_B = 50;
const int trigPin_C = 49;
const int echoPin_C = 48;
const int trigPin_D = 47;
const int echoPin_D = 46;
const int trigPin_E = 45;
const int echoPin_E = 44;
const int trigPin_F = 43;
const int echoPin_F = 42;
const int LH1 = 41;
const int LK1 = 40;
const int LM1 = 39;
const int LH2 = 38;
const int LK2 = 37;
const int LM2 = 36;
const int LH3 = 35;
const int LK3 = 34;
const int LM3 = 33;
int statusambulan;
int t = 5;
int kondisiJalur1=1;
int kondisiJalur2=1;
int kondisiJalur3=1;
//Sensor Ultrasonik pin
//Durasi Lampu Lalu Lintas
int kuningDelay = 2000;
int hijauSepi = 5000;
int hijauNormal = 7000;
int hijauPadat = 10000;
int ambulan = 10000;
int A,B,C,D,E,F;
//Durasi Lampu Lalu Lintas
//Var Global
long duration;
int distance;
int detik, detikShow;

//Var Global

void setup() {
Serial.begin(9600);
Serial2.begin(9600);
Serial3.begin(9600);
lcd.begin();
pinMode(trigPin_A, OUTPUT);
pinMode(echoPin_A, INPUT);
pinMode(trigPin_B, OUTPUT);
pinMode(echoPin_B, INPUT);
pinMode(trigPin_C, OUTPUT);
pinMode(echoPin_C, INPUT);
pinMode(trigPin_D, OUTPUT);
pinMode(echoPin_D, INPUT);
pinMode(trigPin_E, OUTPUT);
pinMode(echoPin_E, INPUT);
pinMode(trigPin_F, OUTPUT);
pinMode(echoPin_F, INPUT);
pinMode(LH1, OUTPUT);
pinMode(LK1, OUTPUT);
pinMode(LM1, OUTPUT);
pinMode(LH2, OUTPUT);
pinMode(LK2, OUTPUT);
pinMode(LM2, OUTPUT);
pinMode(LH3, OUTPUT);
pinMode(LK3, OUTPUT);
pinMode(LM3, OUTPUT);
Serial.begin(9600);
Serial2.begin(9600);
Serial3.begin(9600);
lcd.begin();
lcd.setCursor(0,0);
lcd.print("Startup Berhasil");
Serial.println("ok");
statusambulan = 0;
  Timer1.initialize(500000); 
  Timer1.attachInterrupt(softInterr);

}
void loop() {
  kondisi1();
  jalur1();
  jalur2();
  jalur3();
  Serial.println(statusambulan);
}
void softInterr(){
          
    Serial3.write("s");
    if (Serial3.available()>0)
    {
      statusambulan=Serial3.read();
      }
      if(statusambulan == 0){
        statusambulan=0;
      }else if(statusambulan == 1){
        Serial.println("jalur 1 Dibuka  ");
      }else if(statusambulan == 2){
        Serial.println("jalur 2 Dibuka  ");
      }else if(statusambulan == 3){
        Serial.println("jalur 3 Dibuka  ");
      }else {
        statusambulan=0;
      }
        Serial3.flush();
}  

void sensorA()
{
  digitalWrite(trigPin_A, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin_A, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_A, LOW);
  duration = pulseIn(echoPin_A, HIGH);
  A= duration*0.034/2;
  duration =0;
}
void sensorB()
{
  digitalWrite(trigPin_B, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin_B, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_B, LOW);
  duration = pulseIn(echoPin_B, HIGH);
  B= duration*0.034/2;
  duration =0;
}
void sensorC()
{
  digitalWrite(trigPin_C, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin_C, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_C, LOW);
  duration = pulseIn(echoPin_C, HIGH);
  C= duration*0.034/2;
  duration =0;
}
void sensorD()
{
  digitalWrite(trigPin_D, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin_D, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_D, LOW);
  duration = pulseIn(echoPin_D, HIGH);
  D= duration*0.034/2;
  duration =0;
}
void sensorE()
{
  digitalWrite(trigPin_E, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin_E, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_E, LOW);
  duration = pulseIn(echoPin_E, HIGH);
  E= duration*0.034/2;
  duration =0;
}
void sensorF()
{
  digitalWrite(trigPin_F, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin_F, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_F, LOW);
  duration = pulseIn(echoPin_F, HIGH);
  F= duration*0.034/2;
  duration =0;
}
void kondisi1(){
  sensorA();
  sensorB();
  if((A <= t )&& (B<=t)){
    kondisiJalur1 = 3;
    }else if ((A <= t )&& (B>=t)){
    kondisiJalur1 = 2;
    }else if ((A >= t )&& (B>=t)){
    kondisiJalur1 = 1;
    }
}
void kondisi2(){
  sensorC();
  sensorD();
  if((C <= t )&& (D<=t)){
    kondisiJalur2 = 3;
    }else if ((C <= t )&& (D>=t)){
    kondisiJalur2 = 2;
    }else if ((C >= t )&& (D>=t)){
    kondisiJalur2 = 1;
    }
}
void kondisi3(){
  sensorE();
  sensorF();
  if((E <= t )&& (F<=t)){
    kondisiJalur3 = 3;
    }else if ((E <= t )&& (F>=t)){
    kondisiJalur3 = 2;
    }else if ((E >= t )&& (F>=t)){
    kondisiJalur3 = 1;
    }
}
void jalur1(){
  if(statusambulan!=0){
    if(statusambulan==1){
      Serial.println("Kendaraan Prioritas jalur 1");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kendaraan Priori");
      lcd.setCursor(0,1);
      lcd.print("Ada di Jalur 1");
      digitalWrite(LH1, HIGH);
      digitalWrite(LH2, LOW);
      digitalWrite(LH3, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(LM3, HIGH);
      digitalWrite(LM1, LOW);
      delay(ambulan);
      statusambulan=0;
      digitalWrite(LH1, LOW);
      digitalWrite(LK1, HIGH);
      digitalWrite(LK2, HIGH);
      digitalWrite(LM2, LOW);
      delay(kuningDelay);
      digitalWrite(LK1, LOW);
      digitalWrite(LK2, LOW);
      digitalWrite(LM1, LOW);
      kondisi2();
//      jalur2();
    }else if (statusambulan==2){
      Serial.println("Kendaraan Prioritas jalur 2");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kendaraan Priori");
      lcd.setCursor(0,1);
      lcd.print("Ada di Jalur 2"); 
      digitalWrite(LH2, HIGH);
      digitalWrite(LH1, LOW);
      digitalWrite(LH3, LOW);
      digitalWrite(LM1, HIGH);
      digitalWrite(LM3, HIGH);
      digitalWrite(LM2, LOW);
      delay(ambulan);
      statusambulan=0;
      digitalWrite(LH2, LOW);
      digitalWrite(LM1, LOW);
      digitalWrite(LK1, HIGH);
      digitalWrite(LK2, HIGH);
      delay(kuningDelay);
      digitalWrite(LK1, LOW);
      digitalWrite(LK2, LOW);
//      digitalWrite(LM3, LOW);
      kondisi1();
      jalur1();
     }else if (statusambulan==3){
      Serial.println("Kendaraan Prioritas jalur 3"); 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kendaraan Priori");
      lcd.setCursor(0,1);
      lcd.print("Ada di Jalur 3");
      digitalWrite(LH3, HIGH);
      digitalWrite(LH2, LOW);
      digitalWrite(LH1, LOW);
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, HIGH);
      digitalWrite(LM3, LOW);
      delay(ambulan);
      statusambulan=0;
      digitalWrite(LH3, LOW);
      digitalWrite(LM1, LOW);
      digitalWrite(LK3, HIGH);
      digitalWrite(LK1, HIGH);
      delay(kuningDelay);
      digitalWrite(LK1, LOW);
      digitalWrite(LK3, LOW);
      digitalWrite(LM3, LOW);
      kondisi1();
      jalur1();
     }
  }else  if(kondisiJalur1 == 3){
    Serial.println("Jalur 1 Padat");
    Serial.println("Durasi Lampu Hijau 1");
    Serial.println(hijauPadat);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Situasi Jalur 1 ");
      lcd.setCursor(0,1);
      lcd.print("       Padat");
    digitalWrite(LM2, HIGH);
    digitalWrite(LM3, HIGH);
    digitalWrite(LM1, LOW);
    digitalWrite(LH1, HIGH);
    digitalWrite(LH2, LOW);
    digitalWrite(LH3, LOW);
    delay(hijauPadat);
    }else if(kondisiJalur1 == 2){
    Serial.println("Jalur 1 Normal");
    Serial.println("Durasi Lampu Hijau 1");
    Serial.println(hijauNormal);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Situasi Jalur 1 ");
      lcd.setCursor(0,1);
      lcd.print("       Normal");
    digitalWrite(LM2, HIGH);
    digitalWrite(LM1, LOW);
    digitalWrite(LM3, HIGH);
    digitalWrite(LH1, HIGH);
    digitalWrite(LH2, LOW);
    digitalWrite(LH3, LOW);
    delay(hijauNormal);  
    }else if(kondisiJalur1 == 1){
    Serial.println("Jalur 1 Sepi");
    Serial.println("Durasi Lampu Hijau 1");
    Serial.println(hijauSepi);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Situasi Jalur 1 ");
      lcd.setCursor(0,1);
      lcd.print("       Sepi");
    digitalWrite(LM2, HIGH);
    digitalWrite(LM1, LOW);
    digitalWrite(LM3, HIGH);
    digitalWrite(LH1, HIGH);
    digitalWrite(LH2, LOW);
    digitalWrite(LH3, LOW);
    digitalWrite(LM1, LOW);
    delay(hijauSepi);  
  }
  digitalWrite(LH1, LOW);
  digitalWrite(LK1, HIGH);
  digitalWrite(LK2, HIGH);
  digitalWrite(LK3, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(LM1, LOW);
  delay(kuningDelay);
  digitalWrite(LK1, LOW);
  digitalWrite(LK2, LOW);
  digitalWrite(LM1, HIGH);
  kondisi2();
  }
  
void jalur2(){
  if(statusambulan!=0){
    if(statusambulan==1){
      Serial.println("Kendaraan Prioritas jalur 1");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kendaraan Priori");
      lcd.setCursor(0,1);
      lcd.print("Ada di Jalur 1");
      digitalWrite(LH1, HIGH);
      digitalWrite(LH2, LOW);
      digitalWrite(LH3, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(LM3, HIGH);
      digitalWrite(LM1, LOW);
      delay(ambulan);
      statusambulan=0;
      digitalWrite(LH1, LOW);
      digitalWrite(LK1, HIGH);
      digitalWrite(LK2, HIGH);
      digitalWrite(LM2, LOW);
      delay(kuningDelay);
      digitalWrite(LK1, LOW);
      digitalWrite(LK2, LOW);
      digitalWrite(LM1, LOW);
      kondisi2();
      jalur2();
    }else if (statusambulan==2){
      Serial.println("Kendaraan Prioritas jalur 2");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kendaraan Priori");
      lcd.setCursor(0,1);
      lcd.print("Ada di Jalur 2");
      digitalWrite(LH2, HIGH);
      digitalWrite(LH1, LOW);
      digitalWrite(LH3, LOW);
      digitalWrite(LH1, LOW);
      digitalWrite(LH3, LOW);
      digitalWrite(LM1, HIGH);
      digitalWrite(LM3, HIGH);
      digitalWrite(LM2, LOW);
      delay(ambulan);
      statusambulan=0;
      digitalWrite(LH2, LOW);
      digitalWrite(LK2, HIGH);
      digitalWrite(LK3, HIGH);
      digitalWrite(LM3, LOW);
      delay(kuningDelay);
      digitalWrite(LK2, LOW);
      digitalWrite(LK3, LOW);
      digitalWrite(LM2, LOW);
      kondisi3();
//      jalur3();
     }else if (statusambulan==3){
      Serial.println("Kendaraan Prioritas jalur 3");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kendaraan Priori");
      lcd.setCursor(0,1);
      lcd.print("Ada di Jalur 3");
      digitalWrite(LH3, HIGH);
      digitalWrite(LH2, LOW);
      digitalWrite(LH1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(LM1, HIGH);
      digitalWrite(LM3, LOW);
      delay(ambulan);
      statusambulan=0;
      digitalWrite(LH3, LOW);
      digitalWrite(LK1, LOW);
      digitalWrite(LK2, HIGH);
      digitalWrite(LK3, HIGH);
      digitalWrite(LM2, LOW);
      delay(kuningDelay);
      digitalWrite(LK3, LOW);
      digitalWrite(LK2, LOW);
      digitalWrite(LM1, LOW);
      kondisi2();
      jalur2();
     }
  }else if(kondisiJalur2 == 3){
    Serial.println("Jalur 2 Padat");
    Serial.println("Durasi Lampu Hijau 2");
    Serial.println(hijauPadat);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Situasi Jalur 2 ");
      lcd.setCursor(0,1);
      lcd.print("       Padat");
    digitalWrite(LM2, LOW);
    digitalWrite(LH2, HIGH);
    digitalWrite(LH1, LOW);
    digitalWrite(LH3, LOW);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM3, HIGH);
    delay(hijauPadat);
    }else if(kondisiJalur2 == 2){
    Serial.println("Jalur 2 Normal");
    Serial.println("Durasi Lampu Hijau 2");
    Serial.println(hijauNormal);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Situasi Jalur 2 ");
      lcd.setCursor(0,1);
      lcd.print("       Normal");
    digitalWrite(LM2, LOW);
    digitalWrite(LH2, HIGH);
    digitalWrite(LH1, LOW);
    digitalWrite(LH3, LOW);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM3, HIGH);
    delay(hijauNormal);  
    }else if(kondisiJalur2 == 1){
    Serial.println("Jalur 2 Sepi");
    Serial.println("Durasi Lampu Hijau 2");
    Serial.println(hijauSepi);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Situasi Jalur 2 ");
      lcd.setCursor(0,1);
      lcd.print("       Sepi");
    digitalWrite(LM2, LOW);
    digitalWrite(LH2, HIGH);
    digitalWrite(LH1, LOW);
    digitalWrite(LH3, LOW);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM3, HIGH);
    delay(hijauSepi);  
  }
  digitalWrite(LH2, LOW);
  digitalWrite(LK2, HIGH);
  digitalWrite(LK3, HIGH);
  digitalWrite(LM3, LOW);
  digitalWrite(LM2, LOW);
  delay(kuningDelay);
  kondisi3();
  digitalWrite(LK2, LOW);
  digitalWrite(LK3, LOW);
  digitalWrite(LM2, HIGH);
  }
void jalur3(){
  if(statusambulan!=0){
    if(statusambulan==1){
      Serial.println("Kendaraan Prioritas jalur 1");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kendaraan Priori");
      lcd.setCursor(0,1);
      lcd.print("Ada di Jalur 1"); 
      digitalWrite(LH1, HIGH);
      digitalWrite(LH2, LOW);
      digitalWrite(LH3, LOW);
      digitalWrite(LM3, HIGH);
      digitalWrite(LM2, HIGH);
      digitalWrite(LM1, LOW);
      delay(ambulan);
      statusambulan=0;
      digitalWrite(LH1, LOW);
      digitalWrite(LK2, LOW);
      digitalWrite(LK3, HIGH);
      digitalWrite(LK1, HIGH);
      digitalWrite(LM3, LOW);
      digitalWrite(LM1, LOW);
      delay(kuningDelay);
      digitalWrite(LK2, LOW);
      digitalWrite(LK1, LOW);
      digitalWrite(LK3, LOW);
      digitalWrite(LM2, LOW);
      kondisi3();
      jalur3();
    }else if (statusambulan==2){
      Serial.println("Kendaraan Prioritas jalur 2");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kendaraan Priori");
      lcd.setCursor(0,1);
      lcd.print("Ada di Jalur 2"); 
      digitalWrite(LH2, HIGH);
      digitalWrite(LH1, LOW);
      digitalWrite(LH3, LOW);
      digitalWrite(LM1, HIGH);
      digitalWrite(LM3, HIGH);
      digitalWrite(LM2, LOW);
      delay(ambulan);
      statusambulan=0;
      digitalWrite(LH2, LOW);
      digitalWrite(LK2, HIGH);
      digitalWrite(LK3, HIGH);
      digitalWrite(LM3, LOW);
      delay(kuningDelay);
      digitalWrite(LK2, LOW);
      digitalWrite(LK3, LOW);
      digitalWrite(LM2, LOW);
      kondisi3();
      jalur3();
     }else if (statusambulan==3){
      Serial.println("Kendaraan Prioritas jalur 3");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kendaraan Priori");
      lcd.setCursor(0,1);
      lcd.print("Ada di Jalur 3"); 
      digitalWrite(LH3, HIGH);
      digitalWrite(LH2, LOW);
      digitalWrite(LH1, LOW);
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, HIGH);
      delay(ambulan);
      statusambulan=0;
      digitalWrite(LH3, LOW);
      digitalWrite(LM1, LOW);
      digitalWrite(LK3, HIGH);
      digitalWrite(LK1, HIGH);
      delay(kuningDelay);
      digitalWrite(LK1, LOW);
      digitalWrite(LK3, LOW);
      digitalWrite(LM3, LOW);
     } 
  }else if(kondisiJalur3 == 3){
    Serial.println("Jalur 3 Padat");
    Serial.println("Durasi Lampu Hijau 3");
    Serial.println(hijauPadat);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Situasi Jalur 3 ");
      lcd.setCursor(0,1);
      lcd.print("       Padat");
    digitalWrite(LM3, LOW);
    digitalWrite(LH3, HIGH);
    digitalWrite(LH1, LOW);
    digitalWrite(LH2, LOW);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    delay(hijauPadat);
    }else if(kondisiJalur3 == 2){
    Serial.println("Jalur 3 Normal");
    Serial.println("Durasi Lampu Hijau 3");
    Serial.println(hijauNormal);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Situasi Jalur 3 ");
      lcd.setCursor(0,1);
      lcd.print("       Normal");
    digitalWrite(LM3, LOW);
    digitalWrite(LH3, HIGH);
    digitalWrite(LH1, LOW);
    digitalWrite(LH2, LOW);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    delay(hijauNormal);  
    }else if(kondisiJalur3 == 1){
    Serial.println("Jalur 3 Sepi");
    Serial.println("Durasi Lampu Hijau 3");
    Serial.println(hijauSepi);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Situasi Jalur 3 ");
      lcd.setCursor(0,1);
      lcd.print("       Sepi");
    digitalWrite(LM3, LOW);
    digitalWrite(LH3, HIGH);
    digitalWrite(LH1, LOW);
    digitalWrite(LH2, LOW);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    delay(hijauSepi);  
  }
  digitalWrite(LH3, LOW);
  digitalWrite(LM1, LOW);
  digitalWrite(LK3, HIGH);
  digitalWrite(LK1, HIGH);
  digitalWrite(LM3, LOW);
  delay(kuningDelay);
  digitalWrite(LK1, LOW);
  digitalWrite(LK3, LOW);
  digitalWrite(LM3, HIGH);
  }
