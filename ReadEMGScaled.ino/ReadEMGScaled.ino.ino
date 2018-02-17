#include "CurieTimerOne.h"

int analogPin = A0;
int x,i,j,t;
volatile boolean flag = false;

void emgISR(){
  x = analogRead(analogPin);
  flag = true;
}

void setup() {
  Serial.begin(115200);
  while(!Serial){};
  CurieTimerOne.start(5000,emgISR);
  float t_total = 5;
  j = t_total*200;
  i = 0;
}

void loop() {
  if (flag && i < j){
    t = micros();
    Serial.print(t);
    Serial.print('\t');
    Serial.println(x);
    flag = false;
    i++;
  }
}
