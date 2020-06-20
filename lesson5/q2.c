/*
 * HorizonChaser 2020-06-20
*/


#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  
  Serial.begin(9600);
}

void loop()
{
  byte in = 0x00;

  if(Serial.available()){
    Serial.println("4!");
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
    
    
    in = Serial.read() - '0';
    digitalWrite(S1, LOW);
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    digitalWrite(S4, HIGH);
    digitalWrite(2,in&0x1);
    digitalWrite(3,(in>>1)&0x1);
    digitalWrite(4,(in>>2)&0x1);
    digitalWrite(5,(in>>3)&0x1);
    delay(100);

    in = Serial.read() - '0';
    digitalWrite(S1, HIGH);
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    digitalWrite(S4, HIGH);
    digitalWrite(2,in&0x1);
    digitalWrite(3,(in>>1)&0x1);
    digitalWrite(4,(in>>2)&0x1);
    digitalWrite(5,(in>>3)&0x1);
    delay(100);

    in = Serial.read() - '0';
    digitalWrite(S1, HIGH);
    digitalWrite(S2, HIGH);
    digitalWrite(S3, LOW);
    digitalWrite(S4, HIGH);
    digitalWrite(2,in&0x1);
    digitalWrite(3,(in>>1)&0x1);
    digitalWrite(4,(in>>2)&0x1);
    digitalWrite(5,(in>>3)&0x1);
    delay(100);

    in = Serial.read() - '0';
    digitalWrite(S1, HIGH);
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    digitalWrite(S4, LOW);
    digitalWrite(2,in&0x1);
    digitalWrite(3,(in>>1)&0x1);
    digitalWrite(4,(in>>2)&0x1);
    digitalWrite(5,(in>>3)&0x1);
    delay(100);

  }
}


