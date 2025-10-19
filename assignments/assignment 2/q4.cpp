/*Scenario # 4: 
A university has a Lab Management System used by undergraduate students. The system manages different types of users, such as Students, Teaching Assistants (TAs), and Professors. Students can access basic tools and complete assignments. TAs monitor students, assist in labs. Professors have full control of labs, assign projects, and manage research. 
PERMISSIONS: 
    STUDENT = submit assignment 
    TA = view projects, manage_students 
    PROFESSOR = assign projects , full_lab_access*/

#include <iostream> 
#include <string>
using namespace std;

void generateHash(string &password);

/* The User class: 
    • Has basic attributes like name, ID, list of permissions, email and hashed_password. 
    • A parameterized constructor to set the attributes and save passwords as hashed. 
    • An authenticate function which authenticates based on the correct password. 
    • Display function to display the information. 
    • A function access lab that checks the permissions of the user and provides access to the lab if allowed. */

class User {
    protected:
    string name;
    string id;
    string *list_of_permissions;
    int num_permissions;
    string email;
    string hashed_password;

    public:
    User() : name(""), id(""), list_of_permissions(nullptr), num_permissions(0), email(""), hashed_password("") {}

    User(string name, string id, string *list_of_permissions, int num_permissions, string email, string password)
        : name(name), id(id), num_permissions(num_permissions), email(email) {
        this->list_of_permissions = new string[num_permissions];
        for (int i = 0; i < num_permissions; i++) {
            this->list_of_permissions[i] = list_of_permissions[i];
        }
        generateHash(password);
        this->hashed_password = password;
    }

    string getName() const {
        return name;
    }

    bool authenticate(string password) {
        generateHash(password);
        if (password == hashed_password) {
            cout << "correct password " << endl;
            return true;
        }
        else {
            cout << "incorrect password " << endl;
            return false;
        }
    }

    virtual void display() {
        cout << "User Details: \nName: " << name << "\nID: " << id << "\nEmail: " << email << "\nPermissions:\n";
        for (int i = 0; i < num_permissions; i++) {
            cout << i+1 << ") " << list_of_permissions[i] << endl;
        }
    }

    bool accessLab() {
        for (int i=0; i<num_permissions; i++) {
            if (list_of_permissions[i] == "full_lab_access") {
                cout << "lab access given" << endl;
                return 1;
            }
        }
        cout << "not allowed to access lab" << endl;
        return 0;
    }

    virtual ~User() {
        delete[] list_of_permissions;
    }  
};

/* The Student class: 
    • Derived from the user class 
    • Override the display function 
    • Has a list of assignments where each index represents 1 assignment. If the assignment is submitted by the student update the status to 1 or else leave it at 0. 
    • Has a functionality where students can be given assignments and their status can be updated after submission.*/

class Student : virtual public User {
    protected:
    int *assignments;
    int num_assignments;

    public:
    Student() : User(), assignments(nullptr), num_assignments(0) {}

    Student(string name, string id, string *list_of_permissions, int num_permissions, string email, string hashed_password, int *assignments, int num) : User(name, id, list_of_permissions, num_permissions, email, hashed_password), num_assignments(num) {
        this->assignments = new int[num_assignments];
        for (int i = 0; i < num_assignments; i++) {
            this->assignments[i] = assignments[i];
        }
    }

    void display() override {
        User::display();
        cout << "Assignments List: " <<endl;
        for (int i = 0; i < num_assignments; i++) {
            cout << "Assignment " << i + 1 << ": ";
            if (assignments[i] == 1) { cout << "Submitted" <<endl; }
            else {cout << "Not Submitted" <<endl; }
        }
    }

    void submitAssignment(int index) {
        if (index < 0 || index >= num_assignments) {
            cout << "Invalid Index" << endl;
            return;
        }
        else {
            if (assignments[index] == 1) {
                cout << "Assignment Already Submitted" << endl;
            }
            else {
                assignments[index] = 1;
                cout << "Assignment Submitted" << endl;
            }
        }
    }

    void addAssignment() {
        int *newass = new int[num_assignments + 1];
        for (int i = 0; i < num_assignments; i++) {
            newass[i] = assignments[i];
        }
        newass[num_assignments] = 0;
        delete assignments;
        assignments = newass;
        num_assignments++;
        cout << "Assignment Added" << endl;
    }

    ~Student() {
        delete [] assignments;
    }
};

/* The TA class: 
    • Derived from the Student class 
    • Override the display function 
    • Has a List of Students that are assigned to it. 
    • Has a List of projects that they are working on with the professor (MAX = 2) and provides functionality to view the current projects or start working on a new project if the limit is not exceeded. 
    • Has a functionality where the permission is checked and then students can be assigned to the TA. Each TA can manage only up to 10 students. The TA cannot be assigned more than 10 at any time.*/

