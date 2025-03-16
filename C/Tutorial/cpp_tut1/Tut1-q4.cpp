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
            if(toupper(res.grade)=='A') finalMark = 90;
            else if(toupper(res.grade)=='B') finalMark = 80;
            else if(toupper(res.grade)=='C') finalMark = 60;
        }
        else{
            finalMark = res.mark;
        }
        
    }
};

void displayStudentInfo(Student *students, int count) {
    // TO-DO: Write your functions here
    double total = 0;
    cout << "Student Results:" << endl;
    for(int i=0; i<count; i++){
        cout << students[i].studentName << ", Final Mark: " << students[i].finalMark << endl;
        total += students[i].finalMark;
    }
    cout << "Average Final Mark: " << total/count << endl;
}



int main() {
    // TO-DO: Write your functions here
    int num = 0; //size of student
    char gm;
    char dummy[50];

    cout << "How many students do you want to input?" << endl;
    cout << "Enter student size: ";
    cin >> num;
    Student students[num];
    
    for(int i=0; i<num; i++){
        cin.getline(dummy, 50); //for removing '\n' from getting num
        cout << "Enter student name: ";
        cin.getline(students[i].studentName, 50);
        cout << "Enter 'G' if result is grade or 'M' if result is mark: ";
        cin >> gm;
        if(toupper(gm)=='G'){
            students[i].isGrade=true;
            cout << "Enter grade (A,B,C): ";
            cin >> students[i].res.grade;
        }
        else{
            cout << "Enter mark (0-100): ";
            cin >> students[i].res.mark;
        }
        students[i].convertGrade();
    }

    displayStudentInfo(students, num);
    return 0;
}

