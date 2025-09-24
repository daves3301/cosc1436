/*
David petroff
Lab 1
COSC 1436 FALL 2025
9/4/25
*/

#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <cctype>

int main()
{
   
    cout << "please enter your name:";   //requesting name from user then storing it.
    string studentName;
    
    std::getline(cin, studentName);

    double Lab1, Lab2, Lab3, Lab4;                     //requesting lab grades then storing them.
    cout << "please enter your grade for Lab 1:";
    cin >> Lab1;
    cout << "please enter your grade for Lab 2:";
    cin >> Lab2;
    cout << "please enter your grade for Lab 3:";
    cin >> Lab3;
    cout << "please enter your grade for Lab 4:";
    cin >> Lab4;
    
    double Exam1, Exam2, Exam3;                 //requesting exam values the storing them.
    cout << "please enter your grade for Exam 1:";
    cin >> Exam1;
    cout << "please enter your grade for Exam 2:";
    cin >> Exam2;
    cout << "please enter your grade for Exam 3:";
    cin >> Exam3;
    
    double Participation;                                          //requesting participation grade.
        std::cout << "please enter your participation grade:";
    cin >> Participation;
    
    double Final;
    cout << "Please enter your Final Exam grade:";
    cin >> Final;                                               //requesting final grade.

    cout << studentName << " Your Lab grades are:" << endl;             //outputting lab grades.
    cout << "Lab 1: " <<Lab1 << endl;
    cout << "Lab 2: " <<Lab2 << endl;
    cout << "Lab 3: " <<Lab3 << endl;
    cout << "Lab 4: " <<Lab4 << endl;

    cout << studentName << " Your Exam grades are:" << endl;            //outputting exam grades
    cout << "Exam 1: " <<Exam1 << endl;
    cout << "Exam 2: " <<Exam2 << endl;
    cout << "Exam 3: " <<Exam3 << endl;

    cout << studentName << " Your other grades are:" << endl;
    cout << "Participation: " << Participation << endl;        //outputting other grades.
    cout << "Final Exam: " << Final << endl;
    
    double LabAvg, ExamAvg, ClassAvg;                           //declaring avg variables
   
    LabAvg = (Lab1 + Lab2 + Lab3 + Lab4) / 4;                        //calculating averages.
    
    ExamAvg = (Exam1 + Exam2 + Exam3) / 3;
    
    ClassAvg = (LabAvg * .65)+(ExamAvg * .20)+(Participation * .05)+(Final * .10) / 4;
        
    cout << studentName << ", Your class grades are: " << endl; //outputting student grades.
    cout << std::fixed << std::setprecision(2);
    cout << "Lab Average (65%): " << LabAvg << "%" << endl;
    cout << "Exam Average (20%): " << ExamAvg << "%" << endl;
    cout << "Participation (5%): " << Participation << "%" << endl;
    cout << "Final Exam (10%): " << Final << "%" << endl;
    cout << "Class Average: " << ClassAvg << "%" << endl;

    
        return 0;
}