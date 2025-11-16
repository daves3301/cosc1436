/*
Lab 4 - Number Analysis Program
David Petroff
COSC 1436
Fall 2025

This Program allows users tp enter up to 100
integers then provides menu options to calculate
the largest, smallest, sum, mean, or view values,
as well as insert new values.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 100;   //Max number of values user can enter

/*FUNCTON PROTOTYPES*/

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

/// <summary>
/// Displays program title, author name,
/// course, and semester.
/// </summary>
void displayProgramInfo() {
    cout << "========================================\n";
    cout << "       Lab 4 - Number Analyzer\n";
    cout << "       David Petroff\n";
    cout << "       COSC 1436 Fall 2025\n";
    cout << "========================================\n";
}

/// <summary>
/// prompts user to enter up to 100 integers.
/// stops when user enters 0.
/// no negative integers.
/// </summary>
/// <param name="array"></param>
/// <param name="maxSize"></param>
/// <returns>number of valid integers stored in array</returns>
int inputValues(int arr[], int maxSize) {
    int value;
    int count = 0;

    while (count < maxSize) {   //Validate input
        cout << "Enter a value: ";
        cin >> value;

        while (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter an intiger: ";
            cin >> value;
        }

        if (value == 0) {   //stop when user enters 0
            break;
        } else if (value < 0) { //Reject negatives
            cout << "You must enter a value greater than or equal to 0\n";
        } else {            //valid? store in array
            arr[count] = value;
            count++;
        }
    }
    return count;   //Total values stored
}

/// <summary>
/// Shows main menu and retreives user choice.
/// converts input to uppercase.
/// </summary>
/// <returns>char representing selected menu option.</returns>
char displayMenu() {
    char choice;
    cout << "\nMain Menu\n";
    cout << "-----------------\n";
    cout << "L) Largest\n";
    cout << "S) Smallest\n";
    cout << "A) Add (Sum)\n";
    cout << "M) Mean\n";
    cout << "V) View Values\n";
    cout << "I) Insert New Value\n";
    cout << "Q) Quit\n";
    cout << "Entert choice: ";
    cin >> choice;

    return toupper(choice); //convert to upper-case
}

/// <summary>
/// finds & returns largest integer in array.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
/// <returns>largest integer in array.</returns>
int getLargest(const int arr[], int count) {
    int largest = arr[0];   //start with first element

    for (int i = 1; i < count; i++) {   //loop through array to find max
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}

/// <summary>
/// Finds & returns smallest integer in array.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
/// <returns>Smallest integer in array.</returns>
int getSmallest(const int arr[], int count) {
    int smallest = arr[0];

    for (int i = 1; i < count; i++) {   //loop through array to find min
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    return smallest;
}

/// <summary>
/// Computes & returns sum of all values in array.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
/// <returns>Sum of integers.</returns>
int getSum(const int arr[], int count) {
    int sum = 0;

    for (int i = 0; i < count; i++) //add all numbers into sum
        sum += arr[i];
    return sum;
}

/// <summary>
/// Caluculates & returns the avg of all values stored in array.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
/// <returns> A double representing avg of the numbers.</returns>
double getMean(const int arr[], int count) {
    
    int sum = getSum(arr, count);   //reuse getSum
    return static_cast<double>(sum) / count;    //convert to double
}

/// <summary>
/// Displays all values stored in array,
/// printing 10 values per line for readablility.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
void viewValues(const int arr[], int count) {
    
    if (count == 0) {       //if display is empty, nothing to display
        cout << "No values to display.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << setw(5) << arr[i];
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}

/// <summary>
/// Allows user to add additional integers to existing array
/// without overwriting old values.
/// stop on 0, reject negatives.
/// </summary>
/// <param name="arr"></param>
/// <param name="count"></param>
/// <param name="maxSize"></param>
/// <returns>The new total number of values in the array.</returns>
int insertValues(int arr[], int count, int maxSize) {
    
    if (count >= maxSize) {     //No space left
        cout << " Dang! Array is already full, cannot insert more values.\n";
        return count;
    }
    
    int value;

    while (count < maxSize) {   //Continue adding while theres space
        cout << "Enter a value: ";
        cin >> value;

        while (!cin) {  //Validate input 
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Oops! Invalid input. Enter an integer: ";
            cin >> value;
        }
        if (value == 0) //Stop at 0
            break;

        if (value < 0) {    //Reject negatives
            cout << "Oops! You must enter a value greater than or equal to 0\n";
        } else {
            arr[count] = value; //Store value
            count++;
        }
    }

    return count;   //Update number of elements
}

int main() {
    int numbers[MAX_SIZE];
    int count = 0;
    char choice;

    displayProgramInfo();

    count = inputValues(numbers, MAX_SIZE); //first batch of values

    do {                                    //Masin menu loop runs until user chooses 'Q'
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
                cout << "Exiting program... Goodbye!\n";
                break;

            default:
                cout << "Invalid menu election.\n";
        }
    } while (choice != 'Q');
    
    return 0;
}
