int i = 0;
int x = 0;
unsigned long t1, t2, t;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Sample Number    Sensor Reading    Time Difference");
}

void loop(){
  t1 = t2;
  t2 = micros();
  x = analogRead(A1);
  delayMicroseconds(6812);
  i++;
  t = t2 - t1;
  Serial.print("      ");
  Serial.print(i);
  Serial.print("               ");
  Serial.print(x);
  Serial.print("             ");
  Serial.println(t);
}

