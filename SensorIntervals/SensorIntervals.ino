#include "CurieIMU.h"

int i = 0;
int x = 0;
unsigned long t1, t2;

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Initializing IMU device...");
  CurieIMU.begin();
  CurieIMU.setAccelerometerRange(2);
  CurieIMU.setGyroRange(250);
}

void loop() {

  if 
  
  i++;
  // accel
  float ax, ay, az;
  t1 = micros();
  CurieIMU.readAccelerometerScaled(ax, ay, az);
  t2 = micros();
  
  Serial.println("Microseconds for Accel read");
  Serial.println(t2-t1);

  
  // empty analog pin
  t1 = micros();
  x = analogRead(A1);
  t2 = micros();
  
  Serial.println("Microseconds for analogRead");
  Serial.println(t2-t1);


  // gyro
  float gx, gy, gz;
  t1 = micros();
  CurieIMU.readGyroScaled(gx, gy, gz);
  t2 = micros();
  
  Serial.println("Microseconds for Gyro read");
  Serial.println(t2-t1);

}