class TA : public Student {
    Student *students_assigned;
    int num_students_assigned;
    string *projects_assigned;
    int num_projects_assigned;

    public:
    TA() : num_students_assigned(0), num_projects_assigned(0), students_assigned(nullptr), projects_assigned(nullptr), Student(), User() {}

    TA(string name, string id, string *list_of_permissions, int num_permissions, string email, string hashed_password, int *assignments, int num, Student *students_assigned, int num_students_assigned, string *projects_assigned, int num_projects_assigned) : Student(name, id, list_of_permissions, num_permissions, email, hashed_password, assignments, num), num_students_assigned(num_students_assigned), num_projects_assigned(num_projects_assigned), User(name, id, list_of_permissions, num_permissions, email, hashed_password) {
        while (num_projects_assigned < 0 || num_projects_assigned > 2) {
            cout << "Number Of Projects Assigned should not exceed 2: ";
            cin >> num_projects_assigned;
        }
        this->num_students_assigned = num_students_assigned;
        this->students_assigned = new Student[num_students_assigned];
        for (int i = 0; i < num_students_assigned; i++) {
            this->students_assigned[i] = students_assigned[i];
        }

        while (num_students_assigned < 0 || num_students_assigned > 10) {
            cout << "Number Of Students Assigned should not exceed 2: ";
            cin >> num_students_assigned;
        }
        this->num_projects_assigned = num_projects_assigned;
        this->projects_assigned = new string[num_projects_assigned];
        for (int i = 0; i < num_projects_assigned; i++) {
            this->projects_assigned[i] = projects_assigned[i];
        }
    }

    void viewProjects() {
        cout << "Projects Assigned: " <<endl;
        for (int i = 0; i < num_projects_assigned; i++) {
            cout << i + 1 << ") " << projects_assigned[i] << endl;
        }
    }

    // void startWorkOnProject() {}

    void display() override {
        // Student::display();
        cout << "User Details: \nName: " << name << "\nID: " << id << "\nEmail: " << email << "\nPermissions:\n";
        for (int i = 0; i < num_permissions; i++) {
            cout << i+1 << ") " << list_of_permissions[i] << endl;
        }
        cout << "Assignments List: " <<endl;
        for (int i = 0; i < num_assignments; i++) {
            cout << "Assignment " << i + 1 << ": ";
            if (assignments[i] == 1) { cout << "Submitted" <<endl; }
            else {cout << "Not Submitted" <<endl; }
        }
        viewProjects();
        cout << "Students Assigned: " <<endl;
        for (int i = 0; i < num_students_assigned; i++) {
            cout << i + 1 << ") "; students_assigned[i].display();
        }
    }

    bool assignNewProject(string project) {
        if (num_projects_assigned == 2) {
            cout << "cannot add new project" << endl;
            return false;
        }
        string* newProjects = new string[num_projects_assigned+1];
        for (int i =0; i<num_projects_assigned; i++) {
            newProjects[i] = projects_assigned[i];
        }
        newProjects[num_projects_assigned] = project;
        num_projects_assigned++;
        delete[] projects_assigned;
        projects_assigned = newProjects;
        cout << "new project assigned successfully" << endl;
        return true;
    }

    void assignNewStudent(Student &student) {
        if (num_students_assigned == 10) {
            cout << "cannot assign more students to ta " << name << endl; 
            return;
        }
        Student *newStudents = new Student[num_students_assigned + 1];
        for (int i=0; i<num_students_assigned; i++) {
            newStudents[i] = students_assigned[i];
        }
        newStudents[num_students_assigned] = student;
        num_students_assigned++;
        delete[] students_assigned;
        students_assigned = newStudents;    
    }

    ~TA() {
        delete[] students_assigned;
        delete[] projects_assigned;
    }
};

/*The Professor class: 
    • Derived from the user class 
    • Override the display function 
    • Has a functionality that allows professors to work with TA’s on projects. At any one time each TA can only work on 2 projects. 
Create objects of all the classes. Call the display function and authenticate function as needed. */

class Professor : public User {
    TA *tas;
    int num_TAs;
    public:
    Professor() : User(), tas(nullptr), num_TAs(0) {}

    Professor(string name, string id, string *list_of_permissions, int num_permissions, string email, string hashed_password, TA *tas, int num_TAs) : User(name, id, list_of_permissions, num_permissions, email, hashed_password), num_TAs(num_TAs) {
        this->tas = new TA[num_TAs];
        for (int i = 0; i < num_TAs; i++) {
            this->tas[i] = tas[i];
        }
    }

    void display() override {
        User::display();
        cout << "TAs working with Professor: " <<endl;
        for (int i = 0; i < num_TAs; i++) {
            cout << i + 1 << ") ";
            tas[i].display();
        }
    }

