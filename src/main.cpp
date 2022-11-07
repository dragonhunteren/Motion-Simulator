#include <Arduino.h>
#include <Servo.h>

#define MAX_COMMAND_SIZE 5
char commandBuf[MAX_COMMAND_SIZE];

#define SERVO_A_PIN 9
#define SERVO_B_PIN 10
#define SERVO_C_PIN 11

Servo servoA;
Servo servoB;
Servo servoC;

void setup()
{
  servoA.attach(SERVO_A_PIN);
  servoB.attach(SERVO_B_PIN);
  servoC.attach(SERVO_C_PIN);
  Serial.begin(9600);
}

void loop()
{
  if (Serial)
  {
    int rlen = Serial.readBytesUntil('\n', commandBuf, MAX_COMMAND_SIZE);
    if (rlen > 0)
    {
      Servo servoToControl;
      if (commandBuf[0] == 'A')
      {
        servoToControl = servoA;
      }
      else if (commandBuf[0] == 'B')
      {
        servoToControl = servoB;
      }
      else if (commandBuf[0] == 'C')
      {
        servoToControl = servoC;
      }
      else
      {
        return;
      }

      int degree = atoi(&commandBuf[1]);
      servoToControl.write(degree);
    }
  }
}