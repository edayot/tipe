

#include "Arduino.h"

long t = -3000;

void setup() {
  Serial.begin(9600);
  Serial.print("Start");
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  Serial.print("\n");
  Serial.print("\n");
  digitalWrite(13,LOW);

}

void loop() {
  bool Bouton=digitalRead(12);
  
  
  if (Bouton == 1)
  {
    t=millis();
  }
  long m=millis();
  if (1000<m-t and m-t<3000)
  {
    digitalWrite(13,HIGH);
    
    }
  else
  {
    digitalWrite(13,LOW);
    
    }
  long value=analogRead(A0);
  Serial.print(value);
  Serial.print("\n");
  delay(100);
  // put your main code here, to run repeatedly:

}
