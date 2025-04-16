#include <iostream>
using namespace std;

class PaymentMethod {
    public:
    PaymentMethod() {}

    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod {
    string cardNumber;

    public:
    CreditCard() : PaymentMethod(), cardNumber("") {}

    CreditCard(string cardNumber) : PaymentMethod(), cardNumber(cardNumber) {}

    void processPayment(double amount) override {
        cout << "processing payment pkr " << amount << " for user " << cardNumber << endl;
    }
};

class DigitalWallet : public PaymentMethod {
    double balance;

    public:
    DigitalWallet() : balance(0.0), PaymentMethod() {}

    DigitalWallet(double balance) : PaymentMethod(), balance(balance) {}

    void processPayment(double amount) override {
        if (amount > balance) {
            cout << "insufficient funds. payment processing failed" << endl;
            return;
        }
        balance -= amount;
        cout << "payment " << amount << " processed, new acount balance: " << balance << endl;
    }
};

int main() {
    CreditCard card1("9999999999");
    DigitalWallet wallet1(10000.0);

    cout << " Credit Card payment:" << endl;
    card1.processPayment(4000.0); 
    cout << endl;

    cout << " Digital Wallet payment:" << endl;
    wallet1.processPayment(5000.0); 
    wallet1.processPayment(6000.0);  
    wallet1.processPayment(1000.0);  
}