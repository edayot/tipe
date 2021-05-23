

#include "Arduino.h"

long t = 0;
bool c=true;
int i=0;

bool en_marche=false;
bool stop_=false;

void setup() {
  Serial.begin(2000000);
  Serial.print("Start");
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  Serial.print("\n");
  Serial.print("\n");
  digitalWrite(13,LOW);
  Serial.print("time_(μs) raw_current raw_low_voltage\n");
}

void loop() {
  
  long m=micros();
  
  
  int current=analogRead(A0);
  int voltage=analogRead(A1);
  Serial.print(m);
  Serial.print(" ");
  Serial.print(current);
  Serial.print(" ");
  Serial.print(voltage);
  Serial.print("\n");
  /*
  bool Bouton=digitalRead(12);
  if (Bouton == 1)
  {
    t=micros();
    c=true;
  }
  */
  
  if (not en_marche)
  {
    if (not stop_ and 1000000<m)
    {
      digitalWrite(13,HIGH);
      en_marche=true;
    
      
      }
    if (m>4000000 and c){
      Serial.print("END");
      Serial.print("\n");
      c=false;
    }
    
    }
    
  if (m>3000000)
  {
    digitalWrite(13,LOW);
    en_marche=false;
    stop_=true;
    
    }
  

  
  // put your main code here, to run repeatedly:

}
