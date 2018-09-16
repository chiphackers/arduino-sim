#include "Arduino.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

/**
 * Declaring Global variables
 * NOTE: This is not clean method. Need refactoring
 */
char* problemDir = NULL;
char* testFile   = NULL;

SerialClass Serial;
typedef std::map<string, int> pinValueMap;

int SerialClass::begin(int a){
    cout << "Received begin serial " << a << endl;
}
void SerialClass::println(int a){
    cout << a<< endl;
}

extern void delay(int a){
   cout << "Sleeping for " << a <<" milliseconds\n"; 
}

extern int analogRead(pin b){
    pinValueMap dic;
    if(problemDir != NULL){
        string infileStr = string(problemDir) + "./sources/src/portvals.txt";
        ifstream infile(infileStr);
        if (infile.is_open()) {
            int number;
            string str;
            char c;
            while (infile >> number >> c >> str && c == ','){
                //std::cout << number << " " << str << "\n";
                
                dic[str] = number;
                cout << str  << " " << number << "\n";
            }
        }
    }else{
        cout << "Unable to open file";
    }
    string pinName;
	switch(b){
	   case  A0: 
		pinName = "A0" ; break;
	   case  A1: 
		pinName = "A1" ; break;
	   case  B0: 
		pinName = "B0" ; break;	
    }
	
  return dic[pinName];
}

extern void setup();
extern void loop();

int main(int argc, char** argv){
    if(argc != 3){
        cout << "[ERROR  ]: Missing arguments to the simulator";
    }else{
        problemDir = argv[1];
        testFile   = argv[0];
    }

    setup();
    loop();
    cout << "hello world" << endl;
}

