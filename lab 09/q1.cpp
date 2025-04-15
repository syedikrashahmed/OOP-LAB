#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    protected:
    string model; //Stores the vehicle’s model name.
    double rate; //Stores the daily rental rate.

    public:
    Vehicle() : model(""), rate(0.0) {}
    Vehicle(string model, double rate) : model(model), rate(rate) {}
    virtual double getDailyRate() = 0; //Pure virtual function to return the daily rate. 
    virtual void displayDetails() = 0; //Pure virtual function to show model and rate.
};

class Car : public Vehicle {
    public:
        Car(string model, double rate) : Vehicle(model, rate) {}
    double getDailyRate() override {
        return rate;
    } 
    void displayDetails() override {
        cout << "model: " << model << ", rate: " << rate << endl;
    }
}; 

class Bike : public Vehicle {
    public:
    Bike(string model, double rate) : Vehicle(model, rate) {}
    double getDailyRate() override {
        return rate;
    }
    void displayDetails() override {
        cout << "model: " << model << ", rate: " << rate << endl;
    }
};  

int main() {
    Vehicle* v[2];
    v[0] = new Car("Cultus", 50);
    v[1] = new Bike("cd 70", 12);
    
    for (int i = 0; i < 2; i++) {
        v[i]->displayDetails();
        cout << "daily rate: " << v[i]->getDailyRate() << endl << endl;
    }

    delete v[0];
    delete v[1];
}
