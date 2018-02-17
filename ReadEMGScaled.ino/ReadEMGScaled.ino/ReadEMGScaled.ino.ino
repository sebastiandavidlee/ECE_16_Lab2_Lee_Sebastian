#include "CurieTimerOne.h"

int analogPin = A0;
float x,t,V;
volatile boolean flag = false;

void emgISR(){
  x = analogRead(analogPin);
  flag = true;
}

void setup() {
  Serial.begin(115200);
  while(!Serial){};
  CurieTimerOne.start(5000,emgISR);
}

void loop() {
  if (flag){
    t = micros();
    V = (3.3*x/1024.0-1.5)/3.6;
    Serial.print(t);
    Serial.print('\t');
    Serial.println(V,4);
    flag = false;
  }
}
