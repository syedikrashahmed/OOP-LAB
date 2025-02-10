/*TASK # 01
You are building a student management system. Create a class `Student` to manage student records.
 Requirements:
1. Attributes: `studentID`, (int) `name`, (string) `age`, (int) `grade` (char)
2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `promoteStudent()`: Upgrades the student's grade (e.g., from 'A' to 'B').
 `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
 `displayDetails()`: Displays the student's details.
5. Create a few `Student` objects and test the methods.*/

#include <iostream>
using namespace std;

class Student {
    int studentID;
    string name;
    int age;
    char grade;

    public:
    Student(){
        grade = 'N';
    }

    Student(int sid, string n, int a, char g){
        studentID = sid;
        name = n;
        age = a;
        grade = g;
    }

    void promoteStudent() {
        if (grade > 65){
            grade--;
        }
    }

    bool isEligibleForScholarship() {
        bool flag = false;
        if (grade == 'A'){
            flag = true;
        }
        return flag;
    }

    void displayDetails() {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student s1(2240170, "Percy", 19, 'D');
    Student s2(2297039, "Kaz", 17, 'A');
    Student s3(2248348, "Pip", 19, 'A');
    
    cout << "Student 1 Details:" << endl;
    s1.displayDetails();
    cout << "\nStudent 2 Details:" << endl;
    s2.displayDetails();
    cout << "\nStudent 3 Details:" << endl;
    s3.displayDetails();
    
    cout << "\nPromoting Student 1..." << endl;
    s1.promoteStudent();
    s1.displayDetails();
    
    cout << "\nIs Student 1 eligible for scholarship? ";
    if (s1.isEligibleForScholarship()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
    cout << "\nIs Student 2 eligible for scholarship? ";
    if (s2.isEligibleForScholarship()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    cout << "\nIs Student 3 eligible for scholarship? ";
    if (s3.isEligibleForScholarship()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
