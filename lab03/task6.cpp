/*Task 6:
Create a class called Smartphone with the following attributes:
    > Company
    > Model
    > Display Resolution
    > RAM
    > ROM
    > Storage

Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.For example:

    > Make a phone call
    > Send a message
    > Connect to the wifi
    > Browse the internet

Create different smartphone objects. Set their attributes using the setter functions and display their attributes after using the getter functions to fetch the attributes.*/

#include <iostream>
using namespace std;

class Smartphone {
    string company;
    string model;
    int displayReso;
    int ram;
    int rom;
    int storage;

    public:
    string getCompany() {
        return company;
    }

    string getModel() {
        return model;
    }

    int getDisplayResolution() {
        return displayReso;
    }

    int getRAM() {
        return ram;
    }

    int getROM() {
        return rom;
    }

    int getStorage() {
        return storage;
    }

    void setCompany(string c) {
        company = c;
    }

    void setModel(string m) {
        model = m;
    }

    void setDisplayResolution(int dr) {
        displayReso = dr;
    }

    void setRAM(int r) {
        ram = r;
    }

    void setROM(int r) {
        rom = r;
    }

    void setStorage(int s) {
        storage = s;
    }

    void PhoneCall() {
        cout << "Making a phone call" << endl;
    }

    void Message() {
        cout << "Sending a message" << endl;
    }

    void connectWifi() {
        cout << "Connecting to WiFi" << endl;
    }

    void browseInternet() {
        cout << "Browsing the internet" << endl;
    }
};

int main() {
    Smartphone smartphone1, smartphone2;

    smartphone1.setCompany("Samsung");
    smartphone1.setModel("S6");
    smartphone1.setDisplayResolution(2532);
    smartphone1.setRAM(4);
    smartphone1.setROM(32);
    smartphone1.setStorage(32);

    smartphone2.setCompany("Vivo");
    smartphone2.setModel("Y20");
    smartphone2.setDisplayResolution(1080);
    smartphone2.setRAM(4);
    smartphone2.setROM(64);
    smartphone2.setStorage(64);

    cout << "Smartphone 1:" << endl;
    cout << "Company: " << smartphone1.getCompany() << endl;
    cout << "Model: " << smartphone1.getModel() << endl;
    cout << "Display Resolution: " << smartphone1.getDisplayResolution() << endl;
    cout << "RAM: " << smartphone1.getRAM() << " GB" << endl;
    cout << "ROM: " << smartphone1.getROM() << " GB" << endl;
    cout << "Storage: " << smartphone1.getStorage() << " GB" << endl;

    smartphone1.PhoneCall();
    smartphone1.Message();
    smartphone1.connectWifi();
    smartphone1.browseInternet();
    cout << endl;

    cout << "Smartphone 2:" << endl;
    cout << "Company: " << smartphone2.getCompany() << endl;
    cout << "Model: " << smartphone2.getModel() << endl;
    cout << "Display Resolution: " << smartphone2.getDisplayResolution() << endl;
    cout << "RAM: " << smartphone2.getRAM() << " GB" << endl;
    cout << "ROM: " << smartphone2.getROM() << " GB" << endl;
    cout << "Storage: " << smartphone2.getStorage() << " GB" << endl;

    smartphone2.PhoneCall();
    smartphone2.Message();
    smartphone2.connectWifi();
    smartphone2.browseInternet();
}