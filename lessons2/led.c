/*
 * By Horizon Chaser
 * 2020/06/16
 * Opensouce HardWare 2nd Lesson Homework
*/

void setup() {
  for(int i = 2;i <= 8;i++)
  pinMode(i, OUTPUT);
}

void loop() {
   for(int i = 1;i <= 8;i++){
    digitalWrite(i, LOW);
    delay(100);
    digitalWrite(i+1, HIGH);
    delay(100);
  }
  for(int i = 1;i <= 8;i++){
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i+1, LOW);
    delay(100);
  }
}