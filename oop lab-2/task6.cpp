/*Task 6: You are tasked with implementing a simple Student Registration System in C++. Define two structures,
Register and Student, where Register contains attributes courseId and courseName, and Student inherits
from Register while having additional attributes such as studentId, firstName, lastName, cellNo, and
email. Your goal is to create an array of Student structures to store information for five students. Write a
C++ program that accomplishes the following tasks:

● Implement the Register and Student structures.

● Inherit the Register structure in the Student structure.

● Create an array of Student structures to store information for 5 students.

● Take input for each student, including their courseId, courseName, studentId, firstName,

lastName, cellNo, and email.

● Display the information for all 5 students.*/
#include <iostream>
using namespace std;
typedef struct {  
    int courseID;
    string courseName;
}Register;

typedef struct {  
    Register registerr;
    int studentId;
    string firstName; 
    string lastName;
    int cellNo;

    string email;
}Student;

int main() {
	Student stu[5];
	for (int i = 0; i < 5; i++) { 
	    cout <<  "Enter First Name of Student " << i << ": ";
	    cin >> stu[i].firstName;
	    cout <<  "Enter Last Name of Student " << i << ": ";
	    cin >> stu[i].lastName;
	    cout <<  "Enter ID of Student " << i << ": ";
	    cin >> stu[i].studentId; 
	    cout <<  "Enter Cell Number of Student " << i << ": ";
	    cin >> stu[i].cellNo;
	    cout <<  "Enter email of Student " << i << ": ";
	    cin >> stu[i].email; 
	    cout <<  "Enter Course ID for Student " << i << ": ";
	    cin >> stu[i].registerr.courseID;
	    cout <<  "Enter Course Name for Student " << i << ": ";
	    cin >> stu[i].registerr.courseName; 
	}
}