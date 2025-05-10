#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <limits>
#include "colors.h"

using namespace std;

// Function prototypes
void displayHeader();
void displayMenu();
void calculateTravelTime();
void calculateMinSpeed();
void calculateRoadLength();
void logError(const string& error);
void waitForKeyPress();
void drawLine();

int main() {
    system("cls");
    int wybor = 0;

    while (wybor != 4) {
        displayHeader();
        displayMenu();
        
        if (!(cin >> wybor)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            logError("Invalid input");
            cout << RED << "Invalid input! Please enter a number." << RESET << endl;
            waitForKeyPress();
            continue;
        }

        system("cls");

        switch (wybor) {
            case 1: calculateTravelTime(); break;
            case 2: calculateMinSpeed(); break;
            case 3: calculateRoadLength(); break;
            case 4: 
                cout << CYAN << "\n*******************************************" << endl;
                cout << "*          Thank you for using           *" << endl;
                cout << "*         Road Calculations App          *" << endl;
                cout << "*******************************************" << RESET << endl;
                break;
            default:
                cout << YELLOW << "Invalid option!" << RESET << endl;
                logError("Invalid menu option");
        }
        
        if (wybor != 4) waitForKeyPress();
    }
    return 0;
}

void displayHeader() {
    cout << MAGENTA;
    cout << "************************************************" << endl;
    cout << "*           ROAD CALCULATIONS v1.0              *" << endl;
    cout << "*          Created by Adrian Lesniak           *" << endl;
    cout << "************************************************" << endl;
    cout << CYAN;
    cout << "\nProgram Description:" << endl;
    cout << "This application helps calculate various road travel" << endl;
    cout << "parameters including travel time, minimum speed," << endl;
    cout << "and road length based on given inputs." << endl;
    cout << RESET << endl;
}

void displayMenu() {
    drawLine();
    cout << GREEN;
    cout << "1. Calculate travel time (using speed and distance)" << endl;
    cout << "2. Calculate minimum speed (using time and distance)" << endl;
    cout << "3. Calculate road length (using speed and time)" << endl;
    cout << "4. Exit program" << endl;
    drawLine();
    cout << RESET;
    cout << "\nEnter your choice: ";
}

void drawLine() {
    cout << YELLOW << "----------------------------------------" << RESET << endl;
}

void waitForKeyPress() {
    cout << "\nPress any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("cls");
}

void logError(const string& error) {
    ofstream logFile("error_log.txt", ios::app);
    time_t now = time(0);
    string timestamp = ctime(&now);
    logFile << timestamp.substr(0, timestamp.length()-1) << ": " << error << endl;
    logFile.close();
}

void calculateTravelTime() {
    double v, d;
    cout << CYAN << "\nCALCULATE TRAVEL TIME" << endl;
    drawLine();
    cout << RESET;
    
    cout << "Enter the speed (km/h): ";
    while (!(cin >> v) || v <= 0) {
        cout << RED << "Invalid input! Please enter a positive number." << RESET << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the speed (km/h): ";
    }
    
    cout << "Enter the length of the road (km): ";
    while (!(cin >> d) || d <= 0) {
        cout << RED << "Invalid input! Please enter a positive number." << RESET << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the length of the road (km): ";
    }
    
    cout << GREEN << "\nTravel time: " << fixed << setprecision(2) << d / v << "h" << RESET << endl;
}

void calculateMinSpeed() {
    double t, d;
    cout << CYAN << "\nCALCULATE MINIMUM SPEED" << endl;
    drawLine();
    cout << RESET;
    
    cout << "Enter your travel time (h): ";
    while (!(cin >> t) || t <= 0) {
        cout << RED << "Invalid input! Please enter a positive number." << RESET << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter your travel time (h): ";
    }
    
    cout << "Enter the length of the road (km): ";
    while (!(cin >> d) || d <= 0) {
        cout << RED << "Invalid input! Please enter a positive number." << RESET << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the length of the road (km): ";
    }
    
    cout << GREEN << "\nMinimum speed: " << fixed << setprecision(2) << d / t << "km/h" << RESET << endl;
}

void calculateRoadLength() {
    double v, t;
    cout << CYAN << "\nCALCULATE ROAD LENGTH" << endl;
    drawLine();
    cout << RESET;
    
    cout << "Enter the speed (km/h): ";
    while (!(cin >> v) || v <= 0) {
        cout << RED << "Invalid input! Please enter a positive number." << RESET << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the speed (km/h): ";
    }
    
    cout << "Enter your travel time (h): ";
    while (!(cin >> t) || t <= 0) {
        cout << RED << "Invalid input! Please enter a positive number." << RESET << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter your travel time (h): ";
    }
    
    cout << GREEN << "\nRoad length: " << fixed << setprecision(2) << v * t << "km" << RESET << endl;
}
