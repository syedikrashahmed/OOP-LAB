/*Question 01. */

#include <iostream>
using namespace std;
#include <string>

class Skill {
    int skillID;
    string name;
    string description;

    public:
    Skill();
    Skill(int sid, string n, string d);
    int getSkillID();
    void showSkillDetails() const;
    void updateSkillDescription(string newDescription);
};

Skill::Skill() {
    skillID = 0;
    name = "";
    description = "";
}

Skill::Skill(int sid, string n, string d) {
    skillID = sid;
    name = n;
    description = d;
}

int Skill::getSkillID() {
    return skillID;
}

void Skill::showSkillDetails() const { 
    cout << "Skill Details:\nSkill ID: " << skillID << "\nSkill Name: " << name << "\nDescription: " << description << endl << endl;
}

void Skill::updateSkillDescription(string newDescription) { 
    description = newDescription;
}

class Sport {
    int sportID;
    string name;
    string description;
    Skill *requiredSkills;

    public:
    Sport();
    Sport(int sid, string n, string d, int numSkill);
    string getName();
    void addSkill(const Skill &s);
    void  removeSkill(Skill s);
    ~Sport();
};

Sport::Sport() {
    description = "";
    name = "";
    sportID = 0;
    requiredSkills = nullptr;
}
   
Sport::Sport(int sid, string n, string d, int numSkill) {
    description = d;
    name = n;
    sportID = sid;
    requiredSkills = new Skill[numSkill];
}
    
string Sport::getName() {
    return name;
}

void Sport::addSkill(const Skill &s) {
    int skillCount = sizeof(requiredSkills) / sizeof(requiredSkills[0]);
    Skill *newSkillArr = new Skill[skillCount + 1];
    
    for (int i = 0; i < skillCount; i++) {
        newSkillArr[i] = requiredSkills[i];
    }
    newSkillArr[skillCount] = s;
    delete[] requiredSkills;
    requiredSkills = newSkillArr;

    cout << "Skill added successfully!" << endl << endl;
}

void  Sport::removeSkill(Skill s){
    int skillCount = sizeof(requiredSkills) / sizeof(requiredSkills[0]);
    int indexToRemove = -1;
    for (int i = 0; i <skillCount; i++) {
        if (requiredSkills[i].getSkillID() == s.getSkillID()) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        cout << "Skill Not Found" << endl << endl;
        return;
    }

    Skill *newSkillArr = new Skill[skillCount - 1];
    int j = 0;
    for (int i = 0; i < skillCount; i++) {
        if (i != indexToRemove) {
            newSkillArr[j] = requiredSkills[i];
            j++;
        }
    }

    delete[] requiredSkills;
    requiredSkills = newSkillArr;
    skillCount--;  

    cout << "Skill removed successfully!" << endl << endl;
}

Sport::~Sport() {
    if (requiredSkills) {
        delete[] requiredSkills;
        requiredSkills = nullptr; 
    }
}

class Mentor;  

class Student {
    int studentID;
    string name;
    int age; 
    Sport *sportsInterests;
    Mentor *mentorAssigned;

    public:
    Student();
    Student(int sid, string n, int a, Sport const *sports, int numSports);
    string getName();
    void registerForMentorship(Mentor &m);
    void viewMentorDetails() const;
    void updateSportsInterest(Sport s);
    ~Student();
};

class Mentor {
    int mentorID;
    string name; 
    Sport *sportsExpertise;
    int maxLearners;
    Student *assignedLearners;

    public:
    Mentor();
    Mentor(int mid, string n, int maxl, int numSports, Sport const *sports);
    int getMentorID();
    string getMentorName();
    int getMaxLearner();
    Sport* getSportsExpertise();
    Student* getassignedLearners();
    void assignLearner(const Student &s);
    void removeLearner(Student s);
    void viewLearners() const;
    void displaySportsExpertise() const;
    void provideGuidance();
    ~Mentor();
};

Mentor::Mentor() {
    mentorID = 0;
    name = "";
    maxLearners = 0;
    sportsExpertise = nullptr;
    assignedLearners = nullptr;
}

Mentor::Mentor(int mid, string n, int maxl, int numSports, Sport const *sports) {
    mentorID = mid;
    name = n;
    maxLearners = maxl;
    sportsExpertise = new Sport[numSports];
    for (int i = 0; i < numSports; i++) {
        sportsExpertise[i] = sports[i];
    }
    assignedLearners = new Student[maxLearners];
}

int Mentor::getMentorID() {
    return mentorID;
}

string Mentor::getMentorName() {
    return name;
}

int Mentor::getMaxLearner() {
    return maxLearners;
}

Sport* Mentor::getSportsExpertise() {
    return sportsExpertise;
}

