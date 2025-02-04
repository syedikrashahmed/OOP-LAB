/*Task 4: In ocean navigation, locations are measured in degrees and minutes of latitude and longitude. Thus if you’re lying off the mouth of Papeete Harbor in Tahiti, your location is 149 degrees 34.8 minutes west longitude, and 17 degrees 31.5 minutes south latitude. This is written as 149°34.8’ W, 17°31.5’ S. There are 60 minutes in a degree. (An older system also divided a minute into 60 seconds, but the modern approach is to use decimal minutes instead.) Longitude is measured from 0 to 180 degrees, east or west from Greenwich, England, to the international dateline in the Pacific. Latitude is measured from 0 to 90 degrees, north or south from the equator to the poles.Create a class angle that includes three member variables: an int for degrees, a float for minutes, and a char for the direction letter (N, S, E, or W). This class can hold either a latitude variable or a longitude variable. Write one member function to obtain an angle value (in degrees and minutes) and a direction from the user, and a second to display the angle value in 179°59.9’ E format. Also write a three-argument constructor.
Write a main() program that displays an angle initialized with the constructor, and then, within a loop, allows the user to input any angle value, and then displays the value. You can use the hex character constant ‘\xF8’, which usually prints a degree (°) symbol.*/

#include <iostream>
#include <iomanip>

using namespace std;

class Angle {
    int degree;
    float minutes;
    char direction;

    public:
    Angle(int deg, float min, char dir) {
        degree = deg; 
        minutes = min;
        direction = dir;
    }

    void obtainAngle(int deg, float min, char dir) {
        degree = deg; 
        minutes = min;
        direction = dir;
    }

    void display() {
        cout << degree << '\xF8' << fixed << setprecision(1) << minutes << "'" << " " << direction << endl;
    }
};

int main() {
    int degree;
    float minutes;
    char direction;
    Angle ang(164, 42.1, 'N');
    ang.display();
    int choice;
    do {
        
        cout << "enter degrees of latitude or longitude: ";
        cin >> degree;
        cout << "enter minutes of latitude or longitude: ";
        cin >> minutes;
        cout << "enter direction of latitude or longitude: ";
        cin >> direction;
        ang.obtainAngle(degree, minutes, direction);
        ang.display();
        cout << "enter 1 if you want to input more angle value: ";
        cin >> choice;
    }while (choice == 1);

}
