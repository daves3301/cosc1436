/*
David petroff
Lab 1
COSC 1436 FALL 2025
9/4/25
*/

#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    string name;
    cout << "please enter your name:";
    cin >> int name;
    int Lab1, Lab2, Lab3, Lab4;
    cout << "please enter your grade for Lab 1:";
    cin >> Lab1;
    cout << "please enter your grade for Lab 2:";
    cin >> Lab2;
    cout << "please enter your grade for Lab 3:";
    cin >> Lab3;
    cout << "please enter your grade for Lab 4:";
    cin >> Lab4;
    
    int Exam1, Exam2, Exam3, Exam4;
    cout << "please enter your grade for Exam 1:";
    cin >> Exam1;
    cout << "please enter your grade for Exam 2:";
    cin >> Exam2;
    cout << "please enter your grade for Exam 3:";
    cin >> Exam3;
    cout << "please enter your grade for Exam 4:";
    cin >> Exam4;
    
    int part
        std::cout << "please enter your participation grade:";
    cin >> part;
    
    int Final;
    cout << "Please enter your Final Exam grade:";
    cin >> Final; 

    cout << name << " Your Lab grades are:";
    cout << Lab1;
    cout << Lab2;
    cout << Lab3;
    cout << Lab4;

    cout << name << "Your Exam grades are:";
    cout << Exam1;
    cout << Exam2;
    cout << Exam3;
    cout << Exam4;

    cout << name << "Your other grades are:";
    cout << "Participation: " << part;
    cout << "Final Exam: " << Final;
    float LabAvg, ExamAvg, ClassAvg;
    LabAvg = Lab1, Lab2, Lab3, Lab4 / 4;
    ExamAvg = Exam1, Exam2, Exam3, Exam4 / 4;
    ClassAvg = 
        cout << name << ", Your class grade is: ";
        cout << "Lab Average (65%): " << LabAvg;
        cout << "Exam Average (20%): " << ExamAvg;
        cout << "Participation (5%): " << part;
        cout << "Class Average: " << ClassAvg;

}