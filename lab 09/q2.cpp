#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
protected:
    
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getStatus() const = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
    protected:
    bool isOn;
    int brightness;

    public:
    LightBulb() : isOn(false), brightness(0) {}
    void turnOn() override { isOn = true; }
    void turnOff() override { isOn = false; }
    
    string getStatus() const override {
        string outp = "Lightbulb is ";
        if (isOn) {
            outp += "on and brightness is " + to_string(brightness) ;
            return outp;
        }
        else {
            outp += "off";
            return outp;
        }
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature; 

public:
    Thermostat() : isOn(false), temperature(0.0) {}
    void turnOn() override { isOn = true; }
    void turnOff() override { isOn = false; }

    string getStatus() const override {
        string outp = "Thermostat is ";
        if (isOn) {
            outp += "on and Temperature is " + to_string(temperature) + "°C" ;
            return outp;
        }
        else {
            outp += "off";
            return outp;
        }
    }
};

int main() {
    LightBulb bulb;
    Thermostat thermo;
    cout << bulb.getStatus() << endl;
    cout << thermo.getStatus() << endl << endl;
    
    bulb.turnOn();
    thermo.turnOn();
    
    cout << bulb.getStatus() << endl;
    cout << thermo.getStatus() << endl << endl;
    
    bulb.turnOff();
    thermo.turnOff();
    
    cout << bulb.getStatus() << endl;
    cout << thermo.getStatus() << endl;
}