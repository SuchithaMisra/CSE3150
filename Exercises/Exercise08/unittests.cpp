#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Electric.h"
#include "Gasoline.h"
#include "Hybrid.h"

TEST_CASE("Electric Vehicle") {
    Electric electric("Test Electric");

    SUBCASE("Start and Stop - Test Electric") {
        electric.Start();
        electric.Stop();
        
    }
    SUBCASE("Fuel Efficiency- Test Electric") {
        CHECK(electric.FuelEfficiency() == 100.0);
    }
    SUBCASE("Cost Of Fuel - Test Electric") {
        CHECK(electric.CostOfFuel() == 0.05);
    }
}

TEST_CASE("Gasoline Vehicle") {
    SUBCASE("Start and Stop") {
        Gasoline gasoline("Test Gasoline");
        gasoline.Start();
        gasoline.Stop();
        
    }
    SUBCASE("Fuel Efficiency") {
        Gasoline gasoline("Test Gasoline");
        CHECK(gasoline.FuelEfficiency() == 30.0);
    }
    SUBCASE("Cost Of Fuel") {
        Gasoline gasoline("Test Gasoline");
        CHECK(gasoline.CostOfFuel() == 0.15);
    }
}

TEST_CASE("Hybrid Vehicle") {
    SUBCASE("Start and Stop") {
        Hybrid hybrid("Test Hybrid");
        hybrid.Start();
        hybrid.Stop();
        
    }
    SUBCASE("Efficiency") {
        Hybrid hybrid("Test Hybrid");
        double expectedEfficiency = (hybrid.Electric::FuelEfficiency() + hybrid.Gasoline::FuelEfficiency()) / 2.0;
        CHECK(hybrid.FuelEfficiency() == expectedEfficiency);
    }
    SUBCASE("Cost Of Fuel") {
        Hybrid hybrid("Test Hybrid");
        double expectedCost = (hybrid.Electric::CostOfFuel() + hybrid.Gasoline::CostOfFuel()) / 2.0;
        CHECK(hybrid.CostOfFuel() == expectedCost);
    }
}
