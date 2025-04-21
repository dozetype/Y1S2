class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.pre = None

class DoublyLL:
    def __init__(self):
        self.head = None
    
    def insertFront(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
        if(newNode.next): #if LL is not empty
            newNode.next.pre = newNode

    def insertEnd(self, data):
        newNode = Node(data)
        if(not self.head): #if nothing in LL
            self.head = newNode
            return

        currNode = self.head
        while(currNode.next): #walk to last Node
            currNode = currNode.next
        newNode.pre = currNode
        currNode.next = newNode

    def insertIndex(self, data, index):
        if(index == 0):
            self.insertFront(data)
            return

        pos = 0
        currNode = self.head
        while(currNode and pos<index-1): #try walk to desired index -1
            currNode = currNode.next
            pos+=1
        if(currNode): #if index-1 exists
            newNode = Node(data)
            newNode.pre = currNode
            newNode.next = currNode.next
            currNode.next = newNode
            if(newNode.next): #if not inserting at last index
                newNode.next.pre = newNode
        else:
            print("Didn't Insert")

    def removeFirst(self):
        if(not self.head):
            return
        self.head.next.pre = None
        self.head = self.head.next
    
    def removeIndex(self, index):
        if(not self.head):
            print("already empty")
            return
        if(index==0):
            self.removeFirst()
        
        curr = 0
        currNode = self.head
        while(currNode.next and curr<index-1):
            currNode = currNode.next
            curr += 1
        if(currNode.next):
            currNode.next = currNode.next.next
            if(currNode.next): #if not last node
                currNode.next.pre = currNode
        else:
            print("Didn't remove")


    def walkPrint(self):
        print("Walking Doubly")
        current = self.head
        while(current.next): #walk forward
            print(current.data, end=" -> ")
            current = current.next
        print(current.data)

        while(current.pre): #walk Backwards
            print(current.data, end=" -> ")
            current = current.pre
        print(current.data)

doubly = DoublyLL()
for i in range(5):
    doubly.insertEnd(i)

doubly.insertIndex(10,4)
doubly.walkPrint()
# doubly.removeIndex(4)
# doubly.walkPrint()
