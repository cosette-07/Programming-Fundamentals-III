#include "Vehicle.h"

// Constructor
Vehicle::Vehicle(std::string make, std::string model, std::string color, int mpg, double msrp)
    : make(make), model(model), color(color), mpg(mpg), msrp(msrp) {}

// Getters for searching vehicles in inventory
std::string Vehicle::getMake() const { return make; }
std::string Vehicle::getModel() const { return model; }
std::string Vehicle::getColor() const { return color; }
int Vehicle::getMPG() const { return mpg; }
double Vehicle::getMSRP() const { return msrp; }

// Print Details
void Vehicle::printVehicleDetails() const {
    std::cout << "Make: " << make << "\nModel: " << model << "\nColor: " << color
              << "\nMPG: " << mpg << "\nMSRP: $" << msrp << "\n";
}
