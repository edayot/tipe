
#include "Arduino.h"
bool c = true;
long T =micros();
long T2 =micros();

void setup() 
{
  
  Serial.begin(9600);
  Serial.print("Start");
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  Serial.print(millis());
  Serial.print("\n");
  Serial.print("\n");
  // put your setup code here, to run once:

}

void loop() 
{
  //état de pin12
  
  float f = 1;
  long d = millis()-T;
  if (d>1000/f) // pour avoir le résultat en Hz
  {
    T =millis();
    Serial.print(analogRead(A1));
    Serial.print(" ");
    Serial.print(millis());
    Serial.print(" ");
    Serial.print(d);
    Serial.print("\n");
    }
 
  
  float f2 = 0.3;
  d = millis()-T2;
  if (d>1000/f2) // pour avoir le résultat en Hz
  {
    T2 =millis();
    if (c)
    {
      c=false;
      digitalWrite(13,HIGH);
      }
    else
    {
      c=true;
      digitalWrite(13,LOW);
      }
    }
  // put your main code here, to run repeatedly:

}
