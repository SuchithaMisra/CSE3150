#ifndef ELECTRIC_H
#define ELECTRIC_H

#include "Vehicle.h"

class Electric : public virtual Vehicle {
public:
    Electric(std::string name);
    virtual ~Electric();

    void Start() override;
    void Stop() override;
    double CostOfFuel() override;
    double FuelEfficiency();
};

#endif 
