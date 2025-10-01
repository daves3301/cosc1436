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
    int loan;
    int interest;
    int payment;
    cout << "Please enter a loan amount: " << endl;  //limit it between 1- 1000$
    cin >> loan;
    cout << "Please enter an interest rate(%): " << endl;
    cin >> interest;
    cout << "How much do you want to pay each month?: " << endl;        //no negatives allowed 
    cin >> payment;


