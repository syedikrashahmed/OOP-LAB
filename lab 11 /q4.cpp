#include <iostream>
#include <string>
#include <cmath>
#include <exception>
using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException - num is negative!";
    }
};

class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException - num is not numeric!";
    }
};

template <typename T>
void sqRoot(T num);

template<>
void sqRoot<string>(string num) {
    throw InvalidTypeException();
}

template <typename T>
void sqRoot(T num) {
    if (num < 0) {
        throw NegativeNumberException();
    }

    cout << "Square Root of " << num << ": " << sqrt(num) << endl;
}

template<>
void sqRoot<const char*>(const char* num) {
    throw InvalidTypeException();
}

int main() {
    try {
        sqRoot(50);
        sqRoot(4.2);
        sqRoot(-50);    
        sqRoot("ikrash"); 
    }
    catch (const NegativeNumberException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const InvalidTypeException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Standard exception: " << e.what() << endl;
    }
}
