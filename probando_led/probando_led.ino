#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
const char* ssid = "POCO F3";
const char* password =  "naujem1234";

//Compartimentos
//papel
int d8 = 12;
int td7 = 13;
int ed6 = 9;
//plastico
int d2 = 4;
int td1 = 5;
int ed0 = 16;
//vidrio
int d5 = 14;
int td4 = 2;
int ed3 = 0;



//Ultrasonido
const int t1 = 14;
const int e1 = 12;



void setup() {
  Serial.begin(115200);
  //Conexión wifi
  WiFi.begin(ssid, password);
  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(500);
    Serial.print(".");
  }
  Serial.print("Conectado con éxito, mi IP es: ");
  Serial.println(WiFi.localIP());
  
  //Infrarrojo
  pinMode(d8,INPUT);
  pinMode(d2,INPUT);
  pinMode(d5,INPUT);

  //ultrasonido
  pinMode(td7, OUTPUT); 
  pinMode(ed6, INPUT);  
  digitalWrite(td7, LOW);

  pinMode(td1, OUTPUT); 
  pinMode(ed0, INPUT);  
  digitalWrite(td1, LOW);

  pinMode(td4, OUTPUT); 
  pinMode(ed3, INPUT);  
  digitalWrite(td4, LOW);
  

}

void loop() {
    
  if (digitalRead(d8)==0){
    delay(2000);
    long t; 
    long d; 
    long r;
    digitalWrite(td7, HIGH);
    delayMicroseconds(10);          
    digitalWrite(td7, LOW);
    t = pulseIn(ed6, HIGH); 
    d = t/59;
    Serial.println("papel");
    r = 100-(100*d)/22;
    //envio("http://192.168.63.234:8000/api/rpapel",getTime(),d);
    envio("http://192.168.63.234:8000/api/rpapel",getTime(),r);
    envio2("http://192.168.63.234:8000/api/topten",getTime(),"papel");
  };
  if (digitalRead(d2)==0){
    delay(2000);
    long t; 
    long d;
    long r;
    digitalWrite(td1, HIGH);
    delayMicroseconds(10);          
    digitalWrite(td1, LOW);
    t = pulseIn(ed0, HIGH); 
    d = t/59;
    Serial.println("plastico");
    r = 100-(100*d)/22;
    //envio("http://192.168.63.234:8000/api/rplastico",getTime(),d);
    envio("http://192.168.63.234:8000/api/rplastico",getTime(),r);
    envio2("http://192.168.63.234:8000/api/topten",getTime(),"plastico");
    
  };
  if (digitalRead(d5)==0){
    delay(2000);
    long t; 
    long d; 
    long r;
    digitalWrite(td4, HIGH);
    delayMicroseconds(10);          
    digitalWrite(td4, LOW);
    t = pulseIn(ed3, HIGH); 
    d = t/59;
    Serial.println("vidrio");
    r = 100-(100*d)/22;
    //envio("http://192.168.63.234:8000/api/rvidrio",getTime(),d);
    envio("http://192.168.63.234:8000/api/rvidrio",getTime(),r);
    envio2("http://192.168.63.234:8000/api/topten",getTime(),"vidrio");
  };
}

String getTime(){
  WiFiClient client;
  HTTPClient http;
  String timeS ="";
  http.begin(client,"http://worldtimeapi.org/api/timezone/America/Lima");
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
    String payload = http.getString();
    int beginS = payload.indexOf("datetime");
    String a = payload.substring(beginS+11,beginS+21);
    //String b = payload.substring(beginS+22,beginS+37);
    //timeS = a + " " + b;
    timeS = a;
  }
  return timeS;
}

void envio(String url, String fecha, int porcentaje){
    WiFiClient client;
    HTTPClient http;
    String datos_a_enviar = "user_id=6&porcentaje="+String(porcentaje)+"&reg_date=" + fecha;
    http.begin(client,url);        //Indicamos el destino
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
    int codigo_respuesta = http.POST(datos_a_enviar);
    if(codigo_respuesta>0){
      Serial.println("Código HTTP ► " + String(codigo_respuesta));  
      if(codigo_respuesta == 200){
        String cuerpo_respuesta = http.getString();
        Serial.println("El servidor respondió ▼ ");
        Serial.println(cuerpo_respuesta);
      }
    }else{
     Serial.print("Error enviando POST, código: ");
     Serial.println(codigo_respuesta);
    }
}
void envio2(String url, String fecha, String tipo){
    WiFiClient client;
    HTTPClient http;
    String datos_a_enviar = "user_id=6&type="+tipo+"&reg_date=" + fecha;
    http.begin(client,url);        //Indicamos el destino
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
    int codigo_respuesta = http.POST(datos_a_enviar);
    if(codigo_respuesta>0){
      Serial.println("Código HTTP ► " + String(codigo_respuesta));  
      if(codigo_respuesta == 200){
        String cuerpo_respuesta = http.getString();
        Serial.println("El servidor respondió ▼ ");
        Serial.println(cuerpo_respuesta);
      }
    }else{
     Serial.print("Error enviando POST, código: ");
     Serial.println(codigo_respuesta);
    }
}
