#define ses_sensoru 3
#define mum 4
int alkis = 0;
long algilama_araligi_baslangic = 0;
long algilama_araligi = 0;

void setup() {
pinMode(mum,OUTPUT);
pinMode(ses_sensoru,INPUT);
Serial.begin(9600);
}

void loop() {
int sensor_durumu = digitalRead(ses_sensoru);

 if (sensor_durumu == 0){
    if (alkis == 0){
      algilama_araligi_baslangic = algilama_araligi = millis();
      alkis++;
      Serial.println("hazir");
    }
    else if (alkis > 0 && millis()-algilama_araligi >= 50){
      algilama_araligi = millis();
      alkis++;
      Serial.println("alkis");
      digitalWrite(mum,HIGH);
      delay(10000);
      digitalWrite(mum,LOW);
    }
  }
}

