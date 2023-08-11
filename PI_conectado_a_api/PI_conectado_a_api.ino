/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include <ESP8266WiFi.h>;

#include "WiFi.h"
/*#include "HTTPClient.h"*/
const char* ssid="POCO F3";
const char* pass="naujem1234";

void setup()


{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.begin(ssid, pass);
    delay(2000);

    Serial.print("se está conectando a la red wifi denominada ");
    Serial.println(ssid);

    while(WiFi.status()!=WL_CONNECTED){
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("Wi fi conncected");
    Serial.println("ip address");
    Serial.println(WiFi.localIP());

    
}

void loop()
{/*
    String date = "2022-11-05";
    if (WiFi.status()==WL_CONNECTED){
      HTTPClient http;
      String datos_a_enviar = "user_id=6&porcentaje=32.87&reg_date="+date;
      
      http.begin("http://192.168.1.11:8000/api/rplastico/");
      http.addHeader("Content-Type","application/x-www-form-urlencoded");
      
      int httpCode = http.POST(datos_a_enviar);

      if(httpCode>0){
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);        
      }
      else{
        Serial.println("Error on HTTP request");
      }
      http.end();
    }
    delay(20000);*/
}
