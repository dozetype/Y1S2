class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def push(stack, data):
    newNode = Node(data)
    newNode.next = stack
    stack = newNode
    return stack

def removeUntil(stack, value):
    currNode = stack
    temp = currNode
    while(temp.data!=value):
        temp = temp.next
    currNode.data = temp.data
    currNode.next = temp.next

def walkPrint(stack):
    currNode = stack
    while(currNode):
        print(currNode.data, end=" ")
        currNode = currNode.next
    print()

#############################################################
class queue:
    def __init__(self):
        self.front = None
        self.rear = None

    def enqueue(self, data):
        newNode = Node(data)
        if(not self.front):
            self.front = newNode
        else:
            self.rear.next = newNode
        self.rear = newNode

    def dequeue(self):
        data = self.front.data
        self.front = self.front.next
        return data

def recursiveReverse(queue):
    data = queue.dequeue()
    if(queue.front):
        recursiveReverse(queue)
    queue.enqueue(data)
    

# stack = None
# q1List = [1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1]
# for i in q1List[::-1]:
#     stack = push(stack, i)
# print("Question 1:")
# walkPrint(stack)
# removeUntil(stack, 6)
# walkPrint(stack)

q = queue()
q2List = [1,2,3,4,5,6,7,8]
for i in q2List[::1]:
    q.enqueue(i)
recursiveReverse(q)
walkPrint(q.front)
