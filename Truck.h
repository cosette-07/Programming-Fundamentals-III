#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

// Derived class for Truck
class Truck : public Vehicle {
private:
    bool sidePanelStorage, autoReleaseTailgate;

public:
    // Constructor intializing both the base and derived class properties
    Truck(std::string make, std::string model, std::string color, int mpg, double msrp, bool sidePanelStorage, bool autoReleaseTailgate);
    void printVehicleDetails() const override;
};

#endif
