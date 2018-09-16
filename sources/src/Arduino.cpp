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

aPinValueMap dic;
dPinValueMap ddic;

SerialClass Serial;

int SerialClass::begin(int a){
    cout << "Received begin serial " << a << endl;
}
void SerialClass::println(int a){
    cout << a<< endl;
}

void SerialClass::println(string a){
    cout << a << endl;
}

void delay(int a){
   cout << "Sleeping for " << a <<" milliseconds\n"; 
}


void pinMode(int pin, int val){
	if ( (val == 0) ){
		cout << "Making the pin " << pin  << " OUTPUT " <<endl;
			
	}
	else if ( (val == 1) ) {
		cout << "Making the pin " << pin  << " INPUT " <<endl;
	}
	else{
		cout << "Wrong Type\n" << endl; 
	}	
}


int digitalRead(int dPinNo){
    if(problemDir != NULL){
        string infileStr = string(problemDir) + string("/dportvals.txt");
        ifstream infile(infileStr.c_str());
        if (infile.is_open()) {
            int portNumber;
            int portValue;
            char c;
            while (infile >> portNumber >> c >> portValue && c == ','){
                ddic[portNumber] = portValue;
            }
        }
    }else{
	cout << "Unable to open digital port values file";
	}
    return ddic[dPinNo];
} 

void digitalWrite(int pin, int val){
	if ( (val == 0) || (val == 1) ) {
		cout << "Writing " << val << " to pin " << pin << endl;
	}
	else{
		cout << "Wrong value\n" << val << endl; 
	}	
}

int analogRead(pin b){
    if(problemDir != NULL){
        string infileStr = string(problemDir) + string("/aportvals.txt");
        ifstream infile(infileStr.c_str());
        if (infile.is_open()) {
            int number;
            string str;
            char c;
            while (infile >> number >> c >> str && c == ','){
                //std::cout << number << " " << str << "\n";
                
                dic[str] = number;
                //cout << str  << " " << number << "\n";
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
        testFile   = argv[2];
    }

    setup();
    loop();
    cout << "hello world" << endl;
}

