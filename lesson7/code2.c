#include <MsTimer2.h>
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define pinInterrupt 2

 
volatile byte tock = 0;

void displayAdd() {
  digitalWrite(IN1,tock&0x1);
  digitalWrite(IN2,(tock>>1)&0x1);
  digitalWrite(IN3,(tock>>2)&0x1);
  digitalWrite(IN4,(tock>>3)&0x1);
  tock++;
  if(tock >= 10)
    tock = 0;
  Serial.println(tock);
}

void setToZero() {
  tock = 0;
}
 
void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  MsTimer2::set(1000, displayAdd); 
  MsTimer2::start();
  attachInterrupt(digitalPinToInterrupt(pinInterrupt),
                  setToZero, CHANGE);
}
 
void loop() {}