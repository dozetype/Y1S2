#include <iostream>
#include <string>
using namespace std;


// TODO: Update your implementation for Student Class and Person Class in Question 1 
//       Declare displayInfo() as virtual 
class Person{
    protected:
    string name;
    int age;

    public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
}




// Derived class: GraduateStudent (inherits from Student)
class GraduateStudent : public Student {
private:
    // TODO: Define the additional attribute (researchTopic)
    string reaseachTopic;
    
public:
    // TODO: Implement the Constructor
    GraduateStudent(string n, int a, int id, string topic)Student(n, a, id), researchTopic(topic){}


    // TODO: Implement displayInfo() (Note: it is virtual function in Student)


    virtual void displayInfo() const override{
        Student::displayInfo();
        cout << researchTopic;
    }
};


int main() {
    GraduateStudent gs1("Alice", 25, 56789, "Machine Learning");
    gs1.displayInfo();
    cout<<endl;

    Student* stu = &gs1;
    stu->displayInfo(); //overidden by gs
    cout<<endl;

    Person* per = &gs1;
    per->displayInfo(); //overidden by gs

    return 0;
}
