class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insert(head, data, index): #dk why need return head
    if(index==0):
        newNode = Node(data)
        newNode.next = head
        head = newNode
        return head
    currNode = head
    curr = 0
    while(currNode and curr<index-1):
        currNode = currNode.next
        curr+=1
    if(currNode):
        newNode = Node(data)
        newNode.next = currNode.next
        currNode.next = newNode
    else:
        print("Not inserted")
    return head

def remove(head, index):
    if(index==0):
        target = head.next
        head.data = target.data
        head.next = target.next
        return
    
    currNode = head
    curr = 0
    while(currNode and curr<index-1):
        currNode = currNode.next
        curr+=1
    if(currNode):
        currNode.next = currNode.next.next
    else:
        print("Not Removed")
    
def walkPrint(head):
    while(head):
        print(head.data, end=" ")
        head = head.next
    print()

def revdup(head, duplicate):
    currNode = head
    while(currNode):
        newNode = Node(currNode.data)
        newNode.next = duplicate
        duplicate = newNode
        currNode = currNode.next
    return duplicate

def copyll(head, copy):
    currNode = head
    copy = Node(currNode.data)
    currNode = currNode.next
    copyTail = copy
    while(currNode):
        copyTail.next = Node(currNode.data)
        copyTail = copyTail.next
        currNode = currNode.next
    return copy


head = None
head = insert(head, 1, 0)
head = insert(head, 2, 0)
head = insert(head, 3, 0)
head = insert(head, 4, 0)
head = insert(head, 5, 1)
# remove(head, 0)
walkPrint(head)
dupl = None
dupl = revdup(head, dupl)
print("rev dup of og: ")
walkPrint(dupl)
copy = copyll(head, None)
print("copy of og: ")
walkPrint(copy)

