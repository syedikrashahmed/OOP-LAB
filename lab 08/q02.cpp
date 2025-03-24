#include <iostream>
using namespace std;
#include <string>

class Account {
    protected:
    string accountNumber;
    string accountHolder;
    double balance;

    public:
    Account(string accNumber, string accHolder, double bal) : accountNumber(accNumber), accountHolder(accHolder), balance(bal) {}

    Account() : accountNumber(""), accountHolder(""), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        balance -= amount;
    }

    Account operator+(const Account& other) {
        Account temp;
        temp.balance = balance + other.balance;
        temp.accountNumber = accountNumber + other.accountNumber;
        temp.accountHolder = accountHolder + other.accountHolder;   
        return temp;
    }

    Account &operator-=(double amount) {
        balance -= amount;
        return *this;
    }

    bool operator>(const Account& other) {
        return balance > other.balance;
    }

    friend ostream& operator<<(ostream& os, const Account& acc) {
        os << "Account Number: " << acc.accountNumber << endl;
        os << "Account Holder: " << acc.accountHolder << endl;
        os << "Balance: " << acc.balance << endl;
        return os;
    }
};

int main() {
    Account a1("12345", "Ikrash ", 5000.5);
    Account a2("678910", "Ahmed ", 400.0);

    cout << a1;
    cout << a2;

    Account a3 = a1 + a2;
    cout << a3;

    a1 -= 2000.0;
    cout << a1;

    if (a1 > a2) {
        cout << "Ikrash has more balance than Ahmed" << endl;
    } 
    else {
        cout << "Ahmed has more balance than Ikrash" << endl;
    }
    cout << "Final Details:" << endl;
    cout << a1;
    cout << a2;
    cout << a3;
}   