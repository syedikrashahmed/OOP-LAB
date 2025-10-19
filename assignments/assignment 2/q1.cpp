#include <iostream>
using namespace std;
#include <string> 

class Person;
class Card;

class Person {
    protected:
    string name;
    string id;
    int contactNumber;
    string email;
    string userType;

    public:
    Person(string name, string id, int contactNumber, string email, string userType) : name(name), id(id), contactNumber(contactNumber), email(email), userType(userType) {}
    
    Person() : name(""), id(""), contactNumber(0), email(""), userType("") {}

    ~Person() {}    

    void update() {
        cout << "Updating Information:" << endl;
        int choice;
        string userStr;
        int userNum;
        while (true) {
            cout << "Press 1 to update name\nPress 2 to update ID\nPress 3 to update email\nPress 4 to update contact Number\nPress 5 to stop update\nchoice: ";
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
                    id = userStr;
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

    string getName() { return name; }
    string getUserType() { return userType; }
    string getUserId() { return id; }

    friend void RegisterPassenger();
    friend void markAttendance();
    friend void removePassenger();
    friend class Route;
    
};

class Student : public Person {
    string department;
    string yearOfSchool; //freshman, sophmore,etc
    public:
    Student(string name, string id, int contactNumber, string email, string department, string yearOfSchool) : Person(name, id, contactNumber, email, "student"), department(department), yearOfSchool(yearOfSchool) {}

    Student() : Person(), department(""), yearOfSchool("") {}

    ~Student() {}

    
    
};

class Teacher : public Person {
    string department;
    float salary;
    string subject;

    public:
    Teacher(string name, string id, int contactNumber, string email, string department, float salary, string subject) : Person(name, id, contactNumber, email, "teacher"), department(department), salary(salary), subject(subject) {}

    Teacher() : Person(), department(""), salary(0), subject("") {}

    ~Teacher() {}
    
};

class Staff : public Person {
    string department;
    float salary;

    public:
    Staff(string name, string id, int contactNumber, string email, string department, float salary) : Person(name, id, contactNumber, email, "staff"), department(department), salary(salary) {}

    Staff() : Person(), department(""), salary(0) {}

    ~Staff() {}
};

class Card {
    Person *cardOwner;
    int cardID;
    int pickupStop;
    int dropoffStop;
    int routeNum;
    bool feesPaid;
    bool attendance[31];

    public:
    Card(Person *cardOwner, int cardID, int pickupStop, int dropoffStop, int routeNum) : cardOwner(cardOwner), cardID(cardID), pickupStop(pickupStop), dropoffStop(dropoffStop), routeNum(routeNum), feesPaid(false) {
        for (int i = 0; i < 31; i++) {
            attendance[i] = false;
        }
    }
    
    Card() : cardOwner(nullptr), cardID(0), pickupStop(0), dropoffStop(0), routeNum(0), feesPaid(false) {
        for (int i = 0; i < 31; i++) {
            attendance[i] = false;
        }
    }

    void registerCard(int cid, int pn, int dn, int bn, Person* p) {
        cardID = cid;
        pickupStop = pn;
        dropoffStop = dn;
        routeNum = bn;
        cardOwner = p;
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

    friend ostream& operator<<(ostream& os, const Card& c) {
        os << "Card ID: " << c.cardID << ", User ID: " << c.cardOwner->getUserId() << ", Name: " << c.cardOwner->getName() << " (" << c.cardOwner->getUserType() << ")" << endl;
        return os;
    }

    ~Card() {}

    friend void RegisterPassenger();
    friend void removePassenger();
    friend void markAttendance();
    friend class Route;
};

class Stop {
    int stopNum;
    int totalSeats;
    string *passenger_ids;

    public: 
    Stop(int stopNum,int totalSeats = 0, string *passenger_ids = nullptr) : stopNum(stopNum), totalSeats(totalSeats) {
        if (passenger_ids != nullptr) {
            this->passenger_ids = new string[totalSeats];
            for (int i = 0; i < totalSeats; i++) {
                this->passenger_ids[i] = passenger_ids[i];
            }
        }
        else {
            this->passenger_ids = nullptr;
        }
    }

    Stop() : stopNum(0), totalSeats(0), passenger_ids(nullptr) {}

    ~Stop() {
        delete[] passenger_ids;
    }
      
    void addStudent(string id) {
        string *newsarrids = new string[totalSeats + 1];
        for (int i = 0; i < totalSeats; i++) {
            newsarrids[i] = passenger_ids[i];
        }
        newsarrids[totalSeats] = id;
        totalSeats++;
        delete[] passenger_ids;
        passenger_ids = newsarrids;
    }
    
    void removeStudent(string std_id) {
        string *newarr = new string[totalSeats - 1];
        int j = 0;
        for (int i = 0; i < totalSeats; i++) {
            if (std_id != passenger_ids[i]) {
                newarr[j] = passenger_ids[i];
                j++;
            }
        }
        totalSeats--;
        delete[] passenger_ids;
        passenger_ids = newarr;
    }

    friend void RegisterPassenger();
    friend class Route;
};

class Route {
    int routeNum;
    string driverName;
    int capacity;
    int registeredSeats;
    Card **passengersInThisRoute;
    Stop **stops;
    int totalStops;

    public:
    Route(int routeNum, string driverName, int capacity, int registeredSeats = 0, Card **passengersInThisRoute = nullptr, Stop **stops = nullptr, int totalStops = 0) : routeNum(routeNum), driverName(driverName), capacity(capacity), registeredSeats(registeredSeats), passengersInThisRoute(nullptr), 
      stops(nullptr), totalStops(totalStops)  {
        if (passengersInThisRoute != nullptr) {
            this->passengersInThisRoute = new Card*[registeredSeats];
            for (int i = 0; i < registeredSeats; i++) {
                this->passengersInThisRoute[i] = passengersInThisRoute[i];
            }
        }  
        
        if (stops != nullptr) {
            this->stops = new Stop*[totalStops];
            for (int i = 0; i < totalStops; i++) {
                this->stops[i] = stops[i];
            }
        }
    }

    ~Route() {
        for (int i = 0; i < registeredSeats; i++) 
            delete passengersInThisRoute[i];
        delete[] passengersInThisRoute;
        for (int i = 0; i < totalStops; i++) 
            delete stops[i];
        delete[] stops;
    }

    Route() : routeNum(0), driverName(""), capacity(0), registeredSeats(0), passengersInThisRoute(nullptr), stops(nullptr), totalStops(0) {}
    
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

    void addPassenger(Card *c) {
        Card **newList = new Card*[registeredSeats + 1];
        for (int i = 0; i < registeredSeats; i++) {
            newList[i] = passengersInThisRoute[i];
        }
        newList[registeredSeats] = c;
        delete[] passengersInThisRoute;
        passengersInThisRoute = newList;
        registeredSeats++;
        cout << "Passenger added successfully!\n";
    }

    void addStop(int stop) {
        for (int i = 0; i < totalStops; i++) {
            if (stop == stops[i]->stopNum) {
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
            if (stops[i]->stopNum == stop) {
                found = true;
                break;
            }
        }
        if (found) {
            Stop** newarr = new Stop*[totalStops - 1];
            int j = 0;
            for (int i = 0; i < totalStops; i++) {
                if (stops[i]->stopNum != stop) {
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

    friend ostream& operator<<(ostream& os, const Route& route) {
        os << "Route Number: " << route.routeNum << endl;
        os << "Driver Name: " << route.driverName << endl;
        os << "Registered Seats: " << route.registeredSeats << endl;
        for (int i = 0; i < route.registeredSeats; i++) {
            os << i << ") " << *route.passengersInThisRoute[i];
        }
        return os;
    }

    void removePassengerFromPoint(string id) {
        int index = -1;
        for (int i = 0; i < registeredSeats; i++) {
            if (passengersInThisRoute[i]->cardOwner->id== id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Passenger with ID " << id << " not found." << endl;
            return;
        }
        delete passengersInThisRoute[index];
        for (int i = index; i < registeredSeats - 1; i++) {
            passengersInThisRoute[i] = passengersInThisRoute[i + 1];
        }
        registeredSeats--;
        Card **newList = new Card*[registeredSeats];
        for (int i = 0; i < registeredSeats; i++) {
            newList[i] = passengersInThisRoute[i];
        }
        delete[] passengersInThisRoute;
        passengersInThisRoute = newList;
        cout << "Passenger removed successfully." << endl;
    }

    friend void RegisterPassenger();
    friend void addAPoint();
    friend void addStopToPoint();
    friend void removeStopFromPoint();
    friend void removePoint();
    friend void removePassenger();
};

Card **cards = nullptr;
Route **routes = nullptr;
int totalRoutes = 0;

void RegisterPassenger() {
    int totalCards = 0;
    while (cards && cards[totalCards]) 
        totalCards++;
    int totalRoutes = 0;
    while (routes && routes[totalRoutes]) 
        totalRoutes++;
    int pstop, dstop, rnum;
    
    cout << "Route Number: ";
    cin >> rnum;

    int rindex = -1;
    for (int i = 0; i < totalRoutes; i++) {
        if (routes[i]->routeNum == rnum) {
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
    for (int i = 0; i < routes[rindex]->totalStops; i++) {
        if (routes[rindex]->getStop(i)->stopNum == pstop) {
            pickupValid = true;
        }
        if (routes[rindex]->getStop(i)->stopNum == dstop) {
            dropoffValid = true;
        }
    }

    if (!pickupValid || !dropoffValid) {
        cout << "Invalid Pickup or Dropoff Stop! Please check the stops for route " << rnum << endl;
        return;
    }

    string n, id, e, ut;
    int cn;
    cout << "Registering Passenger:" << endl;
    do {
        cout << "User Type (student, teacher, staff): ";
        cin >> ut;
    } while (ut != "student" && ut != "teacher" && ut != "staff");
    cout << "Name: ";
    cin >> n;
    cout << "ID: ";
    cin >> id;
    cout << "Email: ";
    cin >> e;
    cout << "Contact Number: ";
    cin >> cn;

    if (ut == "student") {
        string d, y;
        cout << "Student's Department: ";
        cin.ignore();
        getline(cin, d);
        cout << "Year Of School: ";
        cin.ignore();
        getline(cin, y);

        Student *s1 = new Student(n, id, cn, e, d, y);
        Card *newCard = new Card(s1, totalCards + 1, pstop, dstop, rnum);
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
        routes[rindex]->addPassenger(newCard);
        cout << "Student registered successfully!" << endl;
    }

    else if (ut == "teacher") {
        string d, sbj; 
        float sal;
        cout << "Teacher's Department: ";
        cin.ignore();
        getline(cin, d);
        cout << "Subject Taught: ";
        cin.ignore();
        getline(cin, sbj);
        cout << "Teacher's Salary: ";
        cin >> sal;

        Teacher *t1 = new Teacher(n, id, cn, e, d, sal, sbj);
        Card *newCard = new Card(t1, totalCards + 1, pstop, dstop, rnum);
        newCard->registerCard(totalCards + 1, pstop, dstop, rnum, t1);

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
        routes[rindex]->addPassenger(newCard);
        cout << "Teacher registered successfully!" << endl;
    }
    
    else if (ut == "staff") {
        string d; 
        float sal;
        cout << "Staff's Department: ";
        cin.ignore();
        getline(cin, d);
        cout << "Staff's Salary: ";
        cin >> sal;

        Staff *s1 = new Staff(n, id, cn, e, d, sal);
        Card *newCard = new Card(s1, totalCards + 1, pstop, dstop, rnum);
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
        routes[rindex]->addPassenger(newCard);
        cout << "Staff registered successfully!" << endl;
    }
}

void addAPoint() {
    int rnum, totalseats;
    string dname;

    cout << "Enter Route Number of new Point: ";
    cin >> rnum;
    for (int i = 0; i < totalRoutes; i++) {
        if (routes[i]->routeNum == rnum) {
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
    totalRoutes++;
    cout << "New point added successfully!\n";
}

void addStopToPoint() {
    int rnum, stop;
    while (routes && routes[totalRoutes]) totalRoutes++;

    cout << "Enter Route Number to add stop to: ";
    cin >> rnum;

    bool found = false;
    int rindex;
    for (int i = 0; i < totalRoutes; i++) {
        if (routes[i]->routeNum == rnum) {
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
        if (routes[i]->routeNum == rnum) {
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
        if (routes[i]->routeNum == rnum) {
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
    totalRoutes--;
    cout << "Route removed successfully!\n";
}

void markAttendance() {
    string ID;
    int day;
    cout << "Enter Passenger ID: ";
    cin >> ID;
    cout << "Enter Day (1-31): ";
    cin >> day;

    int totalCards = 0;
    while (cards && cards[totalCards]) totalCards++;

    bool found = false;
    for (int i = 0; i < totalCards; i++) {
        if (cards[i]->cardOwner->id == ID) {
            cards[i]->tapCard(day);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "ID not found!" << endl;
    }
}

void removePassenger() {
    cout << "Enter Card ID of Person to remove: ";
    int cardID;
    cin >> cardID;
    
    int totalcards = 0;
    while (cards && cards[totalcards]) {
        totalcards++;
    }
    int totalRoutes = 0;
    while (routes && routes[totalRoutes]) {
        totalRoutes++;
    }
    
    int cindex = -1;
    for (int i = 0; i < totalcards; i++) {
        if (cards[i] && cardID == cards[i]->cardID) {
            cindex = i;
            break;
        }
    }
    if (cindex == -1) {
        cout << "Card doesn't exist\n";
        return;
    }

    delete cards[cindex]->cardOwner;
    
    bool removedFromRoute = false;
    for (int i = 0; i < totalRoutes; i++) {
        if (routes[i] && routes[i]->routeNum == cards[cindex]->routeNum) {
            routes[i]->removePassengerFromPoint(cards[cindex]->cardOwner->id);
            removedFromRoute = true;
            break;
        }
    }

    if (!removedFromRoute) {
        cout << "Could not find passenger's route\n";
    }

    delete cards[cindex];
    
    for (int i = cindex; i < totalcards - 1; i++) {
        cards[i] = cards[i + 1];
    }
    
    if (totalcards > 1) {
        Card** newarr = new Card*[totalcards - 1];
        for (int i = 0; i < totalcards - 1; i++) {
            newarr[i] = cards[i];
        }
        delete[] cards;
        cards = newarr;
    }
    else {
        delete[] cards;
        cards = nullptr;
    }
    cout << "Card removed successfully!\n";
}

void displayPoints() {
    if (totalRoutes == 0) {
        cout << "No routes exist!\n";
        return;
    }
    for (int i = 0; i < totalRoutes; i++) {
        cout << *routes[i];
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\nFAST Transportation System Menu" << endl;
        cout << "Press 1 to Add a Point" << endl;
        cout << "Press 2 to Add a Stop to a Point" << endl;
        cout << "Press 3 to Register a Passenger" << endl;
        cout << "Press 4 to Remove a Passenger" << endl;
        cout << "Press 5 to Remove a Point" << endl;
        cout << "Press 6 to Remove a Stop from a Point" << endl;
        cout << "Press 7 to Tap Card to Mark Attendance " << endl;
        cout << "Press 8 to Display all Point Information" << endl;
        cout << "Press 9 to Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addAPoint();
                break;
            case 2:
                addStopToPoint();
                break;
            case 3:
                RegisterPassenger();
                break;
            case 4:
                removePassenger();
                break;
            case 5:
                 removePoint();
                break;
            case 6:
                removeStopFromPoint();
                break;
            case 7:
                markAttendance();
                break;
            case 8:
                displayPoints();
                break;
            case 9:
                cout << "Exiting system" << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
}
