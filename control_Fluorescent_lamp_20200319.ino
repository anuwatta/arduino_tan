#include <IRremote.h>

const int RECV_PIN = 7;

const int relay_1 = 4; // control light 1st floor
const int relay_2 = 5; // control light 2nd floor
const int relay_3 = 6; // control light 3rd floor

IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  
  pinMode(relay_1,OUTPUT);
  pinMode(relay_2,OUTPUT);
  pinMode(relay_3,OUTPUT);

  digitalWrite(relay_1,LOW);
  digitalWrite(relay_2,LOW);
  digitalWrite(relay_3,LOW);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xFFA25D:
          Serial.println("1");
          digitalWrite(relay_1,HIGH);
          break;
          case 0xFF629D:
          Serial.println("2");
          digitalWrite(relay_2,HIGH);
          break;
          case 0xFFE21D:
          Serial.println("3");
          digitalWrite(relay_3,HIGH);
          break;
          case 0xFF22DD:
          Serial.println("4");
          digitalWrite(relay_1,LOW);
          break;
          case 0xFF02FD:
          Serial.println("5");
          digitalWrite(relay_2,LOW);
          break ;  
          case 0xFFC23D:
          Serial.println("6");
          digitalWrite(relay_3,LOW);
          break ;               
          case 0xFFE01F:
          Serial.println("7");
          break ;  
          case 0xFFA857:
          Serial.println("8");
          break ;  
          case 0xFF906F:
          Serial.println("9");
          digitalWrite(relay_1,HIGH);
          digitalWrite(relay_2,HIGH);
          digitalWrite(relay_3,HIGH);
          break ;  
          case 0xFF6897:
          Serial.println("??");
          break ;  
          case 0xFF9867:
          Serial.println("0");
          digitalWrite(relay_1,LOW);
          digitalWrite(relay_2,LOW);
          digitalWrite(relay_3,LOW);
          break ;
          case 0xFFB04F:
          Serial.println("200+");
          break ;
          case 0xFF30CF:
          Serial.println("1");
          break ;
          case 0xFF18E7:
          Serial.println("2");
          break ;
          case 0xFF7A85:
          Serial.println("3");
          break ;
          case 0xFF10EF:
          Serial.println("4");
          break ;
          case 0xFF38C7:
          Serial.println("5");
          break ;
          case 0xFF5AA5:
          Serial.println("6");
          break ;
          case 0xFF42BD:
          Serial.println("7");
          break ;
          case 0xFF4AB5:
          Serial.println("8");
          break ;
          case 0xFF52AD:
          Serial.println("9");
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
