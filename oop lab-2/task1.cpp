/*Task 1
Write a C++ program that reads a group of n numbers from the user and stores them in a dynamically
allocated array of type float. Then, the program should:
 Calculate the average of the numbers.
 Find the number closest to the average.
 Print the average and the number closest to it.
 Use pointer notation wherever possible.*/

#include <iostream>
using namespace std;

int main() {
    int n; float avg, sum = 0, closest, cldiff = 9999.9;
    cout << "Enter number of elements in array: ";
    cin >> n;
    float *arr = new float[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> *(arr + i);
        sum = sum + *(arr + i);
    }
    avg = sum / n;
    for (int i = 0; i < n; i++) {
        if (avg - *(arr + i) < 0) {
            if (((avg - *(arr + i)) * -1) < cldiff) {
                cldiff = ((avg - *(arr + i)) * -1);
                closest = *(arr + i);
            }
        }
        else {
             if ((avg - *(arr + i)) < cldiff) {
                cldiff = (avg - *(arr + i));
                closest = *(arr + i);
            }
        }
    }
    cout << "Average is " << avg << endl;
    cout << "Closest Element is " << closest << endl;
}