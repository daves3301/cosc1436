/*
David Petroff
COSC 1436 Fall
Lab 2
9/23/25
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double loan;
    double interest;
    double payment;

    while(true)
    {
    cout << "Please enter a loan amount: " << endl; //limit it between 1- 1000$
    cin >> loan;
    
    if (loan < 1 || loan > 1000)
    {
        cout << "ERROR: Loan amount must be between $1 - $1000" << endl;
        loan = 1;
    } else 
    {
        break;
    }
}
    while (true)
    {
    cout << "Please enter an interest rate(%): " << endl;
    cin >> interest;

    if (interest < 1.0 || interest > 100.0)
    {
        std::cout << "ERROR: interest rate must be between 1.0% - 100.0%" << endl;
        interest = 0.0;
    } 
    interest /= 100.0;
   
    cout << "How much do you want to pay each month?: " << endl;        //no negatives allowed 
    cin >> payment;
    if (payment < 0 || payment > loan)
    {
        cout << "ERROR: payment must be between $0 - loan amount" << endl;
        payment = 1.0;
    }
    else {
        break;
    }
}
    cout << fixed << setprecision(2);
    cout << "\nMonth   Balance        Payment        Interest       New Balance\n";         //menu
    cout << "----------------------------------------------------------------------\n";

    double balance = loan;
    double totalInterest = 0.0;
    double totalPayments = 0.0;

    for (int month = 1; month <= 12; ++month)
    {
        double monthlyPayment;
        double interest = 0.0;
        double newBalance = balance;

        if (month == 1)
        {
            interest = 0.0;
            newBalance = balance;
            monthlyPayment = 0.0;
        }

            if (balance > 0) {
                if (monthlyPayment > balance) {

                    monthlyPayment = balance;


                    newBalance = balance - monthlyPayment;
                    interest = newBalance * interest;

                    newBalance += interest;

                    totalPayments += monthlyPayment;                        //calculating totals
                    totalInterest += interest;
                }
            }
        }
        cout << setw(2) << month << "      $ " << setw(8) << balance            //formatting 
            << "      $ " << setw(8) << monthlyPayment
            << "      $ " << setw(8) << interest
            << "      $ " << setw(8) << newBalance << endl;

        balance = newBalance;
    }
    if (balance <= 0) 
    {
        balance = 0;
    }
    cout << "---------------------------------------------------------\n";
    cout << "Total                   $" << setw(8) << totalPayments
    << "   $ " << setw(8) << totalInterest << endl;
    return 0;
}