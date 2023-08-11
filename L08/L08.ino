const int controlVelocidadAbajo = 9;
const int giroDerechaAbajo = 8;
const int giroIzquierdaAbajo = 7;

const int controlVelocidadArriba = 11;
const int giroDerechaArriba = 13;
const int giroIzquierdaArriba = 12;

bool derecha = false, izquierda = false;
int velocidad = 0;
int vel;

const int pulsador1 = 2;
const int pulsador2 = 3;
const int pulsador3 = 4;

int contador = 0;


void setup() {
      Serial.begin(9600);
  
      pinMode(controlVelocidadAbajo,OUTPUT);
      pinMode(giroDerechaAbajo,OUTPUT);
      pinMode(giroIzquierdaAbajo,OUTPUT);
  
      pinMode(controlVelocidadArriba,OUTPUT);
      pinMode(giroDerechaArriba,OUTPUT);
      pinMode(giroIzquierdaArriba,OUTPUT);
      
      pinMode(pulsador1,INPUT);
      pinMode(pulsador2,INPUT);
      pinMode(pulsador3,INPUT);
}

void loop() {

  if (digitalRead(pulsador1)==0){
    derecha = true;
    izquierda = false;
    vel = velocidad;
    controladorGiroVelocidadAbajo(derecha,izquierda,vel);
    controladorGiroVelocidadArriba(derecha,izquierda,vel);
  }
  if (digitalRead(pulsador2)==0){
    derecha = false;
    izquierda = true;
    vel = velocidad;
    controladorGiroVelocidadAbajo(derecha,izquierda,vel);
    controladorGiroVelocidadArriba(derecha,izquierda,vel);
  }
  if (digitalRead(pulsador1)==0 && digitalRead(pulsador2)==0){
    derecha = false;
    izquierda = false;
    vel = velocidad;
    controladorGiroVelocidadAbajo(derecha,izquierda,vel);
    controladorGiroVelocidadArriba(derecha,izquierda,vel);
  }
  if (digitalRead(pulsador3)==0){
    if (velocidad == 10) {
      velocidad = 1;
    }
    velocidad += 1;
    Serial.print(velocidad);
    delay(500);
  }
}


void controladorGiroVelocidadAbajo(bool der, bool izq, int vel){
  digitalWrite(giroDerechaAbajo,der);
  digitalWrite(giroIzquierdaAbajo,izq);
  analogWrite(controlVelocidadAbajo,map(vel,0,100,0,255));
}

void controladorGiroVelocidadArriba(bool der, bool izq, int vel){
  digitalWrite(giroDerechaArriba,der);
  digitalWrite(giroIzquierdaArriba,izq);
  analogWrite(controlVelocidadArriba,map(vel,0,100,0,255));
}
