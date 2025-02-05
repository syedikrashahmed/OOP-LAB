/*Task 5:
Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that stores information about the current year. The user is allowed to store their tasks to do against each day. Assume only one entry is needed per day.
Create the following methods for your class:  Add a task. This function accepts three parameters: task details, date and month. It should add a task on the day specified.  Remove a task. Accepts the date and month as a parameter to remove the task from.  Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how you’ll remove a task, and display the updated task list.
*/

#include <iostream>
using namespace std;

class Calendar {
    string january[31];
    string february[28];
    string march[31];
    string april[30];
    string may[31];
    string june[30];
    string july[31];
    string august[31];
    string september[30];
    string october[31];
    string november[30];
    string december[31];
    int year = 2025;

    public:
    Calendar() {
        for (int i = 0; i < 31; i++) {
            january[i] = "";
        }
        for (int i = 0; i < 28; i++) {
            february[i] = "";
        }
        for (int i = 0; i < 31; i++) {
            march[i] = "";
        }
        for (int i = 0; i < 30; i++) {
            april[i] = "";
        }
        for (int i = 0; i < 31; i++) {
            may[i] = "";
        }
        for (int i = 0; i < 30; i++) {
            june[i] = "";
        }
        for (int i = 0; i < 31; i++) {
            july[i] = "";
        }
        for (int i = 0; i < 31; i++) {
            august[i] = "";
        }
        for (int i = 0; i < 30; i++) {
            september[i] = "";
        }
        for (int i = 0; i < 31; i++) {
            october[i] = "";
        }
        for (int i = 0; i < 30; i++) {
            november[i] = "";
        }
        for (int i = 0; i < 31; i++) {
            december[i] = "";
        }
    }

    void addTask(string task, int date, int month) {
        switch(month) {
            case 1: january[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 2: february[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 3: march[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 4: april[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 5: may[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 6: june[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 7: july[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 8: august[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 9: september[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 10: october[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 11: november[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            case 12: december[date - 1] = task;
            cout << "task added successfully" << endl;
            break;
            default:
            cout << "Invalid Month!" << endl;
        }
    }

    void removeTask(int date, int month) {
        switch(month) {
            case 1: january[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 2: february[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 3: march[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 4: april[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 5: may[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 6: june[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 7: july[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 8: august[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 9: september[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 10: october[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 11: november[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            case 12: december[date - 1] = " ";
            cout << "task removed successfully" << endl;
            break;
            default:
            cout << "Invalid Month!" << endl;
        }
    }

    void showTasks() {
        cout << "Displaying All Tasks" << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "January " << i << ": ";
            if (january[i] != "") {
                cout << january[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "February " << i << ": ";
            if (january[i] != "") {
                cout << february[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "March " << i << ": ";
            if (january[i] != "") {
                cout << march[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "April " << i << ": ";
            if (january[i] != "") {
                cout << april[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "May " << i << ": ";
            if (january[i] != "") {
                cout << may[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "June " << i << ": ";
            if (january[i] != "") {
                cout << june[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "July " << i << ": ";
            if (january[i] != "") {
                cout << july[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "August " << i << ": ";
            if (january[i] != "") {
                cout << august[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "September " << i << ": ";
            if (january[i] != "") {
                cout << september[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "October " << i << ": ";
            if (january[i] != "") {
                cout << october[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "November " << i << ": ";
            if (january[i] != "") {
                cout << november[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
        for (int i = 1; i <= 31; i++) {
            cout << "December " << i << ": ";
            if (january[i] != "") {
                cout << december[i] << endl;
            }
            else
                cout << "no task" << endl;
        }
        cout << endl;
    }
};

int main() {
    Calendar cal;
    cal.addTask("calculus exam", 5, 1);
    cal.addTask("cleaning", 5, 2);
    cal.addTask("cook food", 20, 11);
    cal.addTask("organise house", 22, 3);
    cal.addTask("project deadline", 8, 6);
    cal.addTask("new semester", 19, 8);
    cal.showTasks();
    cal.removeTask(5, 2);
    cal.showTasks();
}