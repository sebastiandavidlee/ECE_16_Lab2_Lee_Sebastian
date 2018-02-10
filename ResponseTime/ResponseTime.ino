#include "CurieTimerOne.h"
#include "CurieIMU.h"

String sensor;
int randomNumber, waitTime;
unsigned long t,t1,t2;
float ax,ay,az;
float sax,say,saz;
float gx,gy,gz;
float sgx,sgy,sgz;
float amagnitude,gmagnitude;
volatile boolean flag = false;

void accelISR(){
  CurieIMU.readAccelerometerScaled(ax,ay,az);
  flag = true;
}

void gyroISR(){
  CurieIMU.readGyroScaled(gx,gy,gz);
  flag = true;
}

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(115200);
  while(!Serial);

  CurieIMU.begin();
  CurieIMU.setAccelerometerRange(4);
  CurieIMU.setGyroRange(500); 
  
  randomSeed(analogRead(0));  
}

void loop() {
  randomNumber = random(1,11);
  waitTime = randomNumber*1000;

//  Serial.println("Hi, which sensor would you like to sample? ");
  while(!Serial.available());
  sensor = Serial.readString();

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);

  delay(waitTime);
  digitalWrite(LED_BUILTIN, HIGH);
  t1 = micros();

  if (sensor == "Accelerometer"){
    CurieTimerOne.start(10000,&accelISR);
    t2 = reactionTime(sensor);
    t = t2 - t1;
    Serial.println(t);
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if (sensor == "Gyroscope"){
    CurieTimerOne.start(10000,&gyroISR);
    t2 = reactionTime(sensor);
    t = t2 - t1;
    Serial.println(t);
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  CurieTimerOne.kill();
}

int reactionTime(String input){
  
  while (true){
    if (flag){
      if (input = "Accelerometer"){
        sax = sq((long)ax);
        say = sq((long)ay);
        saz = sq((long)az);
        amagnitude = (sqrt(sax+say+saz));
        flag = false;
          
        if (amagnitude > 2){
          return micros();
        }
      }
      if (input = "Gyroscope"){
        sgx = sq((long)gx);
        sgy = sq((long)gx);
        sgz = sq((long)gx);
        gmagnitude = (sqrt(sgx+sgy+sgz));
        flag = false;
          
        if (gmagnitude > 400){
          return micros();
        }
      }
    }
  }
}
  
