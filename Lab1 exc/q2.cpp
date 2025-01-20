/*Q2: Design a C++ program to manage student marks. Allow the user to input
marks for students in three subjects (Mathematics, English, and Science). The
program should calculate the total marks, average marks, and display the grade
for each student. The user can specify the number of students and then input
the marks for each subject for each student. Finally, display the marks, total,
average, and grade for each student. Assume a grading system with the
following criteria:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F*/

#include <iostream>
using namespace std;
int main() {
    int numStudents;
    cout << "enter number of students: ";
    cin >> numStudents;
    int mth, eng, scn, avg, total;
    for (int i = 1; i < numStudents + 1; i++)
    {
        cout << "enter marks for maths of student " << i << ": ";
        cin >> mth;
        cout << "enter marks for english of student " << i << ": ";
        cin >> eng;
        cout << "enter marks for science of student " << i << ": ";
        cin >> scn;

        cout << "\nResult of Student " << i << "\nMarks in Maths: " << mth << endl;
        cout << "Marks in English: " << eng << endl;
        cout << "Marks in Science: " << scn << endl;
        total = mth + eng + scn;
        cout << "Total Marks: " << total << endl;
        avg = total / 3;
        cout << "Average Marks: " << avg << endl;

        if (avg < 60)
            cout << "Grade F";
        else if (avg >= 60 && avg < 70)
            cout << "Grade D";
        else if (avg >= 70 && avg < 80)
            cout << "Grade C";
        else if (avg >= 80 && avg < 90)
            cout << "Grade B";
        else
            cout << "Grade A";

    }
}