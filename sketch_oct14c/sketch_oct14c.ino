bool on_off = true;
const int pulsador1 = 2;
const int pulsador2 = 3;
const int pulsador3 = 4;

void setup() {
  // put your setup code here, to run once:
      pinMode(7,INPUT);
      pinMode(8,INPUT);
      pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (digitalRead(pulsador1)==0 && digitalRead(pulsador2)==0){
    
     delay(1000);
     digitalWrite(9,false);
    digitalWrite(7,false);
    digitalWrite(8,true);

    digitalWrite(11,false);
    digitalWrite(13,false);
    digitalWrite(12,false);  

   
    }
    if (digitalRead(pulsador1)==0 && digitalRead(pulsador2)){
    digitalWrite(9,true);
    digitalWrite(7,false);
    digitalWrite(8,true);

    digitalWrite(11,true);
    digitalWrite(13,false);
    digitalWrite(12,true);  
    }
    if (digitalRead(pulsador2)==0 && digitalRead(pulsador1)){
    digitalWrite(9,true);
    digitalWrite(7,true);
    digitalWrite(8,false);

    digitalWrite(11,true);
    digitalWrite(13,true);
    digitalWrite(12,false);  
    }
    
}
