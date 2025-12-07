/**************************************************************
* Lab 5
* Name: David Petroff
* Course: COSC 1436 Fall 2025
*
* This program manages a list of trip stops using arrays,
* pointers, functions, and full input validation.
**************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <string>

using namespace std;


/**************************************************************
* Struct: Stop
* Purpose: Represents a trip stop with X and Y coordinates.
**************************************************************/
struct Stop
{
    int x;
    int y;
};


// Display program information
void displayProgramInfo();

// Input helpers
char getCharInput(string prompt);
int getIntInRange(string prompt, int minVal, int maxVal);
bool getYesNo(string prompt);

// Menu logic
void runMenu(Stop* trip[], int tripSize, int speed);
char displayMenuAndGetSelection();

// Trip management
void menuAddStop(Stop* trip[], int tripSize);
void menuViewTrip(Stop* trip[], int tripSize, int speed);
void menuDeleteStop(Stop* trip[], int tripSize);
void menuClearTrip(Stop* trip[], int tripSize);

bool addStop(Stop* trip[], int tripSize, Stop* newStop);
Stop* getStopByNumber(Stop* trip[], int tripSize, int stopNumber);
void removeStop(Stop* trip[], int tripSize, Stop* stopToRemove);
void clearTrip(Stop* trip[], int tripSize);

// Travel math
double distanceBetween(int x1, int y1, int x2, int y2);

// Input at program start
int getSpeed();

void displayProgramInfo()
{
    cout << "===================== TRIP PLANNER =====================\n";
    cout << "Lab 5 - Trip Manager\n";
    cout << "Author: David Petroff\n";
    cout << "Course: COSC 1436 Fall 2025\n";
    cout << "=========================================================\n\n";
}

/// <summary>
/// prompts the user for input single character
/// </summary>
/// <param name="prompt"></param>
/// <returns>lowercase of user input</returns>
char getCharInput(string prompt)
{
    string input;
    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (input.length() == 1)
            return tolower(input[0]);

        cout << "ERROR: Enter a single character.\n";
    }
}

/// <summary>
/// prompts user for integer within range.
/// </summary>
/// <param name="prompt"></param>
/// <param name="minVal"></param>
/// <param name="maxVal"></param>
/// <returns>validated integer</returns>
int getIntInRange(string prompt, int minVal, int maxVal)
{
    string input;
    int value;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        try
        {
            value = stoi(input);
            if (value >= minVal && value <= maxVal)
                return value;
        } catch (...) {}

        cout << "ERROR: Value must be between "
            << minVal << " and " << maxVal << ".\n";
    }
}
/// <summary>
/// prompts user for yes/ no repsonse, accepts( case-insensitive).
/// or keeps promting
/// </summary>
/// <param name="prompt"></param>
/// <returns>true if user enters 'y', false if'n'</returns>
bool getYesNo(string prompt)
{
    while (true)
    {
        char c = getCharInput(prompt);

        if (c == 'y')
            return true;
        if (c == 'n')
            return false;

        cout << "ERROR: Enter Y or N.\n";
    }
}
/// <summary>
/// displays main menu and promts user for selection.
/// accepts single validated character.
/// </summary>
/// <returns>lowercase version of users charcter choice.</returns>
char displayMenuAndGetSelection()
{
    cout << "\n============== MAIN MENU ==============\n";
    cout << "A - Add Stop\n";
    cout << "V - View Trip\n";
    cout << "D - Delete Stop\n";
    cout << "C - Clear Trip\n";
    cout << "Q - Quit\n";
    cout << "=======================================\n";

    return getCharInput("Enter selection: ");
}
/// <summary>
/// runs main menu loop, continues running until user confirms exit.
/// </summary>
/// <param name="trip"></param>
/// <param name="tripSize"></param>
/// <param name="speed"></param>
void runMenu(Stop* trip[], int tripSize, int speed)
{
    while (true)
    {
        char selection = displayMenuAndGetSelection();

        switch (selection)
        {
            case 'a':
                menuAddStop(trip, tripSize);
                break;

            case 'v':
                menuViewTrip(trip, tripSize, speed);
                break;

            case 'd':
                menuDeleteStop(trip, tripSize);
                break;

            case 'c':
                menuClearTrip(trip, tripSize);
                break;

            case 'q':
                if (getYesNo("Are you sure you want to quit? (Y/N): "))
                    return;
                break;

            default:
                cout << "ERROR: Invalid selection.\n";
        }
    }
}

/// <summary>
/// attempts to add stop pointer to trip array.
/// adds stop to first available NULL position.
/// </summary>
/// <param name="trip"></param>
/// <param name="tripSize"></param>
/// <param name="newStop"></param>
/// <returns>true if stop was added, false if trip is full.</returns>
bool addStop(Stop* trip[], int tripSize, Stop* newStop)
{
    for (int i = 0; i < tripSize; i++)
    {
        if (trip[i] == nullptr)
        {
            trip[i] = newStop;
            return true;
        }
    }
    return false; // No room
}

/// <summary>
/// handles adding a stop through menu interaction.
/// promts user for X and Y coordinates, creates stop,
/// attempts to add to trip.
/// </summary>
/// <param name="trip"></param>
/// <param name="tripSize"></param>
void menuAddStop(Stop* trip[], int tripSize)
{
    cout << "\n=== ADD STOP ===\n";

    int x = getIntInRange("Enter X (-100 to 100): ", -100, 100);
    int y = getIntInRange("Enter Y (-100 to 100): ", -100, 100);

    Stop* newStop = new Stop {x, y};

    if (!addStop(trip, tripSize, newStop))
    {
        cout << "ERROR: Trip is full. Stop not added.\n";
        delete newStop;
    } else
    {
        cout << "Stop added successfully.\n";
    }
}

