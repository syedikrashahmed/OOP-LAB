#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    float amount;
    string currencyCode;
    string currencySymbol;
    float exchangeRate; 

public:
    Currency(float amt, string code, string symbol, float rate) : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual void convertToBase() {
        amount *= exchangeRate; 
    }

    virtual void convertTo(Currency &targetCurrency) {
        convertToBase(); 
        amount = amount / targetCurrency.exchangeRate; 
        currencyCode = targetCurrency.currencyCode;
        currencySymbol = targetCurrency.currencySymbol;
        exchangeRate = targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() {
        cout << "Currency Details: " << endl
             << "Amount: " << amount << endl
             << "Currency Code: " << currencyCode << endl
             << "Currency Symbol: " << currencySymbol << endl
             << "Exchange Rate: " << exchangeRate << endl << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(float amt) : Currency(amt, "USD", "$", 1.0) {} 

    void convertToBase() override {
        cout << "Dollar is the base currency" << endl << endl;
    }

    void displayCurrency() override {
        cout << "Dollar Currency Details: " << endl
             << "Amount: " << amount << endl
             << "Currency Code: " << currencyCode << endl
             << "Currency Symbol: " << currencySymbol << endl
             << "Exchange Rate: " << exchangeRate << endl << endl;
    }
};

class Euro : public Currency {
public:
    Euro(float amt) : Currency(amt, "EUR", "E", 0.85) {} 

    void convertToBase() override {
        amount *= exchangeRate; 
        cout << "Converted base currency" << endl << endl;
    }

    void displayCurrency() override {
        cout << "Euro Currency Details: " << endl
             << "Amount: " << amount << endl
             << "Currency Code: " << currencyCode << endl
             << "Currency Symbol: " << currencySymbol << endl
             << "Exchange Rate: " << exchangeRate << endl << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(float amt) : Currency(amt, "PKR", "RS", 74.5) {} 

    void convertToBase() override {
        amount *= exchangeRate; 
        cout << "Converted to base currency" << endl << endl;
    }

    void displayCurrency() override {
        cout << "Rupee Currency Details: " << endl
             << "Amount: " << amount << endl
             << "Currency Code: " << currencyCode << endl
             << "Currency Symbol: " << currencySymbol << endl
             << "Exchange Rate: " << exchangeRate << endl << endl;
    }
};

int main() {
    Dollar usd(100.0);
    Euro eur(85.0);
    Rupee pkr(7450.0);

    usd.displayCurrency();
    eur.displayCurrency();
    eur.convertToBase(); 
    eur.displayCurrency();

    pkr.displayCurrency();
    pkr.convertToBase(); 
    pkr.displayCurrency();

    usd.convertTo(eur);
    usd.displayCurrency();

    usd.convertTo(pkr);
    usd.displayCurrency();
}