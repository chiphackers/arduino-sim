#include "Arduino.h"
#include <iostream>

using namespace std;

int SerialClass::begin(int a){
    cout << "Received begin serial " << a << endl;
}

SerialClass Serial;

extern void setup();
extern void loop();

int main(){
    setup();
    loop();
    cout << "hello world" << endl;
}

