#ifndef GASOLINE_H
#define GASOLINE_H

#include "Vehicle.h"

class Gasoline : public virtual Vehicle {
public:
    Gasoline(std::string name);
    virtual ~Gasoline();

    void Start() override;
    void Stop() override;
    double CostOfFuel() override;
    double FuelEfficiency();
};

#endif
