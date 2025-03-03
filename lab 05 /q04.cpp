/*Task-04: Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber, accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the accountdetails (accountNumber, accountHolderName, and balance).
Create following Member Functions:
    • deposit(double amount): Adds the specified amount to the account balance.
    • withdraw(double amount): Subtracts the specified amount from the account balance, if sufficient funds are available.
    • display(): Displays the account details including the account number, account holder name, and balance.
    
In the main() function, create an array accounts of BankAccount objects. The array contains three elements, each representing a different bank account. Initialize Each BankAccount object with specific account details such as account number, holder name, and initial balance.
Perform following operations:
    • Iterate through each account in the accounts array.
    • For each account, display the account details using the display() function.
    • Perform Two Transactions:
    • Deposits 500.0 rupees into the account.
    • Withdraws 200.0 rupees from the account.
    • After each transaction, display the updated account details, including the new balance.*/

#include <iostream>
using namespace std;

class BankAccount {
    string accountNumber;
    string accHolderName;
    float balance;

public:
    BankAccount(string accountNumber, string accHolderName, float balance)
        : accountNumber(accountNumber), accHolderName(accHolderName), balance(balance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Updated balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
        } else {
            cout << "Withdrawal failed. Insufficient funds or invalid amount." << endl;
        }
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount accounts[3] = {
        BankAccount("111222333", "Hasan Raheem", 2500.0),
        BankAccount("444555666", "Maanu", 3000.0),
        BankAccount("777888999", "Frank Ocean", 5000.0)
    };

    for (int i = 0; i < 3; i++) {
        cout << "Initial Account Details:" << endl;
        accounts[i].display();
        cout << endl;

        cout << "Depositing 500.0 rupees" << endl;
        accounts[i].deposit(500.0);
        cout << "Updated Account Details:" << endl;
        accounts[i].display();
        cout << endl;

        cout << "Withdrawing 200.0 rupees" << endl;
        accounts[i].withdraw(200.0);
        cout << "Updated Account Details:" << endl;
        accounts[i].display();
    }
}
