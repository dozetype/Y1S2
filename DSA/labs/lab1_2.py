class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insertNode(head, data):
    newNode = Node(data)
    newNode.next = head
    head = newNode
    return head

def walkPrint(head):
    currNode = head
    while(currNode):
        print(currNode.data, end=" ")
        currNode = currNode.next
    print()

def findNode(ptrHead, index):
    currNode = ptrHead
    pos = 0
    while(currNode and pos<index):
        pos+=1
        currNode = currNode.next
    return currNode


def removeNode(ptrHead, index):
    if(index == 0):
        if(ptrHead.next):
            curr = ptrHead.next
            ptrHead.data = curr.data
            ptrHead.next = curr.next
            return 1
        
    currNode = findNode(ptrHead, index-1)

    if(currNode and currNode.next):
        temp = currNode.next
        currNode.next = temp.next
        return 1

def split(head, ptrEvenList, ptrOddList):
    evenHead = oddHead = None
    evenTail = oddTail = None
    currNode = head
    index = 0
    while(currNode):
        if(index%2==0):
            if(evenHead is None):
                evenHead = Node(currNode.data)
                evenTail = evenHead
            else:
                evenTail.next = Node(currNode.data)
                evenTail = evenTail.next
        else:
            if(oddHead is None):
                oddHead = Node(currNode.data)
                oddTail = oddHead
            else:
                oddTail.next = Node(currNode.data)
                oddTail = oddTail.next
        index+=1
        currNode = currNode.next
    ptrEvenList.append(evenHead)
    ptrOddList.append(oddHead)



def duplicateReverse(head, ptrNewHead):
    currNode = head
    dup = Node(currNode.data)
    while(currNode):
        newNode = Node(currNode.data)
        dup = newNode
        dup.next = ptrNewHead
        ptrNewHead = dup
        currNode = currNode.next
    return dup


head = None
oddHead = []
evenHead = []
dup = None
head = insertNode(head, 1)
head = insertNode(head, 2)
head = insertNode(head, 3)
head = insertNode(head, 4)
head = insertNode(head, 5)
head = insertNode(head, 6)
head = insertNode(head, 7)
# removeNode(head, 2)
split(head, evenHead, oddHead)
# walkPrint(oddHead[0])
# walkPrint(evenHead[0])
dup = duplicateReverse(head, dup)
walkPrint(dup)
walkPrint(head)
