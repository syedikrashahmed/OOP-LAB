/*Task 2: Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent toll. Mostly they do, but sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of the total amount of money collected. Model this tollbooth with a class called tollBooth. The two data items are a type unsigned int to hold the total number of cars, and a type double to hold the total amount of money collected. A constructor initializes both of  these to 0. A member function called payingCar() increments the car total and adds 0.50 to the cash total. Another function, called nopayCar(), increments the car total but adds nothing to the cash total. Finally, a member function called display() displays the two totals. Make appropriate member functions const. Include a program to test this class. This program should allow the user to push one key to count a paying car, and another to count a nonpaying car. Pushing the Esc key should cause the program to print out the total cars and total cash and then exit. Note: _getch() (from &lt;conio.h&gt;) reads a key press instantly without requiring Enter. The loop keeps running until the user presses Esc.the ASCII code 27 is the Esc key*/

#include <iostream>
using namespace std;

class tollBooth {
    int carNum;
    double moneyCollected;

    public:
    tollBooth() {
        carNum = 0;
        moneyCollected = 0;
    }

    void payingCar() {
        carNum++;
        moneyCollected += 0.5;
    }

    void nopayCar() {
        carNum++;
    }

    void display() const{
        cout << "Number Of Cars: " << carNum << endl;
        cout << "Money Collected: " << moneyCollected << endl;
    }
};

int main() {
    tollBooth booth1;
    booth1.payingCar();
    booth1.payingCar();
    booth1.nopayCar();
    booth1.nopayCar();
    booth1.payingCar();
    booth1.payingCar();
    booth1.payingCar();
    booth1.nopayCar();

    booth1.display();    
}   