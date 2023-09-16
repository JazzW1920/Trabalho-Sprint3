// Aqui estão os códigos que utilizamos no nosso projeto

// Código utilizado no arduino 

#include <ArduinoJson.h>
const int TAMANHO = 50;  
#include "DHT.h"
#define DHTPIN  A3  
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); 
 

void setup() 
{
  //inicializa o sensor
  dht.begin();

  //inicializa o serial
  Serial.begin(9600);
}

void loop() 
{
  StaticJsonDocument<TAMANHO> json; 

    
  float temp = dht.readTemperature();
  float umi = dht.readHumidity();

  json["temperatura"] = temp;
  json["umidade"] = umi;

  serializeJson(json, Serial);
  Serial.println();

  delay(2000);
}

// Código utilizado para criar uma variável no node-red

var msg = {
    payload: {
        "variable": "umidade",
        "unit": "%",
        "value": msg.payload.umidade
    }
};

return msg;
