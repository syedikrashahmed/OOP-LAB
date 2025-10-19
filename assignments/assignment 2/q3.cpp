#include <iostream>
using namespace std;
#include <string> 

/*1. Base Vehicle Class 
All delivery vehicles derive from a common base class that provides fundamental functionality. It includes: 
    • A unique vehicle ID 
    • A method to calculate the optimal delivery route 
    • A function to determine estimated delivery time 
    • A static variable to track the total number of active deliveries*/

class Package {
    string packageID;
    string urgencyLevel;
    string packageName;

    public:
    Package() : packageID(""), urgencyLevel(""), packageName("") {}

    Package(string id, string urgencyLevel, string name) : packageID(id), urgencyLevel(urgencyLevel), packageName(name) {}

    void display() {
        cout << "Product Information:" << endl << "Name: " << packageName << endl << "Package ID: " << packageID << endl << "Urgency Level: " << urgencyLevel << endl;
    }

    string getID() { return packageID; }
    string geturgencyLevel() { return urgencyLevel; }
    string getName() { return packageName; }
};

class Vehicle {
    protected:
    string vehicleID;
    static int totalActiveDeliveries;

    public:
    Vehicle() : vehicleID("") {}

    Vehicle(string vehicleID) : vehicleID(vehicleID) {}

    void calculateOptimalRoute() {}

    void estimateDeliveryTime() {}

    virtual void display() {
        cout << "Vehicle ID: " << vehicleID << endl << "Total Active Deliveries: " << totalActiveDeliveries << endl;
    }
};

int Vehicle::totalActiveDeliveries = 0;

/*RamzanDrone: Small, fast, and airborne, designed for iftar meal deliveries.
A RamzanDrone is an AI-powered aerial delivery system that specializes in delivering small iftar meals at high speed.*/

class RamzanDrone : public Vehicle {
    public:
    RamzanDrone() : Vehicle() {}
    RamzanDrone(string vehicleID) : Vehicle(vehicleID) {}
    void display() override {}
};

/*RamzanTimeShip: Ensures historical accuracy when delivering food to different time periods.
A RamzanTimeShip is a special vehicle that can travel through time, ensuring that historical deliveries follow strict accuracy protocols.*/ 

class RamzanTimeShip : public Vehicle {
    public:
    RamzanTimeShip() : Vehicle() {}
    RamzanTimeShip(string vehicleID) : Vehicle(vehicleID) {}
    void display() override {}
};


/*RamzanHyperPod: High-speed underground transport optimized for bulk food deliveries. 
A RamzanHyperPod is a ground-based high-speed transport system optimized for bulk deliveries */

class RamzanHyperPod : public Vehicle {
    public:
    RamzanHyperPod() : Vehicle() {}
    RamzanHyperPod(string vehicleID) : Vehicle(vehicleID) {}
    void display() override {}
};
