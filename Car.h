#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

// Derived class for Car
class Car : public Vehicle {
private:
    bool spareInTrunk, rearWindshieldWiper;

public:
    // Constructor intializing both the base and derived class properties
    Car(std::string make, std::string model, std::string color, int mpg, double msrp, bool spareInTrunk, bool rearWindshieldWiper);
    void printVehicleDetails() const override;
};

#endif
