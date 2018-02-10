#include "CurieTimerOne.h"

int i = 0;
int x = 0;
unsigned long t1, t2, t;

void obj2isr(){
  x = analogRead(A1);
  flag = true;
}

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Sample Number    Sensor Reading    Time Difference");
  CurieTimerOne.start(10000, obj2isr);
  flag = false;
}

void loop(){
  if (flag){
    delayMicroseconds(1);
    t1 = t2;
    t2 = micros();
    
    i++;
    t = t2 - t1;
    Serial.print("      ");
    Serial.print(i);
    Serial.print("               ");
    Serial.print(x);
    Serial.print("             ");
    Serial.println(t);
    flag = false;
  }
}



