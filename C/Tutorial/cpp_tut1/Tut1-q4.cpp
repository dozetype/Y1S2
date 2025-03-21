#include <iostream>
using namespace std;

union Result {
    int mark;
    char grade; // Can be only 'A', 'B' or 'C'
};

struct Student {
    char studentName[50];
    bool isGrade;
    int finalMark; // Used to store the final mark
    Result res;

    void convertGrade() { // A=90 , B=80, C=60
        // TO-DO: Write your functions here
        if(isGrade){
            switch(res.grade){
                case 'A':
                    finalMark = 90;
                    break;
                case 'B':
                    finalMark = 80;
                    break;
                case 'C':
                    finalMark = 60;
                    break;
                default:
                    break;
            }
        }
        else{
            finalMark = res.mark;
        }
    }
};

void displayStudentInfo(Student *students, int count) {
    // TO-DO: Write your functions here
    double total = 0;
    cout << "\nStudent Results:" << endl;;
    for(int i=0; i<count; i++){
        cout << "Name: " << students[i].studentName << ", Final Mark: " << students[i].finalMark << endl;
        total += students[i].finalMark;
    }
    cout << "\nAverage Final Mark: " << total/count << endl;


}

int main() {
    // TO-DO: Write your functions here
    int studentSize;
    char gOrM;
    cout << "How many students do you want to input?" << endl << "Enter student size: ";
    cin >> studentSize;
    cin.get(); //Remove '\n'
    Student *studentArr = new Student[studentSize];
    for(int i=0; i<studentSize; i++){
        cout << "Enter student name: ";
        cin.getline(studentArr[i].studentName, 50);
        cout << "Enter 'G' if result is grade or 'M' if result is mark: ";
        cin >> gOrM;
        if(gOrM=='G' || gOrM=='g'){
            studentArr[i].isGrade = true;
            cout << "Enter grade (A,B,C): ";
            cin >> studentArr[i].res.grade;
        }
        else{
            cout << "Enter mark (0-100): ";
            cin >> studentArr[i].res.mark;
        }
        studentArr[i].convertGrade();
        cin.get();
    }
    displayStudentInfo(studentArr, studentSize);

    //delete afterwards;
    delete[] studentArr;
    studentArr = nullptr;
    return 0;
}