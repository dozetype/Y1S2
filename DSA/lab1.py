class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None #pointer to next Node

    def insertFront(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    def insertEnd(self, data):
        newNode = Node(data)
        if(self.head is None): #if theres nothing in LL
            newNode.next = None
            self.head = newNode
            return

        currNode = self.head
        while(currNode.next): #walk to last node
            currNode = currNode.next
        currNode.next = newNode

    def insertIndex(self, data, index):
        if(index==0):
            self.insertFront(data)
        
        pos = 0
        currNode = self.head
        while(currNode and pos<index-1): #walk to index-1
            currNode = currNode.next
            pos+=1

        if(currNode):
            newNode = Node(data)
            newNode.next = currNode.next
            currNode.next = newNode
        else:
            print("Didn't Insert")

    def removeBegin(self):
        if(not self.head):
            return
        self.head = self.head.next

    def removeEnd(self):
        if(not self.head):
            return
        currNode = self.head
        while(currNode.next and currNode.next.next):
            currNode = currNode.next
        currNode.next = None #dk why cannot just currNode = None

    def removeIndex(self, index):
        if(index==0): 
            self.removeBegin()
            return

        curr = 0
        currNode = self.head
        while(currNode.next and curr<index-1):
            curr += 1
            currNode = currNode.next
        if(currNode.next):
            currNode.next = currNode.next.next
        else:
            print("Didn't remove")

    def walkPrint(self):
        currNode = self.head
        while(currNode):
            print(currNode.data, end=" ")
            currNode = currNode.next
        print("\n")

    def size(self):
        count = 0
        currNode = self.head
        while(currNode):
            count+=1
            currNode = currNode.next
        return count