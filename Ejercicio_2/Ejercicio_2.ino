/*
Grupo 3
Cordoni
Lichtenstein
López
*/

//Ejercicio 2
#include <DHT.h>
#include <U8g2lib.h>

#define DATA_DHT 23    // pin del dht
#define DHTTYPE DHT11  // tipo de DHT

DHT dht(DATA_DHT, DHTTYPE);
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void printBMP_OLED(void );

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperatura = dht.readTemperature();

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  delay(2000);  // 2 segundos mínimo
}