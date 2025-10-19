#include <iostream>
#include <string>
using namespace std;

class User {
    int age;
    string licenseType;
    int contactNumber;
    int userID;
    bool isRegistered;

public:
    User() {
        age = 0;
        licenseType = "";
        contactNumber = 0;
        userID = 0;
        isRegistered = false;
    }

    int getID() {
        return userID;
    }

    void registerUser(int a, string license, int cNum, int uid) {
        age = a;
        licenseType = license;
        contactNumber = cNum;
        userID = uid;
        isRegistered = true;
    }

    void update(int a, string license, int cNum) {
        age = a;
        licenseType = license;
        contactNumber = cNum;
    }

    string getLicenseType() {
        return licenseType;
    }
};

class Vehicle {
    int vehicleID;
    string model;
    float rentPerDay;
    int rentorID;
    string eligibility;
    bool available;

public:
    Vehicle() {
        vehicleID = 0;
        model = "";
        rentPerDay = 0.0;
        rentorID = 0;
        eligibility = "";
        available = true;
    }

    int getID() {
        return vehicleID;
    }

    void add(int vid, string model, float rent, string eligibility) {
        vehicleID = vid;
        this->model = model;
        rentPerDay = rent;
        this->eligibility = eligibility;
        available = true;
    }

    void update(string model, float rent, string eligibility) {
        this->model = model;
        rentPerDay = rent;
        this->eligibility = eligibility;
    }

    void rent(int rentor) {
        if (available) {
            available = false;
            rentorID = rentor;
            cout << "Vehicle rented successfully" << endl;
        } else {
            cout << "Vehicle already rented" << endl;
        }
    }

    void returnVehicle() {
        if (!available) {
            available = true;
            rentorID = 0;
            cout << "Vehicle returned successfully" << endl;
        } else {
            cout << "Vehicle already available" << endl;
        }
    }

    void display() {
        cout << "Model: " << model << endl
             << "Rent Per Day: " << rentPerDay << endl
             << "Eligibility: " << eligibility << endl
             << "Available: ";
        if (available)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    string getEligibility() {
        return eligibility;
    }
};

class System {
    User **users;
    int numOfUsers;
    Vehicle **vehicles;
    int numOfVehicles;

public:
    System() {
        users = nullptr;
        numOfUsers = 0;
        numOfVehicles = 0;
        vehicles = nullptr;
    }

    void addUser() {
        int age, contactNumber, userID;
        string licenseType;
        cout << "Enter User ID: ";
        cin >> userID;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Contact Number: ";
        cin >> contactNumber;
        cout << "Enter License Type: ";
        cin >> licenseType;

        User **newArr = new User *[numOfUsers + 1];
        for (int i = 0; i < numOfUsers; i++) {
            newArr[i] = users[i];
        }
        newArr[numOfUsers] = new User(); 
        newArr[numOfUsers]->registerUser(age, licenseType, contactNumber, userID);
        delete[] users;
        users = newArr;
        numOfUsers++;
        cout << "User Added Successfully" << endl;
    }

    void updateUser(int userId) {
        for (int i = 0; i < numOfUsers; i++) {
            if (userId == users[i]->getID()) {
                int age, contactNumber;
                string licenseType;
                cout << "Enter New Age: ";
                cin >> age;
                cout << "Enter New Contact Number: ";
                cin >> contactNumber;
                cout << "Enter New License Type: ";
                cin >> licenseType;
                users[i]->update(age, licenseType, contactNumber);
                cout << "User Updated Successfully" << endl;
                return;
            }
        }
        cout << "User Not Found" << endl;
    }

    void deleteUser(int userId) {
        for (int i = 0; i < numOfUsers; i++) {
            if (userId == users[i]->getID()) {
                delete users[i]; 
                User **newArr = new User *[numOfUsers - 1];
                int j = 0;
                for (int z = 0; z < numOfUsers; z++) {
                    if (users[z]->getID() != userId) {
                        newArr[j] = users[z];
                        j++;
                    }
                }
                delete[] users;
                users = newArr;
                numOfUsers--;
                cout << "User Removed Successfully" << endl;
                return;
            }
        }
        cout << "User Not Found" << endl;
    }

