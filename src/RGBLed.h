#ifndef WEATHERSTATION_RGBLED_H
#define WEATHERSTATION_RGBLED_H

#include "Adafruit_NeoPixel.h"


class RGBLed {
public:
    RGBLed(short int PIN);
    ~RGBLed(){delete object;};
    void setColor(short int r, short int g, short int b);
    void clear();
    void init();
private:
    Adafruit_NeoPixel* object;
};


#endif
