
/*
Lab 4 - Number Analysis Program
David Petroff
COSC 1436
Fall 2025

This program allows the user to enter up to 100
integers, then provides menu options to calculate 
largest, smallest, sum, mean, view their values,
as well as enter new ones.
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 100;   //max number of values user can enter


void displayProgramInfo();
int inputValues(int arr[], int maxSize);
char displayMenu();
int getLargest(const int arr[], int count);
int getSmallest(const int arr[], int count);
int getSum(const int arr[], int count);
double getMean(const int arr[], int count);
void viewValues(const int arr[], int count);
int insertValues(int arr[], int count, int maxSize);

/*FUNCTION DEFINITIONS*/

void displayProgramInfo() { 
    cout << "=========================================\n";
    cout << "        Lab 4 - Number Analyzer\n";
    cout << "        David Petroff\n";
    cout << "        COSC 1436 Fall 2025\n";
    cout << "=========================================\n";
}

/// <summary>
/// Prompts user to enter integers into an array.
/// stops when user enters 0.
/// Validates input, Rejects negatives.
/// </summary>
/// <param name="arr"></param>
/// <param name="maxSize"></param>
/// <returns>The number of valid values entered</returns>
int inputValues(int arr[], int maxSize) {
    int value;
    int count = 0;  

    while (count < maxSize) {
        cout << "Enter a value: ";
        cin >> value;

        while (!cin) {  //validating input
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Oops! Invalid input. Enter an integer: ";
            cin >> value;
        }

        if (value == 0) {   //stop at 0
            break;
        } else if (value < 0) { //Rejects negatives
            cout << "Yikes! You must enter a value greater than or equal to 0\n";
        } else {                //valid number? store it in array
            arr[count] = value;
            count++;
        }
    }

    return count;   //total values stored
}

/// <summary>
/// Displays the main menu and returns users choice.
/// Converts input to upper-case
/// </summary>
/// <returns>Selected menu option as char</returns>
char displayMenu() {
    char choice;
    cout << "\nMain Menu\n";
    cout << "-----------------\n";
    cout << "L) Largest\n";
    cout << "S) Smallest\n";
    cout << "A) Add (Sum)\n";
    cout << "M) Mean\n";
    cout << "V) View Values\n";
    cout << "I) Insert New Values\n";
    cout << "Q) Quit\n";
    cout << "Enter choice: ";
    cin >> choice;

    return toupper(choice); //convert to uppercase
}

/// <summary>
/// Returns the largest value in the array.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
/// <returns>The largest integer</returns>
int getLargest(const int arr[], int count) {    
    
    int largest = arr[0];   //start with first element
    for (int i = 1; i < count; i++) {   //loop through to find max 
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}

/// <summary>
/// Returns the smallest value in the array.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
/// <returns>The smallest integer</returns>
int getSmallest(const int arr[], int count) {
    
    int smallest = arr[0];
    for (int i = 1; i < count; i++) {   //loop through to find min
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    return smallest;
}

/// <summary>
/// Computes the sum of the values in the array
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
/// <returns>returns the total sum.</returns>
int getSum(const int arr[], int count) {
   
    int sum = 0;
    for (int i = 0; i < count; i++) //add all numbers into sum
        sum += arr[i];
    return sum;
}

/// <summary>
/// Computes the average of the values in the array.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
/// <returns>The mean value as a double.</returns>
double getMean(const int arr[], int count) {
   
    int sum = getSum(arr, count);   //Reuse getSum
    return static_cast<double>(sum) / count;    //converting to double
}

/// <summary>
/// Displays all values in the array.
/// values are printed 10 per line.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
void viewValues(const int arr[], int count) {
    if (count == 0) {       //nothing to display if array is empty
        cout << "Welp:/ No values to display.\n";
        return;
    }

    for (int i = 0; i < count; i++) {   //print 10 per line
        cout << setw(5) << arr[i];
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}

/// <summary>
/// Allows user to add additional values into array.
/// Still stops on 0 & rejects negatives.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
/// <param name="maxSize"></param>
/// <returns>The new count of values stored.</returns>
int insertValues(int arr[], int count, int maxSize) {
    
    if (count >= maxSize) { //No space left
        cout << "Dang! Array is already full. Cannot insert more values.\n";
        return count;
    }

    int value;

    while (count < maxSize) {   //continue if while theres space
        cout << "Enter a value: ";
        cin >> value;

        while (!cin) {  //validate input
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Whoops! Invalid input. Enter an integer: ";
            cin >> value;
        }

        if (value == 0) //stop at 0
            break;

        if (value < 0) {    //reject negatives
            cout << "No can do,You must enter a value greater than or equal to 0\n";
        } else {
            arr[count] = value; //store value
            count++;
        }
    }

    return count;   //update # of elements
}

int main() {
    int numbers[MAX_SIZE];
    int count = 0;
    char choice;

    displayProgramInfo();

    count = inputValues(numbers, MAX_SIZE); //initial values

    do {    //main menu loops until user enters 'Q'
        choice = displayMenu();

        switch (choice) {
            case 'L':
                if (count > 0)
                    cout << "Largest = " << getLargest(numbers, count) << endl;
                else
                    cout << "No values available.\n";
                break;

            case 'S':
                if (count > 0)
                    cout << "Smallest = " << getSmallest(numbers, count) << endl;
                else
                    cout << "No values available.\n";
                break;

            case 'A':
                if (count > 0)
                    cout << "Sum = " << getSum(numbers, count) << endl;
                else
                    cout << "No values available.\n";
                break;

            case 'M':
                if (count > 0)
                    cout << "Mean = " << fixed << setprecision(4) << getMean(numbers, count) << endl;
                else
                    cout << "No values available.\n";
                break;

            case 'V':
                viewValues(numbers, count);
                break;

            case 'I':
                count = insertValues(numbers, count, MAX_SIZE);
                break;

            case 'Q':
                cout << "Exiting program...Goodbye!\n";
                break;

            default:
                cout << "Invalid menu selection.\n";
        }

    } while (choice != 'Q');

    return 0;
}