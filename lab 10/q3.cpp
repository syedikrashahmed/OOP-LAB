#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream chap1("chapter1.txt");
    if (!chap1) {
        cerr << "Error opening file for reading!" << endl;
        return 0;
    }
    ifstream chap2("chapter2.txt");
    if (!chap2) {
        cerr << "Error opening file for reading!" << endl;
        return 0;
    }
    ofstream book("book.txt");
    if (!book) {
        cerr << "Error opening file for writing!" << endl;
        return 0;
    }

    string line;
    while (getline(chap1, line)) {
        book << line << endl;
    }

    book << endl;

    while (getline(chap2, line)) {
        book << line << endl;
    }

}