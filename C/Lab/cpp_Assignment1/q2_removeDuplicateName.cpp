#include <iostream>
#include <string>

struct StringNode {
    std::string name;
    StringNode* next;
};


void printList(const StringNode* head) {
    const StringNode* temp = head;
    while (temp) {
        std::cout << temp->name << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

void append(StringNode*& head, const std::string& name) {
    StringNode* newNode = new StringNode;
    newNode->name = name;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    StringNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void freeList(StringNode*& head) {
    while (head) {
        StringNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Remove duplicate names from the linked list
void removeDuplicatedNames(StringNode*& head) {
    // TO-DO: Write Your Code Here
    if(!head) return;
    
    StringNode* curr = head;
    int size = 0;
    for(; curr; curr=curr->next) //getting size
        size++;
    
    std::string* store = new std::string[size];
    int index = 0;
    curr = head;
    StringNode* prev = nullptr;
    while(curr){
        bool isInside = false;
        for(int i=0; i<size; i++){
            if(store[i] == curr->name){ //if name already seen
                isInside = true;
                break;
            }
        }
        
        if(isInside){ //if seen
            if(curr->next) //if next is not nullptr
                prev->next = curr->next;
            else
                prev->next = nullptr;
        }
        else{ //not seen. store the name, move prev ptr
            store[index] = curr->name;
            index++;
            prev = curr;
        }
        curr = curr->next;//traverse
    }
    delete[] store;
}

int main() {
    StringNode* head = nullptr;
    append(head, "Alice");
    append(head, "Alice");
    append(head, "Bob");
    append(head, "Charlie");
    append(head, "David");
    printList(head);
    removeDuplicatedNames(head);
    printList(head);
    freeList(head);

    return 0;
}
