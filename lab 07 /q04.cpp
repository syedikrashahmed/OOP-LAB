#include <iostream>
#include <string>
using namespace std;

class Course;

class Person {
protected:
    string name, id, address, email;
    int phoneNumber;

public:
    Person(string name, string id, string address, string email, int phoneNumber) {
        this->name = name;
        this->id = id;
        this->address = address;
        this->email = email;
        this->phoneNumber = phoneNumber;
    }

    Person() {
        name = "";
        id = "";
        address = "";
        email = "";
        phoneNumber = 0;
    }

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Email: " << email << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }

    string getName() {
        return name;
    }

    void updateInfo() {
        int choice;
        do {
            cout << "1. Update Name" << endl;
            cout << "2. Update ID" << endl;
            cout << "3. Update Address" << endl;
            cout << "4. Update Email" << endl;
            cout << "5. Update Phone Number" << endl;
            cout << "6. Exit" << endl;
            cin >> choice;
        } while (choice != 6);
    }
};

class Student : public Person {
    Course **coursesEnrolled; 
    float gpa;
    int enrollmentYear, numCoursesEnrolled;

public:
    Student(string name, string id, string address, string email, int phoneNumber, float gpa, int enrollmentYear, int numCoursesEnrolled, Course **coursesEnrolled)
        : Person(name, id, address, email, phoneNumber) {
        this->coursesEnrolled = new Course*[numCoursesEnrolled];
        for (int i = 0; i < numCoursesEnrolled; i++) {
            this->coursesEnrolled[i] = coursesEnrolled[i];
        }
        this->gpa = gpa;
        this->enrollmentYear = enrollmentYear;
        this->numCoursesEnrolled = numCoursesEnrolled;
    }

    Student() : Person() {
        coursesEnrolled = nullptr;
        gpa = 0;
        enrollmentYear = 0;
        numCoursesEnrolled = 0;
    }

    float getGPA() {
        return gpa;
    }

    void setGPA(float gpa) {
        this->gpa = gpa;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << gpa << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "Number of Courses Enrolled: " << numCoursesEnrolled << endl;
    }
};

class Professor : public Person {
    string department;
    Course **coursesTaught; 
    float salary;
    int numCoursesTaught;

public:
    Professor(string name, string id, string address, string email, int phoneNumber, string department, float salary, Course **coursesTaught, int numCoursesTaught)
        : Person(name, id, address, email, phoneNumber) {
        this->coursesTaught = new Course*[numCoursesTaught];
        for (int i = 0; i < numCoursesTaught; i++) {
            this->coursesTaught[i] = coursesTaught[i];
        }
        this->department = department;
        this->salary = salary;
        this->numCoursesTaught = numCoursesTaught;
    }

    Professor() : Person() {
        coursesTaught = nullptr;
        department = "";
        salary = 0;
        numCoursesTaught = 0;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Number of Courses Taught: " << numCoursesTaught << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course {
    string courseID, name, schedule;
    Professor instructor;
    int credits;
    Student **studentsEnrolled; 
    int numStudentsEnrolled;

public:
    Course(string courseID, string name, string schedule, Professor instructor, int credits, Student **studentsEnrolled, int numStudentsEnrolled) {
        this->courseID = courseID;
        this->name = name;
        this->schedule = schedule;
        this->instructor = instructor;
        this->credits = credits;
        this->studentsEnrolled = studentsEnrolled;
        this->numStudentsEnrolled = numStudentsEnrolled;
    }

    Course() {
        courseID = "";
        name = "";
        schedule = "";
        instructor = Professor();
        credits = 0;
        studentsEnrolled = nullptr;
        numStudentsEnrolled = 0;
    }

    ~Course() {
        delete[] studentsEnrolled;
    }

    void registerStudent(Student *s) {
        Student **newStudentsEnrolled = new Student*[numStudentsEnrolled + 1];
        for (int i = 0; i < numStudentsEnrolled; i++) {
            newStudentsEnrolled[i] = studentsEnrolled[i];
        }
        newStudentsEnrolled[numStudentsEnrolled] = s;
        delete[] studentsEnrolled;
        studentsEnrolled = newStudentsEnrolled;
        numStudentsEnrolled++;
    }

    void calculateGrades() {
        for (int i = 0; i < numStudentsEnrolled; i++) {
            int marks;
            cout << "Enter the marks for " << studentsEnrolled[i]->getName() << ": ";
            cin >> marks;
            if (marks >= 90 && marks <= 100) {
                studentsEnrolled[i]->setGPA(4);
            } else if (marks >= 80 && marks <= 89) {
                studentsEnrolled[i]->setGPA(3);
            } else if (marks >= 70 && marks <= 79) {
                studentsEnrolled[i]->setGPA(2);
            } else if (marks >= 60 && marks <= 69) {
                studentsEnrolled[i]->setGPA(1);
            } else {
                studentsEnrolled[i]->setGPA(0);
            }
        }
    }
};

class Staff : public Person {
    string department;
    string position;
    float salary;

public:
    Staff(string name, string id, string address, string email, int phoneNumber, string department, string position, float salary)
        : Person(name, id, address, email, phoneNumber) {
        this->department = department;
        this->position = position;
        this->salary = salary;
    }

    Staff() : Person() {
        department = "";
        position = "";
        salary = 0;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Professor prof("Prof. Chiron", "1234567890", "Camp Half-Blood", "chiron@gmail.com", 1234567890, "Greek Mythology", 100000, nullptr, 0);
    Course c("GM101", "Introduction to Computer Science", "10-11am", prof, 3, nullptr, 0);
    Student s("Annabeth Chase", "1234567890", "Washington", "wise.girl@gmail.com", 1234567890, 0, 2024, 0, nullptr);
    c.registerStudent(&s);
    s.displayInfo();
    cout << endl;
    c.calculateGrades();
    s.displayInfo();
}
