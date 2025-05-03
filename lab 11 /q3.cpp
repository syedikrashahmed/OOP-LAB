#include <iostream>
#include <string>
#include <fstream>
#include <exception>
using namespace std;

class FileException : public exception{
    public:
    virtual const char* what() const noexcept override {
        return "FileException - File error!";
    }
};

class FileNotFoundException : public FileException {
    public:
    const char* what() const noexcept override {
        return "FileNotFoundException - File not found!";
    }
};

class PermissionDeniedException : public FileException {
    public:
    const char* what() const noexcept override {
        return "PermissionDeniedException - Access denied!";
    }
};

void readFile(const string& filename) {  
    ifstream inFile(filename);
    if (!inFile) {
        ofstream testFile(filename, ios::app);
        if (!testFile) {
            throw PermissionDeniedException();
        } else {
            testFile.close();
            throw FileNotFoundException();
        }
    }
    
    string line;
    if (!getline(inFile, line)) {
        inFile.close();
        throw PermissionDeniedException();
    }

    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

int main() {
    try {
        readFile("secret.txt");
    }
    catch (const FileNotFoundException& e) {
        cerr << "FileNotFoundException: " << e.what() << endl;
    }
    catch (const PermissionDeniedException& e) {
        cerr << "PermissionDeniedException: " << e.what() << endl;
    }
    catch (const FileException& e) {
        cerr << "FileException: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown error occurred" << endl;
    }
}
