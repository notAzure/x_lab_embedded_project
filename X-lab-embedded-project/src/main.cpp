#include <Arduino.h>
#include "LEDflow.h"
#include "Passwordlock.h"
#include "Steppermotor.h"
/*LEDflow part
void setup() {
    Serial.begin(115200);
    LEDsetup();
}

void loop() {
    LEDflow();
}
*/
/*Passwordlock part
void setup() {
    passwordlocksetup();
}
void loop() {
    passwordlockloop();
}
*/
void setup() {
    steppermotorsetup();
    Serial.begin(115200);
}
void loop() {
    Serial.println("Rotating 4096 steps clockwise...");
    rotateCertainSteps(4096, 1); 
    delay(1000);
    Serial.println("Rotating 4096 steps counterclockwise...");
    rotateCertainSteps(-4096, 1); 
    delay(1000); 
}
