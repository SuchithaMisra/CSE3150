#include "Electric.h"
#include <iostream>

using namespace std; 

Electric::Electric(std::string name) : Vehicle(name, 0) {
    cout << "Constructor: Electric" << endl;
}

Electric::~Electric() {
    cout << "Destructor: Electric" << endl;
}

void Electric::Start() {
    cout << "Electric START" << endl;
}

void Electric::Stop() {
    cout << "Electric STOP" << endl;
}

double Electric::CostOfFuel() {
    return 0.05; 
}

double Electric::FuelEfficiency() {
    return 100.0;
}
