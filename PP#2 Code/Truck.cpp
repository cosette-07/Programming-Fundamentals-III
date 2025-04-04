#include "Truck.h"

// Constructor
Truck::Truck(std::string make, std::string model, std::string color, int mpg, double msrp, bool sidePanelStorage, bool autoReleaseTailgate)
    : Vehicle(make, model, color, mpg, msrp), sidePanelStorage(sidePanelStorage), autoReleaseTailgate(autoReleaseTailgate) {}

// Override base class function to print the truck-specific details
void Truck::printVehicleDetails() const {
    Vehicle::printVehicleDetails();
    
    std::string doesItHaveSidePanelStorage;
    if (sidePanelStorage) {
        doesItHaveSidePanelStorage = "Yes";
    } 
    else {
        doesItHaveSidePanelStorage = "No";
    }

    std::string doesItHaveAutoReleaseTailgate;
    if (autoReleaseTailgate) {
        doesItHaveAutoReleaseTailgate = "Yes";
    } 
    else {
        doesItHaveAutoReleaseTailgate = "No";
    }

    std::cout << "Side Panel Storage: " << doesItHaveSidePanelStorage << "\n";
    std::cout << "Auto Release Tailgate: " << doesItHaveAutoReleaseTailgate << "\n";
}