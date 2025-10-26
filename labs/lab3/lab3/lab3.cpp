/*
Lab 3 : Falling Distance calculator
David Petroff
COSC 1436 Fall 2025
10/22/25
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//declaring constants
const double GRAVITY = 9.8;
const double METER_TO_FEET = 3.28084;

/// <summary>collecting & validating time info. </summary>
/// <returns>Returns valid falling time in seconds.</returns>
int getFallingTime() {
    int time;
    bool valid = false;
    while (!valid) {
        cout << "Please enter the number of seconds spent falling(1 - 60): ";
        cin >> time;

        if (cin.fail() || time < 1 || time > 60) {
            cout << "Oops! Error: must be a value between 1 - 60.\n";
            cin.clear();                    //clearing error flags & ignoring invalid input
            cin.ignore(1000, '\n');
        } else {
            valid = true;
        }
    }
    return time;
}

/// <summary>requests to display results in meters or feet. case-insensitive, then validates. </summary>
/// <returns>choice 'm'(meters) or 'f'(feet)</returns>
char getUnitChoice() {
    char choice;
    bool valid = false;

    while (!valid) {
        cout << " Do you want your results in meters or feet? (m/f): ";
        cin >> choice;
        choice = toupper(choice);   //converting input to uppercase

        if (choice == 'M' || choice == 'F') {
            valid = true;
        } else {
            cout << "Oops! Error: Please enter 'm' for meters or 'f' for feet.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return choice;
}

/// <summary>calculate falling distance for provided time(seconds). </summary>
/// <param name="distance"></param>
/// <returns>distance in meters</returns>
double calculateFallingDistance(int time) {
    double distance = 0.5 * GRAVITY * pow(time,2);   //squaring time
    return distance;
}

/// <summary>calculating velocity of falling object, capped at 90 m/s. </summary>
/// <param name="velocity"></param>
/// <returns>velocity in m/s.</returns>
double calculateVelocity(int time) {
    double velocity = GRAVITY * time;
    if (velocity > 90.0)
        velocity = 90.0;
    return velocity;
}
/// <summary>Converts meters to feet. </summary>
/// <param name="conversion"></param>
/// <returns>the conversion.</returns>
double convertMetersToFeet(double meters) {
    return meters * 3.28084;
}
/// <summary>Displays the falling distance & velocity for each second. </summary>
/// <param name="TotalTime">Total falling time in seconds</param>
/// <param name="unitChoice">'M' for meters or 'F' for feet</param>
    void displayResultsTable(int totalTime, char unitChoice) {
    string unitName = (unitChoice == 'M') ? "m" : "ft";
    string velocityUnit = (unitChoice == 'M') ? "m/s" : "ft/s";
    
                                                                //Diplsay header
    
    cout << "\nSeconds" << setw(15) << "Distance" << setw(15) << "Velocity" << endl;
    cout << " ============================================" << endl;
                                                               //Calculate/display results
    for (int t = 1; t <= totalTime; ++t) {
        double distance = calculateFallingDistance(t);
        double velocity = calculateVelocity(t);

        if (unitChoice == 'F') {                                    //conversion if needed
            distance = convertMetersToFeet(distance);
            velocity= convertMetersToFeet(velocity);
        }
        
        cout << fixed << setprecision(2);                            //decimal percision in display
        cout << setw(4) << t
            << setw(15) << distance << " " << unitName
            << setw(12) << velocity << " " << velocityUnit << endl;
    }
}

/// <summary>Collect falling time & unit choice, Dipslay results table, Exit. </summary>
int main() {

    int time = getFallingTime();                //collect falling time
    char unitChoice = getUnitChoice();          //collect unit choice

    displayResultsTable(time, unitChoice);      //displaying table 

    cout << "\nProgram completed. Later Gator!.\n";
    return 0;
}