/*Task-02: Create a class called LoanHelper, which helps the user calculate their loan payments. The classshould have a variable that stores interest rate for the loan as a user defined constant value. Asidefrom the that, it also stores the amount for the loan taken and amount of months that the user willrepay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rateshould be applied over the monthly return amount. The output should be something like:“You have to pay 999 every month for 12 monthsto repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rateshould be a value between 0-0.5%*/
#include <iostream>
using namespace std;

class LoanHelper {
    const float interestRate;  
    float loanAmount;         
    int repaymentMonths;      

public:
    LoanHelper(float rate, float amount, int months) : interestRate(rate), loanAmount(amount), repaymentMonths(months) {
        if (interestRate < 0 || interestRate > 0.5) {
            cout << "Error: Interest rate must be between 0 and 0.5%." << endl;
            return;
        }
    }

    void calculateMonthlyPayment() {
        float baseMonthlyPayment = loanAmount / repaymentMonths;
        float monthlyPaymentWithInterest = baseMonthlyPayment * (1 + interestRate / 100);
        cout << "You have to pay " << monthlyPaymentWithInterest
             << " every month for " << repaymentMonths
             << " months to repay your loan." << endl;
    }
};

int main() {
    LoanHelper loan(0.2, 10989, 12); 
    loan.calculateMonthlyPayment();
}
