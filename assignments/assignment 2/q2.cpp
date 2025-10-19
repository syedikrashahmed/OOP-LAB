/*Scenario # 2:
 Let’s say you are working to simulate a Haunted House based game! our game allows users to create multiple Haunted Houses with ghosts of their own choices. After creating a Haunted House, the user can run a simulation to see how well the Haunted Houses doing in terms or visitor experience and scares!Let’s have a look at the entities involved:*/

#include <iostream> 
#include <string>
using namespace std;

/* • Ghost – the super class for all types of ghosts. It will contain everything that is shared between different types of ghosts. For example: name of the worker playing the ghost, the scare level of the ghost (RNG 1-10), a function to perform the haunting, etc. Ghosts have some operator overloading done on the << operator to display information about them, and + operator to upgrade a ghost (results in a ghost with two people playing a bigger ghost and combined scare level of both ghosts) */

class Ghost
{
  protected:
    string nameOfWorker;
    int scareLevel; //rating from 1 to 10

  public:
    Ghost() {
        nameOfWorker = "";
        scareLevel = 0;
    }

    Ghost(string nameOfWorker, int scareLevel)
    : nameOfWorker(nameOfWorker) {
        while (scareLevel > 10 || scareLevel < 1)
        {
            cout << "Enter Score Level between 1 and 10: ";
            cin >> scareLevel;
        }
        this->scareLevel = scareLevel;
    }

    virtual void haunt() { }

    string getWorkerName()
    {
        return nameOfWorker;
    }

    int getScareLevel()
    {
        return scareLevel;
    }
    
    Ghost operator+ (Ghost g) {    
        string newName = nameOfWorker + g.getWorkerName(); 
        int newScareLevel = scareLevel + g.getScareLevel();
        if (newScareLevel > 10) {    
            scareLevel = 10;
        }
        
        Ghost g1 = Ghost(newName, newScareLevel);
        return g1;
    }

    void upgradeGhost(Ghost g1) {
        *this = *this + g1;        
    }

    virtual void display() {}
};

void operator <<(ostream &COUT, Ghost &g)
{
    cout << "Name of Worker playing the Ghost: " << g.getWorkerName() << endl;
    cout << "Scare Level: " << g.getScareLevel() << endl;
}

/*• HauntedHouse – has a name and multiple ghosts (ensure runtime polymorphism here).*/
class Visitor;

class HauntedHouse
{
    protected:
    string name;
    Ghost **ghosts;
    int numGhosts;
    
    public:
    HauntedHouse() : name(""), ghosts(nullptr), numGhosts(0) {}
    
    HauntedHouse(string name, Ghost **ghost, int numGhosts) : name(name), ghosts(ghost), numGhosts(numGhosts) {}

    friend void Visit(Visitor *visitors, int numVisitors, HauntedHouse &hauntedhouse);
};

/*• There are different ghosts who perform hauntings differently*/
/*Poltergeists (move objects)*/
class Poltergeist : virtual public Ghost {
    public:
    Poltergeist() : Ghost() {}

    Poltergeist(string nameOfWorker, int scareLevel) : Ghost(nameOfWorker, scareLevel) {}

    void haunt() override {
        cout << "Poltergeist "<< nameOfWorker << " moves objects!" << endl;
    }

    void display() override {
        cout << "Poltergeist is played by "<< nameOfWorker << " and the scare level rating is " << scareLevel << endl;
    }
};

/*Banshees (scream loudly)*/
class Banshee : virtual public Ghost {
    public:
    Banshee() : Ghost() {}

    Banshee(string nameOfWorker, int scareLevel) : Ghost(nameOfWorker, scareLevel) {}

    void haunt() override {
        cout << "Banshee "<< nameOfWorker << " screams loudly!" << endl;
    }

    void display() override {
        cout << "Banshee is played by "<< nameOfWorker << " and the scare level rating is " << scareLevel << endl;
    }
};


/*ShadowGhosts (whisper creepily).*/
class ShadowGhost : virtual public Ghost {
    public:
    ShadowGhost() : Ghost() {}

    ShadowGhost(string nameOfWorker, int scareLevel) : Ghost(nameOfWorker, scareLevel) {}

    void haunt() override {
        cout << "ShadowGhost "<< nameOfWorker << " whispers creepily!" << endl;
    }

    void display() override {
        cout << "ShadowGhost is played by "<< nameOfWorker << " and the scare level rating is " << scareLevel << endl;
    }
};

/*• There are also some hybrid ghosts that may appear; for example, ShadowPoltergeist (is 
a shadow ghost and Poltergeist). This ghost performs both actions of a ShadowGhost 
and a Poltergeist.*/

class ShadowPoltergeist : public ShadowGhost, public Poltergeist {
public:
    ShadowPoltergeist() : Ghost(), ShadowGhost(), Poltergeist() {}

    ShadowPoltergeist(string nameOfWorker, int scareLevel) 
        : Ghost(nameOfWorker, scareLevel), ShadowGhost(nameOfWorker, scareLevel), Poltergeist(nameOfWorker, scareLevel) {}

    void haunt() override {
        ShadowGhost::haunt();
        Poltergeist::haunt();
    }

    void display() override {
        cout << "ShadowPoltergeist is played by " << nameOfWorker << " and the scare level rating is " << scareLevel << endl;
    }
};

class ShadowBanshee : public ShadowGhost, public Banshee {
public:
    ShadowBanshee() : Ghost(), ShadowGhost(), Banshee() {}

    ShadowBanshee(string nameOfWorker, int scareLevel) : Ghost(nameOfWorker, scareLevel), ShadowGhost(nameOfWorker, scareLevel), Banshee(nameOfWorker, scareLevel) {}

