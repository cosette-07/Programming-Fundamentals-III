#include <iostream>
#include <vector>
#include <memory>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

// Function prototypes
void addVehicle(std::vector<std::shared_ptr<Vehicle>>& inventory);
void printInventory(const std::vector<std::shared_ptr<Vehicle>>& inventory);
void searchInventory(const std::vector<std::shared_ptr<Vehicle>>& inventory);
void printVehicleDetails(const std::vector<std::shared_ptr<Vehicle>>& inventory);

int main() {
    std::vector<std::shared_ptr<Vehicle>> inventory; // Stores all the vehicles
    int choice;

    // Main menu loop
    do {
        std::cout << "\n== Car Dealership Inventory System ==\n";
        std::cout << "1) Add a Car or Truck to Inventory\n";
        std::cout << "2) Print List of Current Inventory\n";
        std::cout << "3) Search Inventory by Make, Model, or Color\n";
        std::cout << "4) Print Details About a Specific Vehicle\n";
        std::cout << "5) Exit\n";
        std::cout << "Enter which choice you would to do (1, 2, 3, 4, or 5): ";

        while (!(std::cin >> choice)) {  // Validate input
            std::cin.clear(); // Clear the input buffer
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter a valid menu option: ";
        }

        switch (choice) {
            case 1:
                addVehicle(inventory);
                break;
            case 2:
                printInventory(inventory);
                break;
            case 3:
                searchInventory(inventory);
                break;
            case 4:
                printVehicleDetails(inventory);
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid option. Please select a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add a vehicle to inventory
void addVehicle(std::vector<std::shared_ptr<Vehicle>>& inventory) {
    std::string type;
    std::cout << "Would you like to add a Car or a Truck? ";
    std::cin >> type;

    std::string make, model, color;
    int mpg;
    double msrp;

    std::cout << "Enter Make: ";
    std::cin >> make;
    
    std::cout << "Enter Model: ";
    std::cin >> model;
    
    std::cout << "Enter Color: ";
    std::cin >> color;
    
    std::cout << "Enter MPG: ";
    while (!(std::cin >> mpg)) { // Validate the integer input
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Enter a valid MPG: ";
    }

    std::cout << "Enter MSRP: ";
    while (!(std::cin >> msrp)) { // Validate the double input
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Enter a valid MSRP: ";
    }

    std::cin.ignore(); // Remove newline left in the buffer

    if (type == "Car" || type == "car") {
        bool spare, wiper;
        
        std::cout << "Spare in Trunk? (1 for Yes, 0 for No): ";
        while (!(std::cin >> spare)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter 1 for Yes, 0 for No: ";
        }

        std::cout << "Rear Windshield Wiper? (1 for Yes, 0 for No): ";
        while (!(std::cin >> wiper)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter 1 for Yes, 0 for No: ";
        }

        inventory.push_back(std::make_shared<Car>(make, model, color, mpg, msrp, spare, wiper));
        std::cout << "Car added successfully!\n";
    } 
    else if (type == "Truck" || type == "truck") {
        bool sidePanel, autoTailgate;
        
        std::cout << "Side Panel Storage? (1 for Yes, 0 for No): ";
        while (!(std::cin >> sidePanel)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter 1 for Yes, 0 for No: ";
        }

        std::cout << "Auto Release Tailgate? (1 for Yes, 0 for No): ";
        while (!(std::cin >> autoTailgate)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter 1 for Yes, 0 for No: ";
        }

        inventory.push_back(std::make_shared<Truck>(make, model, color, mpg, msrp, sidePanel, autoTailgate));
        std::cout << "Truck added successfully!\n";
    } 
    else {
        std::cout << "Invalid choice! Returning to menu.\n";
    }
}

// Function to print all the vehicles in inventory
void printInventory(const std::vector<std::shared_ptr<Vehicle>>& inventory) {
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    std::cout << "\nCurrent Inventory:\n";
    for (const auto& vehicle : inventory) {
        vehicle->printVehicleDetails();
    }
}

// Function to search inventory by make, model, or color
void searchInventory(const std::vector<std::shared_ptr<Vehicle>>& inventory) {
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    std::string searchTerm;
    std::cout << "Enter Make, Model, or Color to search: ";
    std::cin >> searchTerm;

    bool found = false;
    for (const auto& vehicle : inventory) {
        if (vehicle->getMake() == searchTerm || vehicle->getModel() == searchTerm || vehicle->getColor() == searchTerm) {
            vehicle->printVehicleDetails();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching vehicles found.\n";
    }
}

// Function to print the details about a specific vehicle
void printVehicleDetails(const std::vector<std::shared_ptr<Vehicle>>& inventory) {
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    std::string searchMake, searchModel;
    std::cout << "Enter the Make of the vehicle: ";
    std::cin >> searchMake;
    std::cout << "Enter the Model of the vehicle: ";
    std::cin >> searchModel;

    bool found = false;
    for (const auto& vehicle : inventory) {
        if (vehicle->getMake() == searchMake && vehicle->getModel() == searchModel) {
            vehicle->printVehicleDetails();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Vehicle not found in inventory.\n";
    }
}
