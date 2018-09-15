#ifndef ARDUINO_H
#define ARDUINO_H

#include <iostream>

extern void setup();
extern void loop();

using namespace std;

enum{
    A0,
    A1,
}pin;
 
class SerialClass {
    public:
        int begin(int);
};


extern SerialClass Serial;

#endif
