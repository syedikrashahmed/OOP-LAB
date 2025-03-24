#include <iostream>
using namespace std;
#include <string>

class User;
class Device;

class Device {
    string deviceID;
    string deviceType;
    double powerRating;
    bool status;

    public:
    Device(string id, string type, double rating, bool stat) : deviceID(id), deviceType(type), powerRating(rating), status(stat) {}

    Device() : deviceID(""), deviceType(""), powerRating(0.0), status(false) {}
    
    virtual void turnOn() {}

    virtual void turnOff() {}

    virtual double calculatePowerUsage(int hours) {}

    friend void AccessDevices(Device* device, int deviceCount, User* user) {}
};

class Lights : public Device {
    public:
    Lights(string id, string type, double rating, bool stat) : Device(id, type, rating, stat) {}

    Lights() : Device() {}

    void turnOn() {
        status = true;
    }

    void turnOff() {
        status = false;
    }

    double calculatePowerUsage(int hours) override {
        return powerRating * hours;
    }
}

class Fans : public Device {
    int speedFactor;
    public:
    Fans(string id, string type, double rating, bool stat, int speed) : Device(id, type, rating, stat), speedFactor(speed) {}

    Fans() : Device(), speedFactor(0) {}

    void turnOn() {
        status = true;
    }
    
    void turnOff() {
        status = false;
    }

    double calculatePowerUsage(int hours) override {
        return powerRating * hours * speedFactor;
    }
}

class ACs : public Device {
    int currentTemp;
    int desiredTemp;

    public:
    ACs(string id, string type, double rating, bool stat, int currentTemp, int desiredTemp) : Device(id, type, rating, stat), currentTemp(currentTemp), desiredTemp(desiredTemp) {}

    ACs() : Device(), currentTemp(0), desiredTemp(0) {}
    void turnOn() {
        status = true;
    }

    void turnOff() {
        status = false;
    }

    double calculatePowerUsage(int hours) override {
        return powerRating * hours * (1 - (currentTemp - desiredTemp) / 100);
    }
    
}

class SecuiritySystems : public Device {
    float const powerConsumption;
    bool secuirityStatusCheck;

    public:
    SecuiritySystems(string id, string type, double rating, bool stat, float powerConsumption, bool secuirityStatusCheck) : Device(id, type, rating, stat), powerConsumption(powerConsumption), secuirityStatusCheck(secuirityStatusCheck) {}

    SecuiritySystems() : Device(), powerConsumption(0.0), secuirityStatusCheck(false) {}
    void turnOn() {
        status = true;
    }

    void turnOff() {
        status = false;
    }

    double calculatePowerUsage(int hours) override {
        if (secuirityStatusCheck) {
            return powerConsumption;
        }
        else {
            return 0.0;
        }
    }
}

class User {
    string userId;
    string userName;
    int accessLevel;

    public:
    friend void AccessDevices(Device* device, int deviceCount, User* user) {}
};

void AccessDevices(Device* device, int deviceCount, User* user) {
    for (int i = 0; i < deviceCount; i++) {
        if  (device[i].deviceType == "Security System"){
            if (user->accessLevel == 1){
                cout << "Device ID: " << device[i]->deviceID << endl;
                cout << "Device Type: " << device[i]->deviceType << endl;
                cout << "Device Power Rating: " << device[i]->powerRating << endl;
                cout << "Device Status: " << device[i]->status << endl;
            }
        }
        else {
            cout << "Access Denied" << endl;
        }
    }
}
