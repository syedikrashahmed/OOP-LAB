#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name, email, summary;
    int yearsOfExperience;
    ofstream outFile("resume.txt", ios::trunc);
    if (!outFile) {
        cerr << "error in resume.txt" << endl;
        return 0;
    }

    cout << "name: ";
    getline(cin, name);
    cout << "email: ";
    getline(cin, email);
    cout << "years of experience: ";
    cin >> yearsOfExperience;
    cin.ignore(); 
    cout << "summary: ";
    getline(cin, summary);

    outFile << "name: " << name << endl;
    outFile << "email: " << email << endl;
    outFile << "years of experience: " << yearsOfExperience << endl;
    outFile << "summary: " << summary << endl;
    outFile.close();

    ifstream inFile("resume.txt");
    if (!inFile) {
        cerr << "error in reading " << endl;
        return 0;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}