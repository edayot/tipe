

#include "Arduino.h"

long t = 0;
bool c=true;

void setup() {
  Serial.begin(2000000);
  Serial.print("Start");
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  Serial.print("\n");
  Serial.print("\n");
  digitalWrite(13,LOW);
  Serial.print("time_(μs) raw_current \n");
}

void loop() {
  float m=micros();
  
  
  float value=analogRead(A0);
  Serial.print(m);
  Serial.print(" ");
  Serial.print(value-512);
  Serial.print("\n");
  
  bool Bouton=digitalRead(12);
  if (Bouton == 1)
  {
    t=micros();
    c=true;
  }
  
  if (1000000<m-t and m-t<3000000)
  {
    digitalWrite(13,HIGH);
    
    }
  else if (m-t>4000000 and c){
    Serial.print("END");
    Serial.print("\n");
    digitalWrite(13,LOW);
    c=false;
    }
  else
  {
    digitalWrite(13,LOW);
    
    }
  
  // put your main code here, to run repeatedly:

}