Student* Mentor::getassignedLearners() {
    return assignedLearners;
}

void Mentor::viewLearners() const {
    cout << "Displaying Learners:" << endl << endl;
    for (int i = 0; i < maxLearners; i++) {
        cout << i << ") " << assignedLearners[i].getName() <<endl;
    }
}

void Mentor::displaySportsExpertise() const {
    cout << "\nDisplaying Sports Expertise:"<< endl;
    int numSports = sizeof(sportsExpertise) / sizeof(sportsExpertise[0]);
    for (int i = 0; i < numSports; i++) {
        cout << i << ") " << sportsExpertise[i].getName() <<endl;
    }
}

void Mentor::provideGuidance() {
    if (assignedLearners[0].getName() == "") {
        cout << "No Learners Assigned right now" << endl << endl;
        return;
    }
    cout << "Providing Guidance:" << endl ;
    for (int i = 0; i < maxLearners; i++) {
        if (assignedLearners[i].getName() != "") {
        cout << "Student Name: " << assignedLearners[i].getName() << endl;
        cout << "Keep practicing your skills daily!" << endl << endl;
        }
    }
}

Mentor::~Mentor() {
    delete []sportsExpertise;
    delete []assignedLearners;
}

Student::Student() {
        studentID = 0;
        name = "";
        age = 0;
        sportsInterests = nullptr;
        mentorAssigned = nullptr;
    }

Student::Student(int sid, string n, int a, Sport const *sports, int numSports) {
        studentID = sid;
        name = n;
        age = a;
        mentorAssigned = nullptr;
        sportsInterests = new Sport[numSports];
        for (int i = 0; i < numSports; i++) {
            sportsInterests[i] = sports[i];
        }
    }

string Student::getName() {
    return name;
}

void Student::registerForMentorship(Mentor &m) {
    mentorAssigned = &m;
}

void Student::viewMentorDetails() const {
    if (mentorAssigned == nullptr) {
        cout << "No Mentor Assigned" << endl << endl;
        return;
    }
    cout << "Mentor Details:\nMentor ID: " << mentorAssigned->getMentorID() << "\nName: " << mentorAssigned->getMentorName() << "\nSports Expertise: " << "\nMax Learners: " << mentorAssigned->getMaxLearner() << endl;
    mentorAssigned->displaySportsExpertise();
}

void Student::updateSportsInterest(Sport s) {
    int maxSportInterests = sizeof(sportsInterests) / sizeof(sportsInterests[0]);
    Sport *newArr = new Sport[maxSportInterests + 1];
    for (int i = 0; i < maxSportInterests; i++) {
        newArr[i] = sportsInterests[i];
    }
    sportsInterests[maxSportInterests] = s;
    cout << "Sport Interest Updated" << endl << endl;
}

Student::~Student() {
        delete[] sportsInterests;
}

void Mentor::assignLearner(const Student &s) {
    for (int i = 0; i < maxLearners; i++) {
        if (assignedLearners[i].getName() == "") {
            assignedLearners[i] = s;
            cout << "Learner Assigned" << endl << endl;
            return;
        }
    }

    cout << "Mentor has reached Maximum number of Learners" << endl << endl;
}

void Mentor::removeLearner(Student s) {
    for (int i = 0; i < maxLearners; i++) {
        if (assignedLearners[i].getName() == s.getName()) {
            int size = sizeof(assignedLearners) / sizeof(assignedLearners[0]);
            Student *newArr = new Student[size - 1];
            int z = 0;
            for (int j = 0; j < size - 1; j++) {
                if (assignedLearners[i].getName() != s.getName()) {
                    newArr[z] = assignedLearners[j];
                    z++;
                }
            }
            delete [] assignedLearners;
            assignedLearners = newArr;
            cout << "Mentor currently has no Learners" << endl << endl;
            return;
     }

    cout << "Mentor has reached Maximum number of Learners" << endl << endl;
    }
}

int main() {
    Skill dribbling(1, "Dribbling", "Ability to control the ball while running");
    Skill shooting(2, "Shooting", "Ability to accurately shoot the ball");
    
    Sport basketball(101, "Basketball", "A team sport involving shooting and dribbling", 2);
    basketball.addSkill(dribbling);
    basketball.addSkill(shooting);
    
    Mentor coach(1, "Coach John", 2, 1, &basketball);
    
    Student alice(201, "Alice", 18, &basketball, 1);
    Student bob(202, "Bob", 19, &basketball, 1);
    
    coach.assignLearner(alice);
    coach.assignLearner(bob);
    
    alice.registerForMentorship(coach);
    bob.registerForMentorship(coach);
    
    alice.viewMentorDetails();
    bob.viewMentorDetails();
    
    coach.provideGuidance();
    
    return 0;
}
