/*TASK # 03
You are building a bank account management system. Create a class `Account` to manage bank
accounts.
Attributes:
     `accountNumber` (string)
     `accountHolderName` (string)
     `balance` (double)
    2. Define a default constructor that initializes `balance` to `0.0`.
    3. Define a parameterized constructor to initialize all attributes.
Add methods:
     `deposit(double amount)`: Adds the amount to the balance.
     `withdraw(double amount)`: Deducts the amount from the balance (if sufficient funds are
    available).
     `checkBalance()`: Displays the current balance.
Create a few `Account` objects and test the methods.*/

#include <iostream>
using namespace std;

class Account {
    string accountNumber;
    string accountHolderName;
    double balance;

    public:
    Account() {
        accountHolderName = "";
        accountNumber = "";
        balance = 0.0;
    }

    Account(string accNum, string accHN, double bal) {
        accountNumber = accNum;
        accountHolderName = accHN;
        balance = bal;
    }

    string getName() {
        return accountHolderName;
    }

    void deposit(double amount) {
        balance = balance + amount;
        
    }

    void withdraw(double amount) {
        if (amount<=balance){
            balance = balance - amount;
            cout << "remianing balance: " << balance;
            return;
        }
        cout <<"insufiicient balance " << endl;
    }

    void checkBalance () {
        cout << "current balance: " << balance;
    }
};

int main() {
    Account a1("123456", "syed", 700.0);
    Account a2("256413", "ikrash", 1980.0);
    Account a3("654123", "ahmed", 508.0);
    cout << "\nPerforming Transactions: " << endl;
    cout << "\nDepositing into " << a1.getName() << " account" << endl;
    a1.deposit(400);
    cout <<"Deposited" << endl;
    a1.checkBalance();
    cout << "\nWithdrawing from " << a2.getName() << " account" << endl;
    a2.withdraw(300);
    cout << endl;
    cout << "\nWithdrawing from " << a3.getName() << " account" << endl;
    a3.withdraw(100);
    cout << endl;
    cout << "\nall account balances" << endl;
    cout << a1.getName() << ": ";
    a1.checkBalance();
    cout << endl;
    cout << a2.getName() << ": ";
    a2.checkBalance();
    cout << endl;
    cout << a3.getName() << ": ";
    a3.checkBalance();
    cout << endl;
}
