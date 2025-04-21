///////// Student Info/////////
//
//           Your Name:Chen Xing Wei
//      Your NTU Email:C240155@e.ntu.edu.sg
//
//
//
#include <iostream>
#include <map>
#include <string>

using namespace std;

class PhoneBook {
private:
    map<string, string> contacts; // Maps names to phone numbers

public:
    // TO-DO: Implement the constructor
    PhoneBook(){
        map<string, string> contacts;
    }

    // TO-DO: Implement addContact(const string &name, const string &number) 
    void addContact(const string &name, const string &number){
        contacts[name] = number;
    }

    // TO-DO: Implement removeContact(const string &name) 
    void removeContact(const string &name){
        contacts.erase(name);
    }


    // TO-DO: Implement findContact(const string &name) 
    string findContact(const string &name){
        auto search = contacts.find(name);
        if(search != contacts.end()){ //student exist
            return search->second;
        }
        else{ //student dont exist
            return "Not Found!";
        }
    }


    // TO-DO: Implement displayAllContacts()
    void displayAllContacts(){
        for(auto i : contacts) {
            cout << i.first << " -> " << i.second << endl;
        }
    }

};

int main() {
    PhoneBook pb;
    pb.addContact("Alice", "12345678");
    pb.addContact("Bob", "23456789");
    pb.addContact("Charlie", "34567890");

    // Display contacts
    cout << "All Contacts:" << endl;
    pb.displayAllContacts();
    cout<<endl;

    // Find a contact
    string searchName = "Charlie";
    cout << "The contact number of " << searchName << ": " 
         << pb.findContact(searchName) << endl <<endl;

    searchName = "David";
    cout << "The contact number of " << searchName << ": " 
            << pb.findContact(searchName) << endl <<endl;

    // Remove a contact
    pb.removeContact("Bob");
    cout << "After removing Bob, contacts are:" << endl;
    pb.displayAllContacts();

    return 0;
}
