#include "CurieTimerOne.h"
#include "CurieIMU.h"

float ax,ay,az;
float gx,gy,gz;
float x;
int i = 0;
const int pin = A1;
unsigned long t;
int userInput;
volatile boolean flag;
int n_samples = 5000;


void myISR(){
  if (userInput == 'A'){
    CurieIMU.readAccelerometerScaled(ax,ay,az);
  }
  else if (userInput == 'G'){
    CurieIMU.readGyroScaled(gx, gy, gz);
  }
  flag = true;
}



void setup(){
  Serial.begin(115200);
  while(!Serial){};
  CurieIMU.begin();
  Serial.println("Initializing IMU device... \n");
  
  CurieIMU.setAccelerometerRange(2);
  CurieIMU.setGyroRange(250);

  Serial.println("Board ready!");
  Serial.println("Which sensor would you like to sample?");
  Serial.println("\t A: Accelerometer, G: Gyroscope");

  while(!Serial.available()){}
  userInput = Serial.read();
  
  CurieTimerOne.start(50000, myISR);
  flag = false;
}



void loop(){
  if (flag && i < n_samples + 1){
    i++;
  
    if (userInput == 'A'){
      float sax = sq((long)ax);
      float say = sq((long)ay);
      float saz = sq((long)az);
      Serial.println(sqrt(sax+say+saz));
      delay(1);
    }
    
    else if (userInput == 'G'){
      float sgx = sq((long)gx);
      float sgy = sq((long)gy);
      float sgz = sq((long)gz);
      Serial.println(sqrt(sgx+sgy+sgz));
      delay(1);
    }
    
  flag = false;
  }
}