    void workWithTA(TA &ta, string projectName) {
        bool found = false;
        for (int i = 0; i < num_TAs; i++) {
            if (ta.getName() == tas[i].getName()) {
                found = true;
                if (ta.assignNewProject(projectName)) {
                    cout << "Assigned New Project to TA " << ta.getName() << endl;
                    return;
                }
                cout << "TA can not be assigned more assignments" << endl;
                break;
            }
        }

        if (!found) {
            //add TA to array thing
            TA *newtas = new TA[num_TAs + 1];
            for (int i = 0; i < num_TAs; i++) {
                newtas[i] = tas[i];
            }
            newtas[num_TAs + 1] = ta;
            cout << "Assigned New Project to TA " << ta.getName() << endl;
            delete tas;
            tas = newtas;
            num_TAs++;
        }
    }

    ~Professor() {
        delete[] tas;
    }
};

/*Create a global function that generates the hashes of the password. Use the value given to calculate the hash. [ hash = 5381], Then use the following formula to calculate the hash  [ hash * 33 + c ] where “c” represents a single character. 
Create a global function authenticateAndPerformAction(User* user, string action) that performs the functionality based on the User roles and their permissions.*/

void generateHash(string &password) {
    int size = password.length();
    int hash = 5381; 
    for (int i = 0; i < size; i++) {
        char c = password.at(i);
        hash = hash * 33 + static_cast<int>(c); 
    }
    password = to_string(hash); 
}

void authenticateAndPerformAction(User* user, string action) {
    // Authenticate the user
    string password;
    cout << "Enter password for user " << user->getName() << ": ";
    cin >> password;

    if (!user->authenticate(password)) {
        cout << "Authentication failed. Access denied." << endl;
        return;
    }

    // Perform action based on user role and permissions
    if (action == "submit_assignment") {
        // Check if the user is a Student
        Student* student = dynamic_cast<Student*>(user);
        if (student) {
            int assignmentNumber;
            cout << "Enter assignment number to submit: ";
            cin >> assignmentNumber;
            student->submitAssignment(assignmentNumber - 1); // Convert to 0-based index
        } else {
            cout << "Action 'submit_assignment' failed. Only Students can perform this action." << endl;
        }
    } else if (action == "view_projects") {
        // Check if the user is a TA
        TA* ta = dynamic_cast<TA*>(user);
        if (ta) {
            ta->viewProjects();
        } else {
            cout << "Action 'view_projects' failed. Only TAs can perform this action." << endl;
        }
    } else if (action == "assign_project") {
        // Check if the user is a Professor
        Professor* professor = dynamic_cast<Professor*>(user);
        if (professor) {
            string projectName;
            cout << "Enter project name to assign: ";
            cin >> projectName;

            // Create a dummy TA for demonstration
            TA* ta = new TA();
            professor->workWithTA(*ta, projectName);
        } else {
            cout << "Action 'assign_project' failed. Only Professors can perform this action." << endl;
        }
    } else if (action == "access_lab") {
        // Check if the user has lab access
        if (user->accessLab()) {
            cout << "Action 'access_lab' performed successfully." << endl;
        } else {
            cout << "Action 'access_lab' failed. Insufficient permissions." << endl;
        }
    } else {
        cout << "Unknown action. No action performed." << endl;
    }
}
int main() {
    // Create permissions
    string studentPermissions[] = {"submit_assignment"};
    string taPermissions[] = {"view_projects", "manage_students"};
    string professorPermissions[] = {"assign_project", "full_lab_access"};

    // Create assignments for Student
    int studentAssignments[] = {0, 0}; // 0 = not submitted, 1 = submitted

    // Create a Student object
    Student student("Alice", "S123", studentPermissions, 1, "alice@example.com", "password123", studentAssignments, 2);

    // Create a TA object
    TA ta("Bob", "T456", taPermissions, 2, "bob@example.com", "password456", nullptr, 0, nullptr, 0, nullptr, 0);

    // Create a Professor object
    TA* taArray = new TA[1]{ta};
    Professor professor("Dr. Smith", "P789", professorPermissions, 2, "smith@example.com", "password789", taArray, 1);

    // Display objects
    cout << "Displaying Student:" << endl;
    student.display();
    cout << endl;

    cout << "Displaying TA:" << endl;
    ta.display();
    cout << endl;

    cout << "Displaying Professor:" << endl;
    professor.display();
    cout << endl;

    // Perform actions using authenticateAndPerformAction
    cout << "\nPerforming actions:" << endl;

    // Student submits an assignment
    authenticateAndPerformAction(&student, "submit_assignment");
    cout << endl;

    // TA views projects
    authenticateAndPerformAction(&ta, "view_projects");
    cout << endl;

    // Professor assigns a project
    authenticateAndPerformAction(&professor, "assign_project");
    cout << endl;

    // Professor accesses the lab
    authenticateAndPerformAction(&professor, "access_lab");
    cout << endl;

    // Clean up
    delete[] taArray;
    return 0;
}
