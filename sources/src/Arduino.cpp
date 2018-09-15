#include "Arduino.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

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
    ifstream infile("./sources/src/portvals.txt");
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
    else cout << "Unable to open file";
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

int main(){
    setup();
    loop();
    cout << "hello world" << endl;
}

