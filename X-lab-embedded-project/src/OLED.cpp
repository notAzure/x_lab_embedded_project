#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "OLED.h"
#include "OLED_animation_frames.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void OLED_helloworld() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(1, 1);
    display.println("Hello, World!");
    display.display();
}
void OLEDsetup() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.clearDisplay();
    display.display();
}
void OLED_animation() {
    static int frame=0;
    display.clearDisplay();
    display.drawBitmap(0, 0, oledGifFrames[frame], 128, 64, SSD1306_WHITE);
    display.display();
    frame = (frame + 1) % OLED_GIF_FRAME_COUNT;
    delay(OLED_GIF_FRAME_DELAY_MS);
}