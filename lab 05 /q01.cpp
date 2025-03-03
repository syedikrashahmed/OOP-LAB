/*Task-01:
Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of those Square objects. After each time the area method is called, call that square’s getters for area and allareas to display the updated values.*/

#include <iostream>
using namespace std;
#include <string>

class Square {
    float sideLength;
    float area;
    static float allareas;

public:
    Square() {
        sideLength = 0.0;
        area = 0.0;
    }

    Square(float sideLength) {
        this->sideLength = sideLength;
        area = 0.0;
    }

    void setSideLength(float sideLength) {
        this->sideLength = sideLength;
    }

    float getSideLength() const {
        return sideLength;
    }

    void setArea(float area) {
        this->area = area;
    }

    float getArea() const {
        return area;
    }

    static void setAllAreas(float allareas) {
        Square::allareas = allareas;
    }

    static float getAllAreas() {
        return allareas;
    }

    void calculateArea() {
        area = sideLength * sideLength;
        allareas += area;
    }
};

float Square::allareas = 0.0;

int main() {
    Square square1(5.0);
    Square square2(3.0);
    Square square3(6.0);

    square1.calculateArea();
    square2.calculateArea();
    square3.calculateArea();
    cout << "Area of square1: " << square1.getArea() << endl;
    cout << "Area of square2: " << square2.getArea() << endl;
    cout << "Area of square3: " << square3.getArea() << endl;

    cout << "Total areas calculated: " << Square::getAllAreas() << endl;
}
