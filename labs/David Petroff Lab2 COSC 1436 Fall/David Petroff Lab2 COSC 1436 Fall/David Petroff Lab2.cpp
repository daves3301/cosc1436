/*
David Petroff
COSC 1436 Fall
Lab 2
9/23/25
*/
#include <iostream>
#include <iomanip>

int main()
{
    int loan = 0;           //declaring loan variables
    double interest = 0.0;
    double payment = 0.0;

    while(true)                                     //loan conditions 
    {
    std::cout << "Please enter a loan amount: " << std::endl; //limit it between 1- 1000$
    std::cin >> loan;
    
    if (loan < 1 || loan > 1000)
    {
        std::cout << "ERROR: Loan amount must be between $1 - $1000" << std::endl;
        loan = 1;
    } else 
    {
        break;
    }
}
    while (true)
    {
        std::cout << "Please enter an interest rate(%): " << std::endl;           //interest conditions
        std::cin >> interest;

        if (interest < 1.0 || interest > 100.0)
        {
            std::cout << "ERROR: interest rate must be between 1.0% - 100.0%" << std::endl;
            interest = 0.0;
        } else
        {
            interest /= 100.0;                                          //converting to decimal
            break;
        }
    }
    while (true)
    {
        std::cout << "How much do you want to pay each month?: " << std::endl;        //no negatives allowed 
        std::cin >> payment;

        if (payment < 0 || payment > loan)
        {
            std::cout << "ERROR: payment must be between $0 - loan amount" << std::endl;
            payment = 1.0;
        } else {
            break;
        }
    }
    std::cout << std::fixed << std::setprecision(2);                                                   //table header
    std::cout << "\nMonth   Balance        Payment        Interest       New Balance\n";
    std::cout << "----------------------------------------------------------------------\n";

    double balance = loan;                                                              //balances & totals
    double totalInterest = 0.0;
    double totalPayments = 0.0;

    for (int month = 1; month <= 12; ++month)
    {
        double monthlyPayment = 0.0;
        double monthlyInterest = 0.0;
        double newBalance = balance;

        if (month == 1)                                                                 //no payments or interest yet
        {
            monthlyInterest = 0.0;
            newBalance = balance;
            monthlyPayment = 0.0;
        } 
        else if (balance > 0)
        {
            monthlyPayment = (payment > balance) ? balance: payment;                //preventing paying more than balance

            newBalance = balance - monthlyPayment;                                  //balance - payment before calculating interest

            if (newBalance > 0)                                                     //calculating interest
            {

                monthlyInterest = newBalance * interest;
            }
                newBalance += monthlyInterest;

                totalPayments += monthlyPayment;
                totalInterest += monthlyInterest;
            } 
        else                                                                        //once balance is 0, no more payments or interest
        {
                monthlyPayment = 0.0;
                monthlyInterest = 0.0;
                newBalance = 0.0;
        }
        std::cout << std::setw(2) << month << "      $ " << std::setw(8) << balance                //formatting 
            << "      $ " << std::setw(8) << monthlyPayment
            << "      $ " << std::setw(8) << monthlyInterest
            << "      $ " << std::setw(8) << newBalance << std::endl;

        balance = newBalance;                                                       //updating balance
    }

    std::cout << "---------------------------------------------------------\n";
    std::cout << "Total                   $" << std::setw(8) << totalPayments
         << "    $ " << std::setw(8) << totalInterest << std::endl;
    return 0;
}
