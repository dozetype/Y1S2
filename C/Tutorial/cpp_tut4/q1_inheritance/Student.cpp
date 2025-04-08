#include "Student.h"
#include <iostream>
using namespace std;

// TODO: Implement Student class constructor and initialize studentID 
Student::Student(string n, int a, int id) : Person(n, a) {
    int studenID = id;
}

void Student::displayInfo() const {
    // TODO: Output Student Information
    cout << studentID;


}