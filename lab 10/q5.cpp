#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int main() {
    ofstream outFile("data.txt", ios::out);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }
    outFile << "AI is the future. AI will transform the world. Embrace AI now.";
    outFile.close();

    string searchWord, replacementWord;
    cout << "Search Word: "; 
    cin >> searchWord;
    cout << "Replacement Word: "; 
    cin >> replacementWord;
    if (replacementWord.length() > searchWord.length()) {
        cout << "Replacement word should be smaller or equal to search word\n";
        return 0;
    }

    fstream file("data.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    char ch;
    string currentWord;
    int replacements = 0;
    streampos wordStartPos = file.tellg();
    while (file.get(ch)) {
        if (isAlpha(ch)) {
            if (currentWord.empty()) {
                wordStartPos = file.tellg();
                wordStartPos -= streampos(1); 
            }
            currentWord += ch;
        } 
        else {
            if (currentWord == searchWord) {
                streampos currentPos = file.tellg();                
                file.seekp(wordStartPos);
                file << replacementWord;
                int padding = searchWord.length() - replacementWord.length();
                for (int i = 0; i < padding; i++) {
                    file << ' ';
                }
                replacements++;
                file.seekg(currentPos);
            }
            currentWord.clear();
        }
    }

    if (currentWord == searchWord) {
        file.seekp(wordStartPos);
        file << replacementWord;
        int padding = searchWord.length() - replacementWord.length();
        for (int i = 0; i < padding; i++) {
            file << ' ';
        }
        replacements++;
    }
    cout << "\nReplacements made: " << replacements << endl;
    cout << "Updated file content:\n";
    file.seekg(0);
    while (file.get(ch)) {
        cout << ch;
    }

    file.close();
}
