#include "Car.h"

// Constructor
Car::Car(std::string make, std::string model, std::string color, int mpg, double msrp, bool spareInTrunk, bool rearWindshieldWiper)
    : Vehicle(make, model, color, mpg, msrp), spareInTrunk(spareInTrunk), rearWindshieldWiper(rearWindshieldWiper) {}

// Override base class function to print the car-specific details
void Car::printVehicleDetails() const {
    Vehicle::printVehicleDetails();
    
    std::string isThereASpareInTrunk;
    if (spareInTrunk) {
        isThereASpareInTrunk = "Yes";
    } 
    else {
        isThereASpareInTrunk = "No";
    }

    std::string doesItHaveARearWiper;
    if (rearWindshieldWiper) {
        doesItHaveARearWiper = "Yes";
    } 
    else {
        doesItHaveARearWiper = "No";
    }

    std::cout << "Spare in Trunk: " << isThereASpareInTrunk << "\n";
    std::cout << "Rear Windshield Wiper: " << doesItHaveARearWiper << "\n";
}

