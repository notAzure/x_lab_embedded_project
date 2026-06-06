#include <Arduino.h>
#include "LEDflow.h"

void LEDsetup() {
    int GPIOlist[]={4,5,18,19,21};
    for(int i=0;i<5;i++){
        pinMode(GPIOlist[i],OUTPUT);
        digitalWrite(GPIOlist[i],LOW);
    }
}

void LEDflow() {
    int GPIOlist[]={4,5,18,19,21};
    for(int i=0;i<5;i++){
        digitalWrite(GPIOlist[i],HIGH);
        delay(200);
        digitalWrite(GPIOlist[i],LOW);
        delay(200);
        Serial.println("LED ");
    }

}
