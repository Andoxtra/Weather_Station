#include "RGBLed.h"

#define NUMPIXELS 1


RGBLed::RGBLed(short int PIN) {
    RGBLed::object = new Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB);
}

void RGBLed::setColor(short r, short g, short b) {
    RGBLed::object->setPixelColor(0, Adafruit_NeoPixel::Color(r, g, b));
    RGBLed::object->show();
}

void RGBLed::clear() {
    RGBLed::setColor(0, 0, 0);
}

void RGBLed::init(){
    RGBLed::object->begin();
}
