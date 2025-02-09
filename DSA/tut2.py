class Node():
    def __init__(self, data):
        self.data = data
        self.next = None

class stack():
    def __init__(self):
        self.head = None

    def push(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    def pop(self):
        if(not self.head):
            return
        currNode = self.head
        data = currNode.data
        self.head = currNode.next
        return data
    
    def peek(self):
        if(not self.head):
            return
        return self.head.data

    def printWalk(self):
        currNode = self.head
        while(currNode):
            print(currNode.data, end=" ")
            currNode = currNode.next
        print()
    
    def size(self):
        count = 0
        currNode = self.head
        while(currNode):
            currNode = currNode.next
            count+=1
        return count

class queue():
    def __init__(self):
        self.head = None
        self.tail = None

    def enQueue(self, data):
        if(not self.head):
            newNode = Node(data)
            newNode.next = self.head
            self.head = newNode
            self.tail = newNode
            return
        
        currNode = self.tail
        newNode = Node(data)
        currNode.next = newNode
        self.tail = newNode

    def deQueue(self):
        if(not self.head):
            return
        currNode = self.head
        data = currNode.data
        self.head = currNode.next
        return data

def printWalk(dataStruc):
        currNode = dataStruc.head
        while(currNode):
            print(currNode.data, end=" ")
            currNode = currNode.next
        print()

def reverseStack(st): #Qn 1 simple passing in and out
    dupQ = queue()
    while(st.head):
        dupQ.enQueue(st.pop())
    while(dupQ.head):
        st.push(dupQ.deQueue())
    return st

def reverseFirstKItems(Q, k):#Qn 2 Same thing
    dupSt = stack()
    for i in range(k): #push into stack till K
        dupSt.push(Q.deQueue())
    
    resultQ = queue()
    while(dupSt.head): #pop finish st
        resultQ.enQueue(dupSt.pop())
    while(Q.head): #pop finish Q
        resultQ.enQueue(Q.deQueue())
    return resultQ

def sortStack(St):
    loopSt = stack()
    largestSt = stack() #can't really use int
    for i in range(St.size()):
        largestSt.push(St.pop()) #get first in St for comparisons
        while(St.head): #looping till St is empty
            if(St.peek() > largestSt.peek()): #if curr is larger swap curr with Largest
                temp = St.pop()
                St.push(largestSt.pop())
                largestSt.push(temp)
            else: #if nothing just push into loopSt
                loopSt.push(St.pop())
        loopSt.push(largestSt.pop()) #adding the cherry on top
        while(loopSt.head): #push back into St
            St.push(loopSt.pop())
    return St
    
    #Could just push everything into list and sort and push into result st

######################Initialize#########################
st = stack()
for i in [1,2,3,4,100,6,7,567,9,0]:
    st.push(i)
print("Stack:", end=" ")
printWalk(st)

q = queue()
for i in range(1, 7):
    q.enQueue(i)
print("Queue:", end=" ")
printWalk(q)

################################Questions#########################
st = reverseStack(st) #Qn 1
print("Qn 1) Reversed Stack:", end=" ")
printWalk(st)

q = reverseFirstKItems(q, 3) #Qn2
print("Qn 2) Reversed K Queue:", end=" ")
printWalk(q)

st = sortStack(st) #Qn3
print("Qn 3) Sorted Stack:", end=" ")
printWalk(st)