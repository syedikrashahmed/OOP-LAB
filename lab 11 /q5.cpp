#include <iostream>
#include <string>
using namespace std;

class InsufficientFundsException : public exception {
    public:
    const char* what() const noexcept override {
        return "InsufficientFundsException - amount to be withdraw is more than amount in balance";
    }
};

template <typename T>
class BankAccount {
    T balance;

    public:
    BankAccount(T balance) : balance(balance) {}

    void withdraw() {
        T amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "deficet is " << amount - balance << endl;
            throw InsufficientFundsException();
        }
        balance -= amount;
        cout << "withdarwed \nnew balance: " << balance << endl;
    }
};

int main() {
    BankAccount b(300.369);
    try {
        b.withdraw();
    }
    catch (const exception& e) {
        cerr << "error: " << e.what() << endl;
    }
}
