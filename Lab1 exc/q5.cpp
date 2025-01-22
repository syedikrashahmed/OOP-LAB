/*Q5: Design Event Management System in C++ to facilitate the organization of events. The program should empower the user to seamlessly manage event details, including the event name, date, venue, and organizer. Incorporate key features such as the ability to add events, display comprehensive details of all events, and perform event searches based on specific dates. To enhance flexibility and scalability, leverage dynamic memory allocation for storing event details.
1. Prompt the user to input the total number of events they wish to manage.
2. Dynamically allocate memory to store event details for the specified
number of events.
3. For each event, prompt the user to input: Event Name, Date, Venue, Organizer
4. Display all events that match the provided date, including their complete
details.
5. Allow the user to search for events based on a specific date.*/

#include <iostream>
using namespace std;
int main() {
    int numEvents, dateCheck;
    cout << "Enter the total number of events you wish to manage: ";
    cin >> numEvents;

    string* EvNames = new string[numEvents];
    int* EvDate = new int[numEvents];
    string* EvVenue = new string[numEvents];
    string* EvOrganizer = new string[numEvents];

    for (int i = 0; i < numEvents; i++) {
        cout << "Enter Name of Event " << i << ": ";
        cin >> EvNames[i];
        cout << "Enter Date of Event " << i << ": ";
        cin >> EvDate[i];
        cout << "Enter Venue of Event " << i << ": ";
        cin >> EvVenue[i];
        cout << "Enter Organizer of Event " << i << ": ";
        cin >> EvOrganizer[i];
    }

    int flag = 0;
    cout << endl;
    cout << "Enter date of events to search: ";
    cin >> dateCheck;
    cout << "Name\t Venue\t Organizer" << endl;
    for (int i = 0; i < numEvents; i++) {
        if (dateCheck == EvDate[i]) {
            cout << EvNames[i] << "\t" << EvVenue[i] << "\t" << EvOrganizer[i] << endl;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << " no Event found on this date";
    }

    delete[] EvNames;
    delete[] EvDate;
    delete[] EvVenue;
    delete[] EvOrganizer;
}