    void haunt() override {
        ShadowGhost::haunt();
        Banshee::haunt();
    }

    void display() override {
        cout << "ShadowBanshee is played by " << nameOfWorker << " and the scare level rating is " << scareLevel << endl;
    }
};

class BansheePoltergeist : public Banshee, public Poltergeist {
public:
    BansheePoltergeist() : Ghost(), Banshee(), Poltergeist() {}

    BansheePoltergeist(string nameOfWorker, int scareLevel) 
        : Ghost(nameOfWorker, scareLevel), Banshee(nameOfWorker, scareLevel), Poltergeist(nameOfWorker, scareLevel) {}

    void haunt() override {
        Banshee::haunt();
        Poltergeist::haunt();
    }

    void display() override {
        cout << "BansheePoltergeist is played by " << nameOfWorker << " and the scare level rating is " << scareLevel << endl;
    }
}; 

/*• Visitor – a class of objects that can “visit” a Haunted house. Each visitor has a name and some amount of bravery (1-4: Cowardly, 5-7: Average, 8-10: Fearless).*/ 

class Visitor {
    private:
    string name;
    int braveryLevel; /*(1-4: Cowardly, 5-7: Average, 8-10: Fearless)*/

    public:
    Visitor() : name("") , braveryLevel(0) {}

    Visitor(string name, int braveryLevel) : name(name), braveryLevel(braveryLevel) {
        while (braveryLevel > 10 || braveryLevel < 1)
        {
            cout << "Enter Score Level between 1 and 10: ";
            cin >> braveryLevel;
        }
        this->braveryLevel = braveryLevel;
    }

    string getName() { return name;}

    int getBraveryLevel()
    {
        return braveryLevel;
    }

    friend void Visit(Visitor *visitors, int numVisitors, HauntedHouse &hauntedhouse);
};

/*When a visitor visits a Haunted House, the ghosts will try to haunt them. If the scare level of the ghost is less than the bravery range of the visitor, then the visitor might laugh or taunt the ghost. If it is greater, then the visitor might scream or run away. If it’s around average, then they might get a shaky voice. (please make sure to check if the scare level lies within the bravery range; DO NOT compare the numbers directly)
• “Visit” is a global friend function that accepts the Visitors array and a Haunted House, and then simulates the visit..*/

// void Visit(Visitor *visitors, int numVisitors, HauntedHouse &hauntedhouse) {
//          cout << "Visiting Haunted House: " << hauntedhouse.name << endl;
//     for (int i = 0; i < numVisitors; i++) {
//         cout << "Visitor: " << visitors[i].getName() << " (Bravery: " << visitors[i].getBraveryLevel() << ")" << endl;
//         for (int j = 0; j < hauntedhouse.numGhosts; j++) {
//             // cout << "Ghost: " << hauntedhouse.ghosts[j]->getWorkerName() << " (Scare Level: " << hauntedhouse.ghosts[j]->getScareLevel() << ")" << endl;

//             hauntedhouse.ghosts[j]->haunt();

//             int bravery = visitors[i].getBraveryLevel();
//             int scare = hauntedhouse.ghosts[j]->getScareLevel();

//             if (scare < bravery - 2) {
//                 cout << visitors[i].getName() << " laughs at the ghost!" << endl;
//             } else if (scare > bravery + 2) {
//                 cout << visitors[i].getName() << " screams and runs away!" << endl;
//             } else {
//                 cout << visitors[i].getName() << " gets a shaky voice!" << endl;
//             }
//         }
//         cout << endl;
//     }
// }

void Visit(Visitor *visitors, int numVisitors, HauntedHouse &hauntedHouse) {
    cout << "Visiting Haunted House: " << hauntedHouse.name << endl;
    for (int i = 0; i < numVisitors; i++) {
        cout << "Visitor: " << visitors[i].getName() << " (Bravery: " << visitors[i].getBraveryLevel() << ")" << endl;
        for (int j = 0; j < hauntedHouse.numGhosts; j++) {
            hauntedHouse.ghosts[j]->display();
            hauntedHouse.ghosts[j]->haunt();

            int bravery = visitors[i].getBraveryLevel();
            int scare = hauntedHouse.ghosts[j]->getScareLevel();

            if (scare < bravery - 2) {
                cout << visitors[i].getName() << " laughs at the ghost!" << endl;
            } else if (scare > bravery + 2) {
                cout << visitors[i].getName() << " screams and runs away!" << endl;
            } else {
                cout << visitors[i].getName() << " gets a shaky voice!" << endl;
            }
        }
        cout << endl;
    }
}

/*• Main method should make 2-3 Haunted Houses with multiple ghosts of each type.
• Main method should also have an array of Visitors (a group of friends visiting the haunted house) Try to ensure that there’s at least one of each bravery level among the group.*/

int main() {
    ShadowBanshee g4("De Angelo", 2);
    Poltergeist g1("Frank", 3);
    Banshee g2("Leo", 7);
    ShadowGhost g3("Nico", 9);
    
    g3.display();
    g4.display();
    g3.upgradeGhost(g1);
    g3.display();

    Ghost *ghosts[] = {&g1, &g2, &g3};
    HauntedHouse h1("Mount Olympus", ghosts, 3);
    HauntedHouse h2("Hecate's Mansion", ghosts, 3);

    Visitor v1("Grover", 2);  
    Visitor v2("Percy", 6);  
    Visitor v3("Annabeth", 9);  
    Visitor visitors[] = {v1, v2, v3};

    Visit(visitors, 3, h1);
    Visit(visitors, 3, h2);
}
