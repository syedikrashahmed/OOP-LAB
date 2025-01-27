/*Task 2
Write a C++ program that:
 Reads n strings from the user and stores them in a dynamically allocated array of char*.
 Prints the strings in reverse order using pointer arithmetic.
 Finds and prints the string with the most vowels (a, e, i, o, u).
 Calculates and prints the average length of all the strings.
Note: Use pointer notation wherever possible.
If there are multiple strings with the same number of vowels, print the first one encountered*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, elements, suml = 0, vowels; char temp[50];
    cout << "Enter number of elements: ";
    cin >> n;

    char** arr = new char*[n];
    int* varr = new int[n]; 
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        cin >> temp;
        *(arr + i) = new char[strlen(temp) + 1];
        strcpy(*(arr + i), temp);
    }
    
    cout << endl << "Print in Reverse Order" << endl;
    for (int i = 0; i < n; i++){
        vowels = 0;
        elements = strlen(*(arr + i));
        suml = suml + elements;
        for (int j = elements-1; j >= 0; j--){
            cout << *(*(arr + i) + j) ;
            switch(*(*(arr + i) + j)) {
                case 'a': vowels++; break;
                case 'e': vowels++; break;
                case 'i': vowels++; break;
                case 'o': vowels++; break;
                case 'u': vowels++; break;
                default: vowels+=0;
            }
        }
        cout << endl;
        *(varr + i) = vowels;
    }
    cout << endl;
    int maxv, vpos;
    for (int i = 0; i < n; i++) {
        if (*(varr + i) > maxv){
            maxv = *(varr + i);
            vpos = i;
            break;
        }
    }
    cout << "\nString with the most vowels is " << *(arr + vpos) << " and it has " << *(varr + vpos) << " vowels"<<endl;
    cout << "Average length of all the string is " << suml / n;



    for (int i = 0; i < n; i++) {
        delete[] *(arr + i);
    }
    delete[] arr;
}