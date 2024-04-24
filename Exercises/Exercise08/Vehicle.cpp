#include "Vehicle.h"
#include <iostream>

using namespace std ;

Vehicle::Vehicle(std::string nm, double wt) : name(nm), weight(wt) {
    cout << "Constructor: Vehicle (" << name << ")" << endl;
}

Vehicle::~Vehicle() {
    cout << "Destructor: Vehicle" << endl;
}
