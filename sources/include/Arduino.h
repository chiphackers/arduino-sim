#ifndef ARDUINO_H
#define ARDUINO_H

#include <iostream>

enum pin{
    A0,
    A1,
    B0
};
extern void setup();
extern void loop();

void delay(int a);
int analogRead(pin a);


using namespace std;



class SerialClass {
    public:
        int begin(int);
	void println(int); 
};

/*
class AnalogReadClass {
	public: 
		
}*/
extern SerialClass Serial;

#endif
