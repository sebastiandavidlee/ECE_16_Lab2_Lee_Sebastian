#include "CurieIMU.h"
#include "CurieTimerOne.h"

String oldString, newString;

void obj4isr(){
  float ax, ay, az;
  CurieIMU.readAccelerometerScaled(ax, ay, az);
  
  if (ax < -0.76 && ax > -1.2){
  newString = "Portrait 1";
  }
  else if (ax > 0.66 && ax < 1){
  newString = "Portrait 2";
  }
  else if (ay > 0.67 && ay < 1.1){
  newString = "Landscape 1";
  }
  else if (ay < -0.67 && ay > -1.1){
  newString = "Landscape 2";
  }
}

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Initializing IMU device...");
  
  CurieIMU.begin();
  CurieIMU.setAccelerometerRange(2);
  CurieIMU.setGyroRange(250);
  
  CurieTimerOne.start(10000, obj4isr);
  oldString = "Portrait 1";
}

void loop() {
  if (newString != oldString){
    Serial.println(newString);
    oldString = newString;
  }
}

