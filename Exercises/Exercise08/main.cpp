#include "Hybrid.h"
#include <iostream>
using namespace std;

int main() {


    {
    string electricVehicleName = "Quiet Lightning";
    Electric electricVehicle(electricVehicleName);
    electricVehicle.Start();
    cout << electricVehicleName << " fuel efficiency: " << electricVehicle.FuelEfficiency() << " miles/kWh" << endl;
    cout << electricVehicleName << " cost of fuel: $" << electricVehicle.CostOfFuel() << "/kWh" << endl;
    electricVehicle.Stop();
    }
    cout << endl; 
    
    {
    string gasolineVehicleName = "Thunder Roar";
    Gasoline gasolineVehicle(gasolineVehicleName);
    gasolineVehicle.Start();
    cout << gasolineVehicleName << " fuel efficiency: " << gasolineVehicle.FuelEfficiency() << " miles/gallon" << endl;
    cout << gasolineVehicleName << " cost of fuel: $" << gasolineVehicle.CostOfFuel() << "/gallon" << endl;
    gasolineVehicle.Stop();
    }
    cout << endl;

    {
    string hybridVehicleName = "Eco Storm";
    Hybrid hybridVehicle(hybridVehicleName);
    hybridVehicle.Start();
    cout << hybridVehicleName << " fuel efficiency: " << hybridVehicle.FuelEfficiency() << " combined miles/energy unit" << endl;
    cout << hybridVehicleName << " cost of fuel: $" << hybridVehicle.CostOfFuel() << "/energy unit" << endl;
    hybridVehicle.Stop();
    }

    return 0;
}
