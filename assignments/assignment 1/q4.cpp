/*FAST’s transportation system currently has a troublesome process for student registration, semester payments, and to verify it manually on points. They want you to automate the entire process to streamline the system. The system should
    • Allow students to register for the transportation service.
    • Enable students to pay semester fees to keep their transportation cards active.
    • Manage routes, including pick-up and drop-off stops for students.
    • Record attendance automatically when students tap their cards on the bus.
    • Manage bus routes with stops and assign students to appropriate stops.
Identify the required classes, their data members, and member functions. Then, create a class diagram to represent the system. Based on your class diagram, write a C++ program to implement the system.*/

#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    string studentID;
    string email;
    int contactNumber;

public:
    Student() {
        name = "";
        studentID = "";
        email = "";
        contactNumber = 0;
    }

    Student(string n, string sid, string e, int num) {
        name = n;
        studentID = sid;
        email = e;
        contactNumber = num;
    }

    string getName() { return name; }
    string getID() { return studentID; }
    string getEmail() { return email; }
    int getContact() { return contactNumber; }

    void update() {
        cout << "Updating Student Information:" << endl;
        int choice;
        string userStr;
        int userNum;
        while (true) {
            cout << "Press 1 to update name\nPress 2 to update student ID\nPress 3 to update email\nPress 4 to update contact Number\nPress 5 to stop update\nchoice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin >> userStr;
                    name = userStr;
                    break;
                case 2:
                    cout << "Enter new student ID: ";
                    cin >> userStr;
                    studentID = userStr;
                    break;
                case 3:
                    cout << "Enter new email: ";
                    cin >> userStr;
                    email = userStr;
                    break;
                case 4:
                    cout << "Enter new contact number: ";
                    cin >> userNum;
                    contactNumber = userNum;
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        }
    }
};

class Card {
    Student cardOwner;
    int cardID;
    int pickupStop;
    int dropoffStop;
    int routeNum;
    bool feesPaid;
    bool attendance[31];

public:
    Card() {
        cardID = 0;
        pickupStop = 0;
        dropoffStop = 0;
        routeNum = 0;
        feesPaid = false;
        for (int i = 0; i < 31; i++) attendance[i] = false;
    }

    Card(int cid, int pn, int dn, int bn) {
        cardID = cid;
        pickupStop = pn;
        dropoffStop = dn;
        routeNum = bn;
        feesPaid = false;
        for (int i = 0; i < 31; i++) attendance[i] = false;
    }

    int getCardID() { return cardID; }
    int getPickupStop() { return pickupStop; }
    int getDropoffStop() { return dropoffStop; }
    int getRouteNum() { return routeNum; }
    Student getStudent() { return cardOwner; }

    void registerCard(int cid, int pn, int dn, int bn, Student s) {
        cardID = cid;
        pickupStop = pn;
        dropoffStop = dn;
        routeNum = bn;
        cardOwner = s;
    }

    void feesPay() {
        if (!feesPaid) {
            cout << "Fees Paid" << endl;
            feesPaid = true;
        } else {
            cout << "Fees already paid" << endl;
        }
    }

    void tapCard(int day) {
        if (day < 1 || day > 31) {
            cout << "Invalid day. Please provide a day between 1 and 31." << endl;
            return;
        }
        if (!feesPaid) {
            cout << "Fees not paid. Attendance cannot be marked." << endl;
            return;
        }
        if (attendance[day - 1]) {
            cout << "Attendance already marked for day " << day << "." << endl;
            return;
        }
        attendance[day - 1] = true;
        cout << "Attendance marked for day " << day << "." << endl;
    }
};

class Stop {
    int stopNum;
    int totalSeats;
    string *stdids;

public:
    Stop() {
        stopNum = 0;
        totalSeats = 0;
        stdids = nullptr;
    }

    Stop(int sn) {
        stopNum = sn;
        totalSeats = 0;
        stdids = nullptr;
    }

    ~Stop() {
        delete[] stdids;
    }

    int getStopNum() { return stopNum; }

