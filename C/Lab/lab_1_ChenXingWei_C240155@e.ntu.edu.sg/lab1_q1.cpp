///////// Student Info/////////
//
//           Your Name:Chen Xing Wei
//      Your NTU Email:C240155@e.ntu.edu.sg
//
//
//

#include <iostream>
#include <cstring> //need to include this for strcmp()
using namespace std;

// Function to get a valid integer input
int getValidInt() {
    char dummy[50];
    int input = 0;
    bool valid = false;
    cin >> input;
    while(cin.fail()) { // Check if input failed
        cin.clear(); // Clear error state
        cin.ignore(1000,'\n');//Discard invalid input
        cout << "Invalid input! Please enter an integer: ";
        cin >> input;
    }
    cin.getline(dummy, 50);
    return input;
}

// Function to get a valid float input
float getValidFloat() {
    char dummy[50];
    float input = 0;
    bool valid = false;
    cin >> input;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid input! Please enter a valid float number: ";
        cin >> input;
    }
    cin.getline(dummy, 50);
    return input;
}

int main() {
    char name[50];  // Student name
    int studentID;  // Student ID
    float mathMark; // Math mark

    while (true) {
        // Get student name
        cout << "Enter student name (or enter '#' to exit): ";
        cin.getline(name, 50);

        // Check if user wants to exit
        if (strcmp(name, "#") == 0) {
            break;
        }

        // Get student ID
        cout << "Enter student ID (integer): ";
        studentID = getValidInt();

        // Get math mark
        cout << "Enter math mark (float): ";
        mathMark = getValidFloat();

        // Display student information
        cout << "\nStudent Information:\n";
        cout << "Name: " << name << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Math Mark: " << mathMark << endl;
        cout << "-------------------------\n";
    }

    cout << "Program exited successfully." << endl;
    return 0;
}
