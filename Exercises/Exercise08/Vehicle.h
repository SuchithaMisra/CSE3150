#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    double weight;
    std::string name;

public:
    Vehicle(std::string nm, double wt);
    virtual ~Vehicle();

    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual double CostOfFuel() = 0;
};

#endif