    void addVehicle() {
        int vehicleID;
        string model;
        float rentPerDay;
        string eligibility;
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Rent Per Day: ";
        cin >> rentPerDay;
        cout << "Enter Eligibility: ";
        cin >> eligibility;

        Vehicle **newArr = new Vehicle *[numOfVehicles + 1];
        for (int i = 0; i < numOfVehicles; i++) {
            newArr[i] = vehicles[i];
        }
        newArr[numOfVehicles] = new Vehicle(); 
        newArr[numOfVehicles]->add(vehicleID, model, rentPerDay, eligibility);
        delete[] vehicles;
        vehicles = newArr;
        numOfVehicles++;
        cout << "Vehicle Added Successfully" << endl;
    }

    void updateVehicle(int vehicleID) {
        for (int i = 0; i < numOfVehicles; i++) {
            if (vehicleID == vehicles[i]->getID()) {
                string model;
                float rentPerDay;
                string eligibility;
                cout << "Enter Model: ";
                cin >> model;
                cout << "Enter Rent Per Day: ";
                cin >> rentPerDay;
                cout << "Enter Eligibility: ";
                cin >> eligibility;
                vehicles[i]->update(model, rentPerDay, eligibility);
                cout << "Vehicle Updated Successfully" << endl;
                return;
            }
        }
        cout << "Vehicle Not Found" << endl;
    }

    void rentVehicle(int vehicleID) {
        for (int i = 0; i < numOfVehicles; i++) {
            if (vehicleID == vehicles[i]->getID()) {
                int rentor;
                cout << "User Id of rentor: ";
                cin >> rentor;
                vehicles[i]->rent(rentor);
                return;
            }
        }
        cout << "Vehicle Not Found" << endl;
    }

    void returnVehicle(int vehicleID) {
        for (int i = 0; i < numOfVehicles; i++) {
            if (vehicleID == vehicles[i]->getID()) {
                vehicles[i]->returnVehicle();
                return;
            }
        }
        cout << "Vehicle Not Found" << endl;
    }

    void deleteVehicle(int vehicleID) {
        for (int i = 0; i < numOfVehicles; i++) {
            if (vehicleID == vehicles[i]->getID()) {
                delete vehicles[i]; 
                Vehicle **newArr = new Vehicle *[numOfVehicles - 1];
                int j = 0;
                for (int z = 0; z < numOfVehicles; z++) {
                    if (vehicles[z]->getID() != vehicleID) {
                        newArr[j] = vehicles[z];
                        j++;
                    }
                }
                delete[] vehicles;
                vehicles = newArr;
                numOfVehicles--;
                cout << "Vehicle Removed Successfully" << endl;
                return;
            }
        }
        cout << "Vehicle Not Found" << endl;
    }

    void displayAll() const {
        for (int i = 0; i < numOfVehicles; i++) {
            vehicles[i]->display();
        }
    }

    ~System() {
        for (int i = 0; i < numOfUsers; i++) {
            delete users[i];
        }
        delete[] users;
        for (int i = 0; i < numOfVehicles; i++) {
            delete vehicles[i];
        }
        delete[] vehicles;
    }
};

int main() {
    int choice, user;
    System carRental;
    while (1) {
        cout << "\nVehicle Rental Menu:\nPress 1 to register a User\nPress 2 to update a User\nPress 3 to remove a User\nPress 4 to add a Vehicle\nPress 5 to update a Vehicle\nPress 6 to remove a Vehicle\nPress 7 to rent a Vehicle\nPress 8 to return a Vehicle\nPress 9 to display all vehicles\nPress 0 to exit menu\nchoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                carRental.addUser();
                break;

            case 2:
                cout << "enter user id to update: ";
                cin >> user;
                carRental.updateUser(user);
                break;

            case 3:
                cout << "enter user id to delete: ";
                cin >> user;
                carRental.deleteUser(user);
                break;

            case 4:
                carRental.addVehicle();
                break;

            case 5:
                cout << "enter vehicle id to update: ";
                cin >> user;
                carRental.updateVehicle(user);
                break;

            case 6:
                cout << "enter vehicle id to delete: ";
                cin >> user;
                carRental.deleteVehicle(user);
                break;

            case 7:
                cout << "enter vehicle id to rent: ";
                cin >> user;
                carRental.rentVehicle(user);
                break;

            case 8:
                cout << "enter vehicle id to return: ";
                cin >> user;
                carRental.returnVehicle(user);
                break;

            case 9:
                carRental.displayAll();
                break;

            case 0:
                cout << "Exiting system";
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
