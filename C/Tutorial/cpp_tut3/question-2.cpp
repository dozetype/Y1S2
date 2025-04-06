#include <iostream>
using namespace std;

class VisitorCounter {
private:
    int* count;  // Pointer to dynamically allocated memory for visit count

public:
    VisitorCounter(int initialCount) {
        count = new int(initialCount); //give count a good address
        cout << "Constructor called with the count as " << *count << endl;
    }

    //User defined copy constructor ADDED
    VisitorCounter(const VisitorCounter& other){
        count = new int(*other.count);
        cout << "Deep Copy Constructor Called" << endl;
    }

    ~VisitorCounter() {
        cout << "Destructor called with the count being " << *count << endl;
        delete count; //return integer location pointed by new
    }

    void increment() {
        (*count)++;
    }

    void display() const {
        cout << "Visitor Count: " << *count << endl;
    }
};

int main() {
    VisitorCounter counter(10);
    cout << "\nOriginal Counter:\n";
    counter.display();

    // Copy the counter
    VisitorCounter counterCopy = counter; //using default shallow copy
    cout << "counterCopy:\n";
    counterCopy.display();

    // Increase copied object's count
    counterCopy.increment();
    counterCopy.increment();
    cout << "\nAfter modifying copied counter...\n";
    cout << "Original Counter: "<<endl;
    counter.display();
    cout << "counterCopy: "<<endl;
    counterCopy.display(); 
    cout <<endl <<endl;
    //repeated deletion of dynamically allocated memory
    return 0;
}