    void addStudent(string std_id) {
        string *newstdids = new string[totalSeats + 1];
        for (int i = 0; i < totalSeats; i++) {
            newstdids[i] = stdids[i];
        }
        newstdids[totalSeats] = std_id;
        totalSeats++;
        delete[] stdids;
        stdids = newstdids;
    }

    void removeStudent(string std_id) {
        string *newstdids = new string[totalSeats - 1];
        int j = 0;
        for (int i = 0; i < totalSeats; i++) {
            if (std_id != stdids[i]) {
                newstdids[j] = stdids[i];
                j++;
            }
        }
        totalSeats--;
        delete[] stdids;
        stdids = newstdids;
    }
};

class Route {
    int routeNum;
    string driverName;
    int capacity;
    int registeredSeats;
    Card **studentsInThisRoute;
    Stop **stops;
    int totalStops;

public:
    Route() {
        routeNum = 0;
        driverName = "";
        capacity = 0;
        registeredSeats = 0;
        studentsInThisRoute = nullptr;
        stops = nullptr;
        totalStops = 0;
    }

    Route(int rn, string dn, int c) {
        routeNum = rn;
        driverName = dn;
        capacity = c;
        registeredSeats = 0;
        studentsInThisRoute = nullptr;
        stops = nullptr;
        totalStops = 0;
    }

    ~Route() {
        for (int i = 0; i < registeredSeats; i++) delete studentsInThisRoute[i];
        delete[] studentsInThisRoute;
        for (int i = 0; i < totalStops; i++) delete stops[i];
        delete[] stops;
    }

    int getRouteNum() { return routeNum; }

    bool isThereSpace() {
        return registeredSeats < capacity;
    }

    int getTotalStops() {
        return totalStops;
    }

    Stop* getStop(int index) {
        if (index >= 0 && index < totalStops) {
            return stops[index];
        }
        return nullptr;
    }

    void addStudent(Card *c) {
        Card **newStdsList = new Card*[registeredSeats + 1];
        for (int i = 0; i < registeredSeats; i++) {
            newStdsList[i] = studentsInThisRoute[i];
        }
        newStdsList[registeredSeats] = c;
        delete[] studentsInThisRoute;
        studentsInThisRoute = newStdsList;
        registeredSeats++;
    }

    void addStop(int stop) {
        for (int i = 0; i < totalStops; i++) {
            if (stop == stops[i]->getStopNum()) {
                cout << "Stop already exists in this route" << endl;
                return;
            }
        }
        Stop** newarr = new Stop*[totalStops + 1];
        for (int i = 0; i < totalStops; i++) {
            newarr[i] = stops[i];
        }
        newarr[totalStops] = new Stop(stop);
        delete[] stops;
        stops = newarr;
        totalStops++;
        cout << "New stop added successfully!\n";
    }

    void removeStop(int stop) {
        bool found = false;
        for (int i = 0; i < totalStops; i++) {
            if (stops[i]->getStopNum() == stop) {
                found = true;
                break;
            }
        }
        if (found) {
            Stop** newarr = new Stop*[totalStops - 1];
            int j = 0;
            for (int i = 0; i < totalStops; i++) {
                if (stops[i]->getStopNum() != stop) {
                    newarr[j] = stops[i];
                    j++;
                }
            }
            delete[] stops;
            stops = newarr;
            totalStops--;
            cout << "Stop removed successfully!\n";
            return;
        }
        cout << "Stop doesn't exist in this route\n";
    }

    void removeStudent(string studentId) {
        int index = -1;
        for (int i = 0; i < registeredSeats; i++) {
            if (studentsInThisRoute[i]->getStudent().getID() == studentId) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Student with ID " << studentId << " not found." << endl;
            return;
        }
        delete studentsInThisRoute[index];
        for (int i = index; i < registeredSeats - 1; i++) {
            studentsInThisRoute[i] = studentsInThisRoute[i + 1];
        }
        registeredSeats--;
        Card **newStdsList = new Card*[registeredSeats];
        for (int i = 0; i < registeredSeats; i++) {
            newStdsList[i] = studentsInThisRoute[i];
        }
        delete[] studentsInThisRoute;
        studentsInThisRoute = newStdsList;
        cout << "Student removed successfully." << endl;
    }
};

