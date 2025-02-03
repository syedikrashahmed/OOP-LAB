/*Task 1: Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor should initialize this data to 0, and another should initialize it to fixed values. Another member function should display it, in 11:59:59 format. The final member function should add two objects of type time passed as arguments. A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized. Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should display the value of this third variable. Make appropriate member functions const.*/

#include <iostream>
using namespace std;

class Time {
    int hours;
    int minutes;
    int seconds;

    public:
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0; 
    }

    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void display() const{
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    Time add(Time t1, Time t2) {

        Time result;
        result.hours = t1.hours + t2.hours;
        result.minutes = t1.minutes + t2.minutes; 
                result.seconds = t1.seconds + t2.seconds;

        if (result.seconds > 59) {
            result.minutes++;
            result.seconds = result.seconds - 60;
        }
        if (result.minutes > 59) {
            result.hours++;
            result.minutes = result.minutes - 60;
        }
        if (result.hours > 23) {
            result.hours = result.hours - 24;
            
        }

        return result;
    }
};

int main() {
    Time t1(2, 20, 54); 
    Time t2(3, 39, 6);
    Time t3;
    t3 =  t3.add(t1, t2);
    t3.display();
}

