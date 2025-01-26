/*3. Write a program in C++ to calculate and print the Electricity bill of a given customer. The customer id, name and unit consumed by the user should be taken from the keyboard and display the total amount to pay to the customer. The charges per unit consumed are as follow: 
up to 199 = 16.2, 200 and less than 300 = 20.10, 300 and less than 400 = 20.10, 500 and above = 35.90
If bill exceeds Rs. 18000 then a surcharge of 15% will be charged on top of the bill.*/
#include <iostream>
using namespace std;
int main() {
    string cName; int cID, units; float charge, surcharge, bill, funits; 
    cout << "Customer ID: ";
    cin >> cID;
    cout << "Customer Name: ";
    cin >> cName;
    cout << "Units Consumed: ";
    cin >> units;
    funits = units;
    if (units < 200) {
        charge = 16.20;
        bill = funits * charge;
    }
    else if (units >= 200 && units < 300) {
        charge = 20.10;
        bill = funits * charge;
    }
    else if (units >= 300 && units < 500) {
        charge = 27.10;
        bill = funits * charge;
    }
    else {
        charge = 35.90;
        bill = funits * charge;
    }

    if (bill > 18000)
    {
        surcharge = 0.15 * bill;
    }

    cout << endl << "Customer ID : " << cID << endl;
    cout << "Customer Name: " << cName <<endl;
    cout << "Units Consumed: " << units <<endl;
    cout << "Amount Charges @Rs. " << charge << " per unit: " << bill << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount Paid by the Customer: " << bill + surcharge << endl; 
}