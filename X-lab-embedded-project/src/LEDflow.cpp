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
    static int GPIOlist[] = {4, 5, 18, 19, 21};
    static int currentLED = 0;          // 当前点亮的LED索引
    static bool ledIsOn = false;        // 当前LED是否处于点亮状态
    static unsigned long previousMillis = 0;
    const unsigned long interval = 200; // 200ms 间隔

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        if (ledIsOn) {
            // LED 当前点亮 → 熄灭它，打印信息，切换到下一个LED
            digitalWrite(GPIOlist[currentLED], LOW);
            ledIsOn = false;
            Serial.println("LED ");
            currentLED = (currentLED + 1) % 5;
        } else {
            // LED 当前熄灭 → 点亮当前LED
            digitalWrite(GPIOlist[currentLED], HIGH);
            ledIsOn = true;
        }
    }
}