/// <summary>
/// retreives stop pointer from the trip based on a 1-based stop number.
/// </summary>
/// <param name="trip"></param>
/// <param name="tripSize"></param>
/// <param name="stopNumber"></param>
/// <returns>pointer to the requested stop, or null if not found.</returns>
Stop* getStopByNumber(Stop* trip[], int tripSize, int stopNumber)
{
    int index = stopNumber - 1;

    if (index < 0 || index >= tripSize)
        return nullptr;

    return trip[index];
}

/// <summary>
/// removes stop from the trip array by: locating pointer,
/// deleting stop object, shifting remaining stops forward to fill.
/// </summary>
/// <param name="trip"></param>
/// <param name="tripSize"></param>
/// <param name="stopToRemove"></param>
void removeStop(Stop* trip[], int tripSize, Stop* stopToRemove)
{
    if (stopToRemove == nullptr)
        return;

    int index = -1;

    for (int i = 0; i < tripSize; i++)
    {
        if (trip[i] == stopToRemove)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return;

    delete trip[index];
    trip[index] = nullptr;

    // Compact the array
    int newIndex = index;

    for (int i = index + 1; i < tripSize; i++)
    {
        if (trip[i] == nullptr)
            break;

        trip[newIndex] = trip[i];
        newIndex++;
    }

    trip[newIndex] = nullptr;
}

/// <summary>
/// handles deleting a stop via the menu system.
/// promts for the stop number, validates, and removes the stop.
/// displays error if stop does not exist.
/// </summary>
/// <param name="trip"></param>
/// <param name="tripSize"></param>
void menuDeleteStop(Stop* trip[], int tripSize)
{
    cout << "\n=== DELETE STOP ===\n";

    int stopNum = getIntInRange("Enter stop number: ", 1, tripSize);

    Stop* s = getStopByNumber(trip, tripSize, stopNum);

    if (s == nullptr)
    {
        cout << "ERROR: Stop does not exist.\n";
        return;
    }
    1
        removeStop(trip, tripSize, s);

    cout << "Stop removed.\n";
}

/// <summary>
/// removes all stops from the trip by deleting all stop objects,
/// then setting each array element back to null.
/// </summary>
/// <param name="trip"></param>
/// <param name="tripSize"></param>
void clearTrip(Stop* trip[], int tripSize)
{
    for (int i = 0; i < tripSize; i++)
    {
        if (trip[i] != nullptr)
        {
            delete trip[i];
            trip[i] = nullptr;
        }
    }
}
/// <summary>
/// handles clearing the entire trip via menu selection.
/// asks user for confirmation.
/// </summary>
/// <param name="trip"></param>
/// <param name="tripSize"></param>
void menuClearTrip(Stop* trip[], int tripSize)
{
    cout << "\n=== CLEAR TRIP ===\n";

    if (getYesNo("Are you sure? (Y/N): "))
    {
        clearTrip(trip, tripSize);
        cout << "Trip cleared.\n";
    } else
    {
        cout << "Clear cancelled.\n";
    }
}
/// <summary>
/// computes the straight-line distance between two coordinates.
/// </summary>
/// <param name="x1"></param>
/// <param name="y1"></param>
/// <param name="x2"></param>
/// <param name="y2"></param>
/// <returns>distance between the points as a double.</returns>
double distanceBetween(int x1, int y1, int x2, int y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

/// <summary>
/// displays formatted table containing: stop number, coordinates, distance from
/// previous stop, travel time in min.
/// </summary>
/// <param name="trip"></param>
/// <param name="tripSize"></param>
/// <param name="speed"></param>
void menuViewTrip(Stop* trip[], int tripSize, int speed)
{
    cout << "\n=== VIEW TRIP ===\n";

    cout << "Stop        Location        Distance (miles)     Time (minutes)\n";
    cout << "--------------------------------------------------------------------------\n";

    int totalStops = 0;
    double totalDistance = 0;
    double totalMinutes = 0;

    int prevX = 0, prevY = 0; // Start at origin

    for (int i = 0; i < tripSize; i++)
    {
        if (trip[i] == nullptr)
            break;

        totalStops++;

        int x = trip[i]->x;
        int y = trip[i]->y;

        double d = distanceBetween(prevX, prevY, x, y);
        double hours = d / speed;
        double minutes = ceil(hours * 60);

        totalDistance += d;
        totalMinutes += minutes;

        cout << setw(4) << (i + 1)
            << setw(15) << "(" + to_string(x) + ", " + to_string(y) + ")"
            << setw(15) << fixed << setprecision(2) << d
            << setw(20) << minutes << "\n";

        prevX = x;
        prevY = y;
    }

    cout << "---------------------------------------------------------------------------\n";
    cout << setw(4) << totalStops
        << setw(27) << fixed << setprecision(2) << totalDistance
        << setw(20) << totalMinutes << "\n";
}
/// <summary>
/// promts user for their travel speed in mph.
/// </summary>
/// <returns>validated speed as integer.</returns>
int getSpeed()
{
    return getIntInRange("Enter your speed (1 - 60mph): ", 1, 60);
}

/// <summary>
/// program entry point.
/// initializes trip array, gets users sppeed, runs main menu loop,
/// clears all allocated memory, ends program cleanly 
/// </summary>
/// <returns>0 upon seccessful completion </returns>
int main()
{
    displayProgramInfo();

    const int TRIP_SIZE = 100;
    Stop* trip[TRIP_SIZE] = {nullptr};

    int speed = getSpeed();

    runMenu(trip, TRIP_SIZE, speed);

    clearTrip(trip, TRIP_SIZE);

    cout << "Goodbye!\n";
    return 0;
}