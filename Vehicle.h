#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>

// Base class representing the basic aspects of a vehicle
class Vehicle {
protected:  
    std::string make, model, color;
    int mpg;
    double msrp;

public:
    // Constructor to initialize the vehicle's properties
    Vehicle(std::string make, std::string model, std::string color, int mpg, double msrp);
    virtual void printVehicleDetails() const;
    
    std::string getMake() const;
    std::string getModel() const;
    std::string getColor() const;
    int getMPG() const;
    double getMSRP() const;
    
    // Virtual destructor to allow the correct cleanup during the process of deleting derived objects
    virtual ~Vehicle() {}
};

#endif
