/*
  Four-Wheel Drive System Simulator
  By HorizonChaser 2020/06/18
*/

/*
  Usage:
    F/f: Move Forward
    B/b: Move Backward
    S/s: Stop Immediately
    R/r: Turn Right
    L/l: Turn Left
    I/i: Increase Speed by 10%, MAX == 100%
    D/d: Decrease Speed by 10%, MIN == 10%

  GLHF with Arduino~
*/

float speedPercent = 50;
int motorRctrlA = 2, motorRctrlB = 3;
int motorLctrlA = 4, motorLctrlB = 5;
int pwmCtrlL = 11, pwmCtrlR = 10;
char cmd = ' ';
void setup()
{
  Serial.begin(9600);
  Serial.println("[FWD Sim] Initializating...");
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.println("[FWD Sim] Initialization Completed.");
}

void loop() {
  if (Serial.available() > 0)
  {
    cmd = Serial.read();
    analogWrite(pwmCtrlL, 255 * (speedPercent / 100));
    analogWrite(pwmCtrlR, 255 * (speedPercent / 100));
    switch (cmd) {

      case 'F':
      case 'f':
        digitalWrite(motorRctrlA, HIGH);
        digitalWrite(motorRctrlB, LOW);
        digitalWrite(motorLctrlA, HIGH);
        digitalWrite(motorLctrlB, LOW);
        Serial.println("[FWD Sim] Moving Forward");
        break;

      case 'B':
      case 'b':
        digitalWrite(motorRctrlB, HIGH);
        digitalWrite(motorRctrlA, LOW);
        digitalWrite(motorLctrlB, HIGH);
        digitalWrite(motorLctrlA, LOW);
        Serial.println("[FWD Sim] Moving Backward");
        break;

      case 'R':
      case 'r':
        digitalWrite(motorLctrlA, HIGH);
        digitalWrite(motorLctrlB, LOW);
        digitalWrite(motorRctrlB, HIGH);
        digitalWrite(motorRctrlA, LOW);
        Serial.println("[FWD Sim] Turing Right");
        break;

      case 'L':
      case 'l':
        digitalWrite(motorLctrlA, LOW);
        digitalWrite(motorLctrlB, HIGH);
        digitalWrite(motorRctrlB, LOW);
        digitalWrite(motorRctrlA, HIGH);
        Serial.println("[FWD Sim] Turing Left");
        break;

      case 'S':
      case 's':
        digitalWrite(motorLctrlA, LOW);
        digitalWrite(motorLctrlB, LOW);
        digitalWrite(motorRctrlA, LOW);
        digitalWrite(motorRctrlB, LOW);
        Serial.println("[FWD Sim] Stopping");
        break;

      case 'I':
      case 'i':
        if (speedPercent < 100) {
          speedPercent += 10;
          Serial.print("[FWD Sim] Speen Increased to ");
          Serial.print(speedPercent);
          Serial.println("%");
        } else {
          Serial.println("[FWD Sim] Speed Max Limit Reached: 100%");
        }
        break;

      case 'D':
      case 'd':
        if (speedPercent > 10) {
          speedPercent -= 10;
          Serial.print("[FWD Sim] Speen Decreased to ");
          Serial.print(speedPercent);
          Serial.println("%");
        } else {
          Serial.println("[FWD Sim] Speed Min Limit Reached: 10%");
        }
        break;

      default:
        break;
    }
  }
}
