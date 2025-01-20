/*Q1: Write a C++ program to check whether a given number is prime or not. Allow the user to input a number and display whether it's prime or not?*/

#include <iostream>
using namespace std;
int main() {
    int num, flag = 1;
    cout << "Enter number to check: ";
    cin >> num;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0) {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        cout << "Prime Number";
    else
        cout << "Not a Prime Number";
}