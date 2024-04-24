#include "Hybrid.h"
#include <iostream>

using namespace std;

Hybrid::Hybrid(std::string name) : Vehicle(name, 0), Electric(name), Gasoline(name) {
    cout << "Constructor: Hybrid" << endl;
}

Hybrid::~Hybrid() {
    cout << "Destructor: Hybrid" << endl;
}

void Hybrid::Start() {
    Electric::Start(); 
}

void Hybrid::Stop() {
    Electric::Stop();
}

double Hybrid::CostOfFuel() {
    return (Electric::CostOfFuel() + Gasoline::CostOfFuel()) / 2.0; 
}

double Hybrid::FuelEfficiency() {
    return (Electric::FuelEfficiency() + Gasoline::FuelEfficiency()) / 2.0; 
}
