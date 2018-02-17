#include "CurieTimerOne.h"

int analogPin = A0;
int x,t;
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
    Serial.print(t);
    Serial.print('\t');
    Serial.println(x);
    flag = false;
  }
}
