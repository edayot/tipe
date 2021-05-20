

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
  if (1000<millis()-t<3000)
  {
    digitalWrite(13,HIGH);
    }
  else
  {
    digitalWrite(13,LOW);
    }
  // put your main code here, to run repeatedly:

}