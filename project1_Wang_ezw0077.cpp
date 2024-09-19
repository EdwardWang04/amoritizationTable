/*Edward Wang
ezw0077@auburn.edu
project1_Wang_ezw0077.cpp*/
#include <iostream>
#include <iomanip>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

int main()
{

    // initializing necessary values
    double debt = 0.0;
    double interestPerYear = -1.0;
    double monthlyPayments = 0.0;
    double interest = 0.0;
    double totalInterestPaid = 0.0;
    int month = 0;

    // prevents loan from being negative
    while (debt <= 0)
    {
        cout << "Loan Amount: ";
        cin >> debt;
        if (debt <= 0)
        {
            cout << "Loan Amount should be positive!";
            cout << "\n";
        }
    }

    // prevents interest rate from being negative or zero
    while (interestPerYear < 0)
    {
        cout << "Interest Rate (% per year): ";
        cin >> interestPerYear;
        if (interestPerYear < 0)
        {
            cout << "Interest Rate should not be negative!";
            cout << "\n";
        }
    }

    interest = (interestPerYear / 12) / 100;

    // prevents monthly payment from being negative and also makes sure that monthly payment is large enough
    while (monthlyPayments < debt * interest || monthlyPayments <= 0)
    {
        cout << "Monthly Payments: ";
        cin >> monthlyPayments;

        if (monthlyPayments <= 0)
        {
            cout << "Monthly Payments should be positive!";
            cout << "\n";
        }

        else if (monthlyPayments < debt * interest)
        {
            cout << "Make a larger monthly payment!";
            cout << "\n";
        }
    }
    // rounds all numbers to two decimal points
    cout << fixed << setprecision(2);

    // table
    cout << "********************************************************" << endl;
    cout << "       Amortization Table" << endl;
    cout << "********************************************************" << endl;
    cout << setw(6) << left << "Month"
         << setw(15) << left << "Balance"
         << setw(12) << left << "Payment"
         << setw(6) << left << "Rate"
         << setw(12) << left << "Interest"
         << setw(12) << left << "Principal" << endl;

    cout << setw(6) << left << month
         << "$" << setw(14) << left << debt
         << setw(12) << left << "N/A"
         << setw(6) << left << "N/A"
         << setw(12) << left << "N/A"
         << setw(12) << left << "N/A" << endl;

    // loop that calculates interest and principal
    while (debt > 0)
    {
        double monthlyInterest = debt * interest;
        double principal = monthlyPayments - monthlyInterest;

        // calculates monthly payments when needed
        if (debt - principal < 0)
        {
            principal = debt;
            monthlyPayments = principal + monthlyInterest;
        }

        debt -= principal;
        totalInterestPaid += monthlyInterest;

        month++;

        // looping of amoritization table
        cout << setw(6) << left << month
             << "$" << setw(14) << left << debt
             << "$" << setw(11) << left << monthlyPayments
             << setw(6) << left << interest * 100
             << "$" << setw(11) << left << monthlyInterest
             << "$" << setw(11) << left << principal << endl;
    }

    // final output that tells user the amount of months it took to finish paying and total interest paid
    cout << "********************************************************" << endl;
    cout << "It takes " << month << " months to pay off the loan." << endl;
    cout << "Total interest paid is: $" << totalInterestPaid << endl;
}

/// SOURCES

/*1. "What AI service. i.e. ChatGPT": I used ChatGPT
2. "What questions/code issues you have":I asked how to neatly format the amoritization table
3. What keywords/statement you entered: The statement i used is:
"How can I make a table a 'left lined-up style' one"

4. How solutions from AI technology are integrated in your code. Please explain this part based on
your solutions

It allowed my code to 'match the style of the sample output (including a left lined-up style)' in the instructions
*/