/*Task 5: You are required to write a c++ function swap_string that shifts the last n characters of a string to the
front n times. It will take str and int as parameters. And will return the new string after shifting.
Note: You have to work with pointers.*/
#include <iostream>
using namespace std;
string swap_string(string word, int n);

int main() {
	string brr = "ikrashahmed";
	string hh = swap_string("ikrashahmed", 3);
	cout << hh;
}

string swap_string(string word, int n) {  
    int size = sizeof(word) / sizeof(word[0]);
    string last;
    for (int i = 0; i < n; i++) { 
          last[i] = word[size - n];
    }
    cout << last;
    return last;
}