#ifndef ARDUINO_H
#define ARDUINO_H

#define HIGH 1
#define LOW 0

#define INPUT 1
#define OUTPUT 0

#include <iostream>
#include <map>

enum pin{
    A0,
    A1,
    B0
};



extern void setup();
extern void loop();

void delay(int a);
int analogRead(pin a);
int digitalRead(int dPinNo);
void digitalWrite(int pin, int val);
void pinMode(int pin, int val);
using namespace std;


typedef std::map<string, int> aPinValueMap;
typedef std::map<int, int> dPinValueMap;

class SerialClass {
    public:
        int begin(int);
	void println(int); 
	void println(string);
};


/*
class AnalogReadClass {
	public: 
		
}*/
extern SerialClass Serial;

#endif
