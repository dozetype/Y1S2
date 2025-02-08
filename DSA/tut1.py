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
            return
        
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
    
    def moveEvenItemsToBack(self): #qn 1
        index = 0
        size = self.size()
        currNode = self.head
        for i in range(size):
            if(currNode.data%2==0):
                self.insertEnd(currNode.data)
                self.removeIndex(index)
            else:
                index+=1 #only index++ if currNode is odd
            currNode = currNode.next
    
    def moveMaxToFront(self): #qn 2
        index = 0
        currNode = self.head
        maxData = 0
        for i in range(self.size()):
            if(currNode.data > maxData):
                index = i
                maxData = currNode.data
            currNode = currNode.next
        self.removeIndex(index)
        self.insertFront(maxData)

    def removeDuplicatesSorted(self): #qn 3
        index = 1
        currNode = self.head
        currData = currNode.data
        while(currNode.next):
            if(currNode.next.data == currData):
                # self.removeIndex(index)
                currNode.next = currNode.next.next
            else:
                index+=1
                currNode = currNode.next
                currData = currNode.data

    def circular(self):
        currNode = self.head
        while(currNode.next):
            currNode = currNode.next
        currNode.next = self.head


LList = LinkedList()
input = [2, 7, 18, 3, 4, 15]
# input = list(input.strip().split(','))
for i in range(len(input)):
    LList.insertEnd(input[i])
# LList.insertIndex(, 3)
print("Question 1")
LList.moveEvenItemsToBack()
LList.walkPrint()

print("Question 2")
LList.moveMaxToFront()
LList.walkPrint()

print("Question 3")
LList = LinkedList()
input = [1,1,1,2,4,4,5,5,6,6,6]
for i in range(len(input)):
    LList.insertEnd(input[i])
LList.removeDuplicatesSorted()
LList.walkPrint()

print("Question 4, will create 2 small circular linked list")
# LList.circular()
# LList.walkPrint()