/*Task-03: Create a class called ValidateString. The purpose of this class will be check if the given characters in a string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a parameterized constructor, create multiple objects for your class that accept different strings. Create a constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.*/

#include <iostream>
#include <string>
using namespace std;

class ValidateString {
private:
    string str;

public:
    ValidateString(const string& s) : str(s) {}

    bool isValid() const {
        for (int i = 0; i < str.length(); i++) { 
            char ch = str.at(i);
            if (!((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ValidateString str1("babarAzam");
    ValidateString str2("12345678sss");
    ValidateString str3("shakur54");

    cout << "str1 is ";
    if (str1.isValid()) {
        cout << "valid" << endl;
    }
    else 
        cout << "invalid" << endl;

    cout << "str2 is ";
    if (str2.isValid()) {
        cout << "valid" << endl;
    }
    else 
        cout << "invalid" << endl;

    cout << "str3 is ";
    if (str3.isValid()) {
        cout << "valid" << endl;
    }
    else 
        cout << "invalid" << endl;

}