Card **cards = nullptr;
Route **routes = nullptr;

void RegisterStudent() {
    int totalCards = 0;
    while (cards && cards[totalCards]) totalCards++;
    int totalRoutes = 0;
    while (routes && routes[totalRoutes]) totalRoutes++;

    string n, sid, e;
    int cn, pstop, dstop, rnum;
    cout << "Registering Student:" << endl;
    cout << "Student Name: ";
    cin >> n;
    cout << "Student ID: ";
    cin >> sid;
    cout << "Student Email: ";
    cin >> e;
    cout << "Student Contact Number: ";
    cin >> cn;

    cout << "Route Number: ";
    cin >> rnum;

    int rindex = -1;
    for (int i = 0; i < totalRoutes; i++) {
        if (routes[i]->getRouteNum() == rnum) {
            rindex = i;
            break;
        }
    }
    if (rindex == -1) {
        cout << "Incorrect Route Number! Try Again" << endl;
        return;
    }

    if (!routes[rindex]->isThereSpace()) {
        cout << "No seat left in route " << rnum << endl;
        return;
    }

    cout << "Pickup Stop Number: ";
    cin >> pstop;
    cout << "Dropoff Stop Number: ";
    cin >> dstop;

    bool pickupValid = false, dropoffValid = false;
    for (int i = 0; i < routes[rindex]->getTotalStops(); i++) {
        if (routes[rindex]->getStop(i)->getStopNum() == pstop) {
            pickupValid = true;
        }
        if (routes[rindex]->getStop(i)->getStopNum() == dstop) {
            dropoffValid = true;
        }
    }

    if (!pickupValid || !dropoffValid) {
        cout << "Invalid Pickup or Dropoff Stop! Please check the stops for route " << rnum << endl;
        return;
    }

    Student s1(n, sid, e, cn);
    Card *newCard = new Card(totalCards + 1, pstop, dstop, rnum);
    newCard->registerCard(totalCards + 1, pstop, dstop, rnum, s1);

    Card **newcards = new Card*[totalCards + 1];
    for (int i = 0; i < totalCards; i++) {
        newcards[i] = cards[i];
    }
    newcards[totalCards] = newCard;
    delete[] cards;
    cards = newcards;
    totalCards++;

    int choice;
    cout << "Enter 1 if you want to pay fees to validate transport card: ";
    cin >> choice;
    if (choice == 1) {
        newCard->feesPay();
    }

    routes[rindex]->addStudent(newCard);
    cout << "Student registered successfully!" << endl;
}

void addAPoint() {
    int rnum, totalseats;
    string dname;
    int totalRoutes = 0;
    while (routes && routes[totalRoutes]) totalRoutes++;

    cout << "Enter Route Number of new Point: ";
    cin >> rnum;
    for (int i = 0; i < totalRoutes; i++) {
        if (routes[i]->getRouteNum() == rnum) {
            cout << "Route Number already exists!" << endl;
            return;
        }
    }

    cout << "Enter Driver's name: ";
    cin >> dname;
    cout << "Enter total capacity of seats in point: ";
    cin >> totalseats;

    Route** newarr = new Route*[totalRoutes + 1];
    for (int i = 0; i < totalRoutes; i++) {
        newarr[i] = routes[i];
    }
    newarr[totalRoutes] = new Route(rnum, dname, totalseats);
    delete[] routes;
    routes = newarr;
    cout << "New point added successfully!\n";
}

void addStopToPoint() {
    int rnum, stop;
    int totalRoutes = 0;
    while (routes && routes[totalRoutes]) totalRoutes++;

    cout << "Enter Route Number to add stop to: ";
    cin >> rnum;

    bool found = false;
    int rindex;
    for (int i = 0; i < totalRoutes; i++) {
        if (routes[i]->getRouteNum() == rnum) {
            found = true;
            rindex = i;
            break;
        }
    }

    if (!found) {
        cout << "Invalid Route Number" << endl;
        return;
    }

    cout << "Enter Stop Number to add: ";
    cin >> stop;
    routes[rindex]->addStop(stop);
}

