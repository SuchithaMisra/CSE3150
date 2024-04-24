#ifndef HYBRID_H
#define HYBRID_H

#include "Electric.h"
#include "Gasoline.h"

class Hybrid : public Electric, public Gasoline {
public:
    Hybrid(std::string name);
    virtual ~Hybrid();

    void Start() override;
    void Stop() override;
    double CostOfFuel() override;
    double FuelEfficiency();
};

#endif
