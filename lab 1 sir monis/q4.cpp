/*4. Write a program that prompts the user to enter the weight of a person in kilograms and outputs the equivalent weight in pounds. Output both the weights rounded to two decimal places. (Note that 1 kilogram = 2.2 pounds.) Format your output with two decimal places*/ 
#include <iostream>
#include <iomanip> /* for fixed (decimal place) and precision (significant figures) */
using namespace std;
int main() {
    float kilo, pound;
    cout << "enter the weight in kilograms: ";
    cin >> kilo;
    pound = kilo * 2.2;
    cout << fixed << setprecision(2) << "weight in pounds: " << pound;
}