#include <iostream>
using namespace std;
#include <string>

class BankAccount {
    protected:
    string accountNumber;
    double balance;

    public:
    BankAccount() : accountNumber(""), balance(0.0) {}

    BankAccount(string accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}
    
    virtual void calculateInterest() {}

/*  o Deposit via cash
    o Deposit via check
    o Deposit via online transfer*/

    void deposit(double amount) {
        balance += amount;
    }

    void deposit(double amount, string accountNumber) {
        if (this->accountNumber == accountNumber) {
            balance += amount;
        }
        else {
            cout << "Invalid account number" << endl;
        }
    }

    void deposit() {
        double amount;
        cout << "Enter amount: ";
        cin >> amount;
        balance += amount;
    }

/*Override the withdraw method in both derived classes with different rules:
    o SavingsAccount: Cannot withdraw if balance is below $500
    o CurrentAccount: Allows overdraft up to $1000*/

    virtual void withdraw(double amount) {
        balance -= amount;
    }

    friend double operator + (BankAccount &account1, BankAccount &account2);
    friend double operator - (BankAccount &account1, double amount);
    friend double operator * (BankAccount &account1, float interestRate);
    friend double operator / (BankAccount &account1, int installment);

    double getBalance() {
        return balance;
    }
};

/*o SavingsAccount (Interest: 5% per year)
o CurrentAccount (Interest: No interest)*/

class SavingsAccount : public BankAccount {
    float interestRate;

    public:
    SavingsAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance), interestRate(0.5) {}

    SavingsAccount() : BankAccount(), interestRate(0.5) {}

    void calculateInterest() {
        balance += balance * interestRate / 100;
    }

    void withdraw(double amount) {
        if (balance < 500) {
            cout << "Cannot withdraw if balance is below $500" << endl;
        }   
        else {
            balance -= amount;
        }
    }
};

class CurrentAccount : public BankAccount {
    float interestRate; 
    double overdraft;  
    
    public:
    CurrentAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance), interestRate(1) {}

    CurrentAccount() : BankAccount(), interestRate(1), overdraft(0) {}

    void calculateInterest() {
        balance += balance * interestRate / 100;
    }

    void withdraw(double amount) {
        if (overdraft > 1000) {
            cout << "Cannot withdraw if overdraft is above $1000" << endl;
        }
        else {
            balance -= amount;
            overdraft += amount;
        }
    }
};

// + to add two account balances
double operator + (BankAccount &account1, BankAccount &account2) {
    return account1.balance + account2.balance;
}

// - to subtract an amount from balance
double operator - (BankAccount &account1, double amount) {
    account1.balance -= amount;
    return account1.balance;
}

// * to apply interest on balance
double operator * (BankAccount &account1, float interestRate) {
    account1.balance *= interestRate;
    return account1.balance;
}

// / to calculate equal installment payments from balance
double operator / (BankAccount &account1, int installment) {
    return account1.balance / installment;
}

/*Create objects of both SavingsAccount and CurrentAccount, demonstrate method
overloading, overriding, and operator overloading with real transaction examples.*/

int main() {
    SavingsAccount saveacc("SA1234", 600.0);
    CurrentAccount curracc("CA5678", 600.0);
    
    cout << "Initial balances:" << endl;
    cout << "Savings Account: $" << saveacc.getBalance() << endl;
    cout << "Current Account: $" << curracc.getBalance() << endl << endl;
    
    cout << "Making deposits:" << endl;
    saveacc.deposit(200.0);  
    cout << "Savings after cash deposit: $" << saveacc.getBalance() << endl;
    
    saveacc.deposit(300.0, "SA1234");  
    cout << "Savings after check deposit: $" << saveacc.getBalance() << endl;
    
    saveacc.deposit();  
    cout << "Savings after online deposit: $" << saveacc.getBalance() << endl << endl;
    
    cout << "Attempting withdrawals:" << endl;
    saveacc.withdraw(400.0);  
    cout << "Savings after valid withdrawal: $" << saveacc.getBalance() << endl;
    
    saveacc.withdraw(300.0);  
    cout << "Savings after blocked withdrawal: $" << saveacc.getBalance() << endl;
    
    curracc.withdraw(800.0);  
    cout << "Current after overdraft withdrawal: $" << curracc.getBalance() << endl;
    
    curracc.withdraw(300.0);  
    cout << "Current after blocked overdraft: $" << curracc.getBalance() << endl << endl;
    
    cout << "Operator overloading demonstrations:" << endl;
    double total = saveacc + curracc;
    cout << "Combined balance (+ operator): $" << total << endl;
    
    double new_balance = saveacc - 100.0;
    cout << "Savings after - operator: $" << new_balance << endl;
    
    double with_interest = saveacc * 1.05f;  
    cout << "Savings with interest (* operator): $" << with_interest << endl;
    
    double installment = saveacc / 4;  
    cout << "Equal installments (/ operator): $" << installment << endl << endl;
    
    cout << "Calculating interest:" << endl;
    cout << "Savings before interest: $" << saveacc.getBalance() << endl;
    saveacc.calculateInterest();
    cout << "Savings after interest: $" << saveacc.getBalance() << endl;
    
    cout << "Current before interest: $" << curracc.getBalance() << endl;
    curracc.calculateInterest();
    cout << "Current after interest: $" << curracc.getBalance() << endl;
}
