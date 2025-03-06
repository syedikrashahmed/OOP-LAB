/*Keeping in mind our previous car example, write a class that represents a car, and useaggregation and composition to combine different components like engine, wheels, headlights and steering to create the car object.

Hint: create the individual classes first before performing the composition. Remember that for aggregation, you will need pointers! Youâ€™ll be needing constructors and setters to set these values in case of aggregation. Same hint applies to other questions.*/

#include <iostream>
using namespace std;


class Wheels {
    bool moving;

    public:
    Wheels() {
        moving = false;
    }

    void move() {
        moving = true;
        cout << "moving wheels" << endl;
    }

    void stop() {
        moving = false;
        cout << "wheels stopped" << endl;
    }
};

class Engine {
public:
    void start() {
        cout << "starting engine " << endl;
    }

    void stop() {
        cout << "car engine stopped" << endl;
    }
};

class Headlights {
public:
    void turnOn() {
        cout << "headlights turned on" << endl;
    }

    void turnOff() {
        cout << "headlights turned off" << endl;
    }
};

class Steering {
public:
    void turnLeft() {
        cout << "turning car to left" << endl;
    }

    void turnRight() {
        cout << "turning car to right" << endl;
    }
};

class Car {
    private:
    Engine engine;
    Wheels wheels[4];       
    Headlights* headlights;
    Steering* steering;      
    
    public:
    Car(Headlights* hl, Steering* st) : headlights(hl), steering(st) {
        cout << "car object created" << endl;
    }
    
    void setHeadlights(Headlights* hl) {
        headlights = hl;
    }
    
    void setSteering(Steering* st) {
        steering = st;
    }
    
    void drive() {
        engine.start();
        for (int i = 0; i < 4; i++) {
            wheels[i].move();
        }
        headlights->turnOn();
        steering->turnLeft();
        steering->turnRight();
    }

    void stopDriving() {
        engine.stop();
        for (int i = 0; i < 4; i++) {
            wheels[i].stop();
        }
        headlights->turnOff();
    }

    ~Car() {
        delete headlights;
        delete steering;
        cout << "car object destroyed" << endl;
    }
};

int main() {
    Headlights hl;
    Steering s1;
    Car myCar(&hl, &s1);
    cout << endl << "DRIVING THR CAR" << endl;
    myCar.drive();
    cout << endl << "STOPPNG THR CAR" << endl;
    myCar.stopDriving();
}