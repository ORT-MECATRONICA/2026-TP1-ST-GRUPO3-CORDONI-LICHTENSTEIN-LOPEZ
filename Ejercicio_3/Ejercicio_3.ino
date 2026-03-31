/*
Grupo 3
Cordoni
Lichtenstein
López
*/

//Ejercicio 3
#include <DHT.h>
#include <U8g2lib.h>

#define DATA_DHT 23    // pin del dht
#define DHTTYPE DHT11  // tipo de DHT

DHT dht(DATA_DHT, DHTTYPE);
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

#define UMBRAL 28
#define LED_1 25

void setup() {
  Serial.begin(9600);
  dht.begin();
  u8g2.begin();

  pinMode(LED_1, OUTPUT);
}

void loop() {
  float temperatura = dht.readTemperature();
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB14_tr);
  char stringtemp[10];
  sprintf(stringtemp, "%.1f C", temperatura);
  u8g2.drawStr(30, 50, stringtemp);
  u8g2.sendBuffer();

  if (temperatura >= UMBRAL){
    Serial.digitalWrite(LED_1, HIGH);
  } else {
    Serial.digitalWrite(LED_1, LOW);
  }
  
  delay(2000);  // 2 segundos mínimo
}