/*TASK # 04
You are building a car rental system. Create a class `Car` to manage cars available for rent.
1. Attributes:
     `carID` (int)
     `model` (string)
     `year` (int)
     `isRented` (bool)
2. Define a default constructor that initializes `isRented` to `false`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
     `rentCar()`: Marks the car as rented.
     `returnCar()`: Marks the car as available.
     `isVintage()`: Returns `true` if the car's year is before 2000.
5. Create a few `Car` objects and test the methods.*/

#include <iostream>
using namespace std;

class Car {
    int carID;
    string model;
    int year;
    bool isRented;

    public:
    Car() {
        carID = 0;
        model = "";
        year = 0;
        isRented = false;
    }

    Car(int carID, string model, int year, bool isRented) {
        this->carID = carID;                
        this->model = model;            
        this->year =  year;            
        this->isRented = isRented;                
    }

    int getID() {
        return carID;
    }

    string getModel() {
        return model;
    }

    int getYear() {
        return year;
    }

    bool getRented() {
        return isRented;
    }

    void rentCar() {
        if(isRented == false){
            isRented = true;
            cout << "Rented successfully" << endl;
            return;
        }
        cout <<"Not available for rent" << endl;
    }


    void returnCar() {
        isRented = false;
        cout << "Returned successfully" << endl;
    }


    bool isVintage() {
        if (year < 2000)
            return true;
        return false;
    }
};


int main() {
    Car car1(998, "Cultus", 1999, false);
    Car car2(924, "Prius", 2023, true);
    Car car3(103, "Swift", 2012, false);

    cout << "vintage cars:  " << endl ;
    if (car1.isVintage()) {
        cout << car1.getID() << " is vintage" << endl;
    } 
    else {
        cout << car1.getID() << " is not vintage" << endl;
    }
    if (car2.isVintage()) {
        cout << car2.getID() << " is vintage" << endl;
    } 
    else {
        cout << car2.getID() << " is not vintage" << endl;
    }
    if (car3.isVintage()) {
        cout << car3.getID() << " is vintage" << endl;
    } 
    else {
        cout << car3.getID() << " is not vintage" << endl;
    }

    cout << endl;
    car1.rentCar();
    car2.rentCar();    
}
