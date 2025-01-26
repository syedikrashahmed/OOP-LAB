/*2. Write a program that calculates the sum of all the elements in array using pointers*/
#include <iostream>
using namespace std;
int main() {
    int sum = 0, size;
    cout << "Enter size of array: ";
    cin >> size;
    int* arrPtr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i << ": ";
        cin >> *(arrPtr + i);
    }

    for (int i = 0; i < size; i++) {
        sum = sum + *(arrPtr + i);
    }    
    cout << "sum of all the elements in array is " << sum;
}