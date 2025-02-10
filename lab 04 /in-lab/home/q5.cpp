/*TASK # 05
You are building an employee management system. Create a class `Employee` to manage employee
records.
1. Attributes:
     `employeeID` (int)
     `name` (string)
     `department` (string)
     `salary` (double)
2. Define a default constructor that initializes `salary` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
     `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
     `isManager()`: Returns `true` if the employee's department is "Management".
     `displayDetails()`: Displays the employee's details.
5. Create a few `Employee` objects and test the methods.*/

#include <iostream>
using namespace std;
#include <string>

class Employee {
    int employeeID;
    string name;
    string department;
    double salary;

    public:
    Employee() {
        salary = 0.0;
    }

    Employee(int eid, string n, string d, double sal) {
    employeeID = eid;
    name = n;
    department = d;
    salary = sal;
    }

    string getName() {
        return name;
    }

    void giveBonus(double amount) {
        salary = salary + amount;
        cout << "Bonus Amount Added" << endl;
    }

    bool isManager() {
        if (department == "Management") {
            return true;
        }
        return false;
    }

    void displayDetails() {
        cout << "Employee's Details: " << endl << "Employee's ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee emp1(101, "John Doe", "Management", 55000.0);
    Employee emp2(102, "Jane Smith", "Engineering", 45000.0);
    emp1.displayDetails();
    
    cout << endl;
    if (emp1.isManager()) {
        cout << emp1.getName() << " is a manager." << endl;
    } else {
        cout << emp1.getName() << " is not a manager." << endl;
    }

    cout << endl;
    if (emp2.isManager()) {
        cout << emp2.getName() << " is a manager." << endl;
    } else {
        cout << emp2.getName() << " is not a manager." << endl;
    }

    cout << endl;
    emp1.giveBonus(5000.0);
    cout << endl;
    emp1.displayDetails();
    cout << endl;
    emp2.displayDetails();
}