void removeStopFromPoint() {
    int rnum, stop;
    int totalRoutes = 0;
    while (routes && routes[totalRoutes]) totalRoutes++;

    cout << "Enter Route Number to remove stop from: ";
    cin >> rnum;

    bool found = false;
    int rindex;
    for (int i = 0; i < totalRoutes; i++) {
        if (routes[i]->getRouteNum() == rnum) {
            found = true;
            rindex = i;
            break;
        }
    }

    if (!found) {
        cout << "Invalid Route Number" << endl;
        return;
    }

    cout << "Enter Stop Number to remove: ";
    cin >> stop;
    routes[rindex]->removeStop(stop);
}

void removePoint() {
    int rnum;
    int totalRoutes = 0;
    while (routes && routes[totalRoutes]) totalRoutes++;

    cout << "Enter Route Number to remove: ";
    cin >> rnum;

    bool found = false;
    int rindex;
    for (int i = 0; i < totalRoutes; i++) {
        if (routes[i]->getRouteNum() == rnum) {
            found = true;
            rindex = i;
            break;
        }
    }

    if (!found) {
        cout << "Invalid Route Number" << endl;
        return;
    }

    Route** newarr = new Route*[totalRoutes - 1];
    int j = 0;
    for (int i = 0; i < totalRoutes; i++) {
        if (i != rindex) {
            newarr[j] = routes[i];
            j++;
        }
    }
    delete[] routes;
    routes = newarr;
    cout << "Route removed successfully!\n";
}

void markAttendance() {
    string studentID;
    int day;
    cout << "Enter Student ID: ";
    cin >> studentID;
    cout << "Enter Day (1-31): ";
    cin >> day;

    int totalCards = 0;
    while (cards && cards[totalCards]) totalCards++;

    bool found = false;
    for (int i = 0; i < totalCards; i++) {
        if (cards[i]->getStudent().getID() == studentID) {
            cards[i]->tapCard(day);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student ID not found!" << endl;
    }
}

void removeStudent() {
    cout << "Enter Card ID of student to remove: ";
    int cardID, totalcards = 0, cindex;
    cin >> cardID;
    while (cards && cards[totalcards]) {
        totalcards++;
    }
    int totalRoutes = 0;
    while (routes && routes[totalRoutes]) {
        totalRoutes++;
    }
    
    bool found = false;
    for (int i = 0; i < totalcards; i++) {
        if (cardID == cards[i]->getCardID()) {
            found = true; 
            cindex = i;
            break;
        }
    }

    if (found) {
        for (int i = 0; i < totalRoutes; i++) {
            if (routes[i]->getRouteNum() == cards[cindex]->getRouteNum()) {
                routes[i]->removeStudent(cards[cindex]->getStudent().getID());
                break;
            }
        }

        Card** newarr = new Card*[totalcards - 1];
        int j = 0;
        for (int i = 0; i < totalcards; i++) {
            if (i != cindex) {
                newarr[j] = cards[i];
                j++;
            }
        }
        delete[] cards;
        cards = newarr;
        cout << "Card removed successfully!\n";
        return;
    }
    cout << "Card doesn't exist\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\nFAST Transportation System Menu" << endl;
        cout << "Press 1 to Register a Student" << endl;
        cout << "Press 2 to Remove a Student" << endl;
        cout << "Press 3 to Add a Point" << endl;
        cout << "Press 4 to Remove a Point" << endl;
        cout << "Press 5 to Add a Stop to a Point" << endl;
        cout << "Press 6 to Remove a Stop from a Point" << endl;
        cout << "Press 7 to Tap Card to Mark Attendance " << endl;
        cout << "Press 8 to Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                RegisterStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                addAPoint();
                break;
            case 4:
                removePoint();
                break;
            case 5:
                addStopToPoint();
                break;
            case 6:
                removeStopFromPoint();
                break;
            case 7:
                markAttendance();
                break;
            case 8:
                cout << "Exiting system" << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}
