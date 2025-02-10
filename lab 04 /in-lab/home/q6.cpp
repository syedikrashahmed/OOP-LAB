/*TASK # 06
Scenario: A bank wants to develop a system for managing customer accounts. The system
should allow customers to:
1. Create a new account with an account number, owner’s name, and initial balance
(default balance is 0 if not provided).
2. Deposit money into their account.
3. Withdraw money from their account, ensuring they cannot withdraw more than the
available balance.
4. Display account details including account number, owner’s name, and current balance.*/

#include <iostream>
using namespace std;
#include <string>

class Account {
    int accountNumber;
    string ownerName;
    double balance;

    public:
    Account() {
        accountNumber = 0;
        ownerName = "";
        balance = 0;
    }

    Account(int aN, string n, double bal) {
        accountNumber = aN;
        ownerName = n;
        balance = bal;
    }

    void Deposit(double amount) {
        balance = balance + amount;
        cout << "Amount Deposited Successfully" << endl;
    }

    void Withdraw(double amount) {
        if (amount <= balance) {
            balance = balance - amount;
            cout << "Amount Withdrawen Successfully" << endl;
        }
        cout << "Unsuccessful Withdrawal! amount more than balance" << endl;
    }

    void Display() {
        cout << "Displaying Account Details:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Account a1(998, "ikrash", 4000.0);
    a1.Display();
    cout << endl;
    a1.Deposit(200.0);
    a1.Display();
    cout << endl;
    a1.Withdraw(100.0);
    a1.Display();
}
