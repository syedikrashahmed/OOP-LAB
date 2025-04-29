#include <iostream>
#include <string>
using namespace std;

class InvalidValueException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Error: InvalidValueException - Age cannot be negative or exceed 120.";
    }
};

void validateAge(int age) {
    if (age < 0 || age > 120) {
        throw InvalidValueException();
    }
}

int main() {
    int age;
    cout << "age: ";
    cin >> age;
    
    try {
        validateAge(age);
        cout << "Age is valid: " << age << endl;
    } catch (const InvalidValueException& e) {
        cerr << e.what() << endl;
    }
}
