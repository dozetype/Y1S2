///////// Student Info/////////
//
//           Your Name:Chen Xing Wei
//      Your NTU Email:C240155@e.ntu.edu.sg
//
//
//
#include <iostream>
#include <string>
using namespace std;

// Base class: Sports
class Sports {
protected:
    string sport; // sport name
public:
    // TO-DO 1: Implement the constructor and descructor
    Sports(string sport){
        this->sport = sport;
        cout << "Sports constructor!" << endl;
    }

    ~Sports(){
        cout << "Sports destructor!" << endl;
    }

    // Display sports information
    void displaySports() const {
        cout << "Sport: " << sport << endl;
    }
};

// Base class: Academics
class Academics {
protected:
    float gpa; // GPA
public:
    // TO-DO 2: Implement the constructor and destructor
    Academics();
    Academics(float gpa){
        this->gpa = gpa;
        cout << "Academics constructor!" << endl;
    }

    ~Academics(){
        cout << "Academics destructor!" << endl;
    }


    // Display academic information
    void displayAcademics() const {
        cout << "GPA: " << gpa << endl;
    }
};

// TO-DO 3: Implement the Derived class: StudentAthlete, which inherits from both Academics and Sports
class StudentAthlete : public Sports, public Academics{
    private:
        string name;
        int age;
        int studentID;
    
    public:
        StudentAthlete(string s, float g, string n, int a, int id) : Sports(s), Academics(g){
            this->name = n;
            this->age = a;
            this->studentID = id;
            cout << "StudentAthlete constructor!" << endl;
        }

        ~StudentAthlete(){
            cout << "StudentAthlete destructor!" << endl;
        }
        
        void displayInfo() const{
            cout << "Name: " << name << ", Age: " << age << ", Student ID: " << studentID << endl;
            cout << "Sport: " << sport << endl;
            cout << "GPA: " << gpa << endl;
        }

};

int main() {
    //Create a StudentAthlete instance
    StudentAthlete stu("Basketball", 3.8, "Bob", 21, 1001);

    // Display all the information
    cout<<endl;
    stu.displayInfo();
    cout<<endl;
    
    // Test code to demonstrate multiple inheritances
    stu.displaySports();
    stu.displayAcademics();
    cout<<endl;
    
    return 0;
}
