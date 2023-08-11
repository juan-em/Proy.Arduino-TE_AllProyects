const int controlVelocidadM1 = 9;
const int giroDerechaM1 = 8;
const int giroIzquierdaM1 = 7;
int velocidadM1=100;
//Motor 2
const int controlVelocidadM2 = 11;
const int giroDerechaM2 = 12;
const int giroIzquierdaM2 = 13;
int velocidadM2=100;
//Pulsadores
const int p1 = 2;
const int p2 = 3;
const int p3 = 4;

void setup() {
      pinMode(controlVelocidadM1,OUTPUT);
      pinMode(giroDerechaM1,OUTPUT);
      pinMode(giroIzquierdaM1,OUTPUT);

      pinMode(controlVelocidadM2,OUTPUT);
      pinMode(giroDerechaM2,OUTPUT);
      pinMode(giroIzquierdaM2,OUTPUT);

      pinMode(p1,INPUT);
      pinMode(p2,INPUT);
      pinMode(p3,INPUT);
}

void loop() {
  ///////
  if(digitalRead(p1)==0 && digitalRead(p2)==0){
    delay(1000);
    controladorGiroVelocidadM1(false,false,velocidadM1);
    controladorGiroVelocidadM2(false,false,velocidadM1);
  }
  
  
  if(digitalRead(p1)==0){
    controladorGiroVelocidadM1(true,false,velocidadM1);
    controladorGiroVelocidadM2(true,false,velocidadM1);
  }
  if(digitalRead(p2)==0){
    controladorGiroVelocidadM1(false,true,velocidadM1);
    controladorGiroVelocidadM2(false,true,velocidadM2);
  }
  if(digitalRead(p3)==0){
    if (velocidad == 10) {
      velocidad = 1;
    }
    velocidad += 1;
    Serial.print(velocidad);
    delay(  );
  }
}

void controladorGiroVelocidadM1(bool der, bool izq, int vel){
  digitalWrite(giroDerechaM1,der);
  digitalWrite(giroIzquierdaM1,izq);
  analogWrite(controlVelocidadM1,map(vel,0,100,0,255));
}
void controladorGiroVelocidadM2(bool der, bool izq, int vel){
  digitalWrite(giroDerechaM2,der);
  digitalWrite(giroIzquierdaM2,izq);
  analogWrite(controlVelocidadM2,map(vel,0,100,0,255));
}
