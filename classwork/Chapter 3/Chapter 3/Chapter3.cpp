#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
void main()
{
    std::cout << "enter values for x and y: ";
    double x, y;
    std::cin >> x >> y;
    
   /* std::cout << "Function" << "x" << "y" << "Result" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    std::cout << "pow " << x << y << pow(x, y) << std::endl;
    std::cout << "sqrt " << x << y << sqrt(x, y) << std::endl;
   
    std::cout << "ceil " << x << y << ceil(x, y) << std::endl;
    std::cout << "floor " << x << y << floor(x, y) << std::endl;

    std::cout << "round " << x << y << round(x, y) << std::endl;
    std::cout << "trunc " << x << y << trunc(x, y) << std::endl;
}
void ExpressionDemo()
{    
//*this code is not perfect be weary when studying, it has some sloppiness
   
    //promt user for radius of circle.
    std::cout << "Enter radius";

    //cin is used for input from user.
    int radius = 0;
    std::cin >> radius;

    
    //area = pi * r^2
    const double Pi = 3.14159;
    double area = Pi * radius * radius; 
    std::cout << "Ares = " << Pi << "*" << radius << "*" << radius << std::endl;
    std::cout << "Area = " << area << std::endl;


    //triangle 
    //area = 1/2 base * height

    std::cout << "Enter base and height of triangle";
    int base = 0, height = 0;
    std::cin >> base;
    std::cin >> height;
    
    
    area = (1 / 2) * base * height; 
    std::cout << "Area = " << area << std::endl;
    
    std::cout << "Enter name"; 
    //getline reads strings with spaces in them line and puts it into variable.
    //std::cin.ignore(), will throw out anything in the input buffer.
    std::string name;
    std::getline(std::cin, name);
    std::cin >> name;
    std::cout << name << std::endl;


    //overflow and underflow 
    short smallValue = 32767;
    smallValue = smallValue + 1;
    std::cout << smallValue << std::endl;

    short largeValue = -32768;
    largeValue = largeValue - 1;

    std::cout << smallValue << " " << largeValue << std::endl;

    //type coersion compiler implicitly converts an E to another type.doesnt care about how your going to use the type of the result (it is right associative).
    //type casting : when you explicitly covert an expressions type to another type.
    int left = 10;
    int right = 3;
    int intDivision = 10 / 3; //gives you an int
    //want a fraction? make one of the numbers a double or .0 on the end 
    double intDivison = 10 / 3.0; // gives you double
    //if your dealing with variables, go off how you expect to STORE IN THE VARIABLE. never change the type based on the outcome you want. 
    //type casting:
    intDivision = (double) left / right; // change the type proceeding your variable. THIS IS CALLED A "C-CAST." either side it doesnt matter.
    //alternate approach:
    static_cast<double>(left) / right; //both will have same effect.

    //setting percise decimal places for your outputs or anything else use std::setprecision,and std::fixed, THIS REQUIRES #INCLUDE <IOMANIP>


    //to include higher level math functions USE #inlcude <cmath>
    //math functions
    // pow(x, y) = power X to the Y power: the number then the power you want to raise it to. 


    /*
    YES OR NO QUESTIONS REQUIRE #include <cctype>, then use a do while loop.
    //
    MANIPULATORS:
    
    can use std::setw(?) to determine a number of spaces in an output
    you can also left or right align your setw outputs, proceed your functions with std::left or right, once applied they remain in place unless switched.
    std::setfill --padding value (persistent), can be used for hiding passwords 
    VALUE PERCISION:
    USE SET PERCISION- will format each of your floating point values to that percision.(std::setpercision(?))
    */


        cout << "is this a classic (y/n)? ";
    std::string input;
        cin >> input;
    if (_strcmpi(input.c_str(), "y") == 0)
        isClassic = true;
    else 
        if (_strcmpi(input.c_str(), "n") == 0)
        isClassic = false;
    else
        cout << "you must enter either y or n";
}
    void relationalDemo()
{
    cout << "enter two values: ";
    int left, right;
    cin >> left >> right

    }
    cout << "enter an optional user rating (1.0 - 10.0): ";
    cin >> userRating;
    if (userRating < 1.0)
    {
        cout << "Rating must be between 1.0 and 10.0" << endl;
        userRating = 1.0;
    }