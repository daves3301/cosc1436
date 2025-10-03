/*
David Petroff
COSC 1436 Fall
Lab 2
9/23/25
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    float loan;
    float interest;
    float payment;
    do {
        std::cout << "Please enter a loan amount: " << endl; //limit it between 1- 1000$
        std::cin >> loan;
        if (loan < 1 || loan > 1000)
        {
            std::cout << "ERROR: Loan amount must be between $1 - $1000" << endl;
            loan = 1;
        }
        while (loan < 1 || loan > 1000);
    }

    do {
        std::cout << "Please enter an interest rate(%): " << endl;
        std::cin >> interest;
        if (interest > 1.0 || interest < 100)
        {
            std::cout << "ERROR: interest rate must be between 1.0% - 100.0%" << endl;
            interest = 1.0;
        }
        while (interest > 1.0 || interest < 100);
    }

    do {
        std::cout << "How much do you want to pay each month?: " << endl;        //no negatives allowed 
        std::cin >> payment;
        if (payment < 0 || payment > loan)
        {
            std::cout << "ERROR: payment must be between $0 - loan amount" << endl;
            payment = 1;
        }
        while (payment < 0 || payment > loan);
    }
                                                                            //display loan table
}

