#include <Arduino.h>
#include "Steppermotor.h"

void steppermotorsetup()
{
    int GPIOlist[] = {5,18,19,21};
    for (int i = 0; i < 4; i++)
    {
        pinMode(GPIOlist[i], OUTPUT);
        digitalWrite(GPIOlist[i], LOW);
    }
}
void stepTranslate(int step)
{
    int GPIOlist[] = {5,18,19,21};
    switch (step)
    {
    case 0: // 1000
        digitalWrite(GPIOlist[0], HIGH);
        digitalWrite(GPIOlist[1], LOW);
        digitalWrite(GPIOlist[2], LOW);
        digitalWrite(GPIOlist[3], LOW);
        break;
    case 1: // 1100
        digitalWrite(GPIOlist[0], HIGH);
        digitalWrite(GPIOlist[1], HIGH);
        digitalWrite(GPIOlist[2], LOW);
        digitalWrite(GPIOlist[3], LOW);
        break;
    case 2: // 0100
        digitalWrite(GPIOlist[0], LOW);
        digitalWrite(GPIOlist[1], HIGH);
        digitalWrite(GPIOlist[2], LOW);
        digitalWrite(GPIOlist[3], LOW);
        break;
    case 3: // 0110
        digitalWrite(GPIOlist[0], LOW);
        digitalWrite(GPIOlist[1], HIGH);
        digitalWrite(GPIOlist[2], HIGH);
        digitalWrite(GPIOlist[3], LOW);
        break;
    case 4: // 0010
        digitalWrite(GPIOlist[0], LOW);
        digitalWrite(GPIOlist[1], LOW);
        digitalWrite(GPIOlist[2], HIGH);
        digitalWrite(GPIOlist[3], LOW);
        break;
    case 5: // 0011
        digitalWrite(GPIOlist[0], LOW);
        digitalWrite(GPIOlist[1], LOW);
        digitalWrite(GPIOlist[2], HIGH);
        digitalWrite(GPIOlist[3], HIGH);
        break;
    case 6: // 0001
        digitalWrite(GPIOlist[0], LOW);
        digitalWrite(GPIOlist[1], LOW);
        digitalWrite(GPIOlist[2], LOW);
        digitalWrite(GPIOlist[3], HIGH);
        break;
    case 7: // 1001
        digitalWrite(GPIOlist[0], HIGH);
        digitalWrite(GPIOlist[1], LOW);
        digitalWrite(GPIOlist[2], LOW);
        digitalWrite(GPIOlist[3], HIGH);
        break;
    }
}
void rotateCertainSteps(int steps, int delayTime)
{
    int GPIOlist[] = {5,18,19,21};
    if (steps < 0)
    {
        for (int i = 0; i < -steps; i++)
        {
            stepTranslate((7 - (i % 8)) % 8);
            delay(delayTime);
        }
    }
    else
    {
        for (int i = 0; i < steps; i++)
        {
            stepTranslate(i % 8);
            delay(delayTime);
        }
    }
}