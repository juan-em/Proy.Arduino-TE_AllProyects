#include <IRremote.h>
#include <IRremoteInt.h>

//www.elegoo.com
//2016.12.9

#include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'


boolean a1 = true;
boolean a2 = false;
boolean estado = false;
int vel = 10;
int vel_res;







/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  switch(results.value)

  {
  case 0xFFA25D: Serial.println("POWER"); break;
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: Serial.println("VOL+"); break;
  case 0xFF22DD: Serial.println("FAST BACK");    break;
  case 0xFF02FD: Serial.println("PAUSE");    break;
  case 0xFFC23D: Serial.println("FAST FORWARD");   break;
  case 0xFFE01F: Serial.println("DOWN");    break;
  case 0xFFA857: Serial.println("VOL-");    break;
  case 0xFF906F: Serial.println("UP");    break;
  case 0xFF9867: Serial.println("EQ");    break;
  case 0xFFB04F: Serial.println("ST/REPT");    break;
  case 0xFF6897: Serial.println("0");    break;
  case 0xFF30CF: Serial.println("1");    break;
  case 0xFF18E7: Serial.println("2");    break;
  case 0xFF7A85: Serial.println("3");    break;
  case 0xFF10EF: Serial.println("4");    break;
  case 0xFF38C7: Serial.println("5");    break;
  case 0xFF5AA5: Serial.println("6");    break;
  case 0xFF42BD: Serial.println("7");    break;
  case 0xFF4AB5: Serial.println("8");    break;
  case 0xFF52AD: Serial.println("9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: 
    Serial.println(" other button   ");

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR
void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver

  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);

}/*--(end setup )---*/

void cambio(){
    digitalWrite(12, a1);
    digitalWrite(9, a2);
}
void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    if (results.value == 0xFF629D){
      Serial.println("subida de vel");
    delay(500);
    if (vel==100){
      vel = 10;
    }else{
      vel = vel + 10;
    }
  }
  if (estado==false){
    if(results.value == 0xFFA25D){
      Serial.println("power on");
      delay(500);
      analogWrite(10,map(vel,0,100,0,255));
      cambio();
      estado = !estado;
    }
    if(results.value == 0xFF02FD){
      delay(500);
      a1 = !a1;
      a2 = !a2;
      Serial.println("llegue");
    }
  }
  else if (estado == true){
    if(results.value == 0xFFA25D){
      Serial.println("power off");
      delay(500);
      vel_res = vel;
      vel = 0;
      analogWrite(10,map(vel,0,100,0,255));
      estado = !estado;
      vel = vel_res;
    }
  }
    irrecv.resume(); // receive the next value
  }  
}/* --(end main loop )-- */
