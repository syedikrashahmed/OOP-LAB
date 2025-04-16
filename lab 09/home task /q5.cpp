#include <iostream>
using namespace std;

class Activity {
    public:
    Activity() {}

    virtual void calculateCaloriesBurned() = 0;
};

class Running : public Activity {
    double distance, time;

    public:
    Running() : distance(0.0), time(0.0), Activity() {}

    Running(double distance, double time) : distance(distance), time(time), Activity() {}

    void calculateCaloriesBurned() override {
        cout << "calculating calories burned for running: 5 * (distance/time)" << endl;
    cout << 5 * (distance/time) << endl;
    }
};

class Cycling : public Activity {
    double speed, time;

    public:
    Cycling() : speed(0.0), time(0.0), Activity() {}

    Cycling(double speed, double time) : speed(speed), time(time), Activity() {}

    void calculateCaloriesBurned() override {
        cout << "calculating calories burned for cycling: 5 * speed" << endl;
    cout << 5 * speed << endl;
    }
};

int main () {
    Running r1(70, 10);
    Cycling c1(33, 45);

    r1.calculateCaloriesBurned();
    c1.calculateCaloriesBurned();
}