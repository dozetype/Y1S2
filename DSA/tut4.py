class BTNode:
    def __init__(self, item, left=None, right=None):
        self.item = item  # Store the item (integer)
        self.left = left  # Reference to the left child node
        self.right = right  # Reference to the right child node

def insertBSTNode(root, value):
    """ Recursive approach to insert a node into a BST. """
    if root is None:
        return BTNode(value)
    
    if value < root.item:
        root.left = insertBSTNode(root.left, value)
    elif value > root.item:
        root.right = insertBSTNode(root.right, value)
    return root  # Ensure the modified node is returned

def findMin(node):
    """ Find the node with the smallest value in a subtree. """
    while node.left is not None:
        node = node.left
    return node

def removeBSTNode(node, value): #iterative appro
    if(not node):
        return -1
    
    parent = None
    curr = root
    while(curr and curr.item!=value):#if curr is none or curr.item is found, break
        parent = curr
        if(value < curr.item):
            curr = curr.left
        else:
            curr = curr.right
    
    if(not curr): #unable to find value
        return -1
    
    #now curr needs to be deleted
    #case 1 Has no children
    if(not curr.left and not curr.right):
        if(parent.left == curr):
            parent.left = None
        else:
            parent.right = None

    #case 2 Has 1 child
    elif(not curr.left or not curr.right):
        child = curr.left if curr.left else curr.right #if left exist child=left, else =right
        if(parent.left == curr):
            parent.left = child
        else:
            parent.right = child

    #Case 3
    else:
        successor = findMin(curr.right)
        result = removeBSTNode(curr.right, successor.item)
        curr.item = successor.item
        if(result==1):
            return -1
    return 0

def printTree(node, level=0, prefix="Root: "):
    """ Pretty prints the tree structure for better visualization """
    if node is not None:
        print(" " * level + prefix + str(node.item))
        if node.left or node.right:
            if node.left:
                printTree(node.left, level + 4, "L--- ")
            if node.right:
                printTree(node.right, level + 4, "R--- ")


class ListNode:
    def __init__(self, item):
        self.item = item
        self.next = None

class LinkedList:
    def __init__(self):
        self.size = 0
        self.head = None
        self.tail = None

def findNode(ll, index):
    if ll is None or index < 0 or index >= ll.size:
        return None
    temp = ll.head
    while index > 0:
        temp = temp.next
        if temp is None:
            return None
        index -= 1
    return temp

def insertNode(ll, index, value):
    if ll is None or index < 0 or index > ll.size:
        return -1
    if ll.head is None or index == 0:
        cur = ll.head
        ll.head = ListNode(value)
        ll.head.next = cur
        if ll.size == 0:
            ll.tail = ll.head
        ll.size += 1
        return 0
    if index == ll.size:
        pre = ll.tail
        pre.next = ListNode(value)
        ll.tail = pre.next
        ll.size += 1
        return 0
    pre = findNode(ll, index - 1)
    if pre is not None:
        cur = pre.next
        pre.next = ListNode(value)
        pre.next.next = cur
        if index == ll.size:
            ll.tail = pre.next
        ll.size += 1
        return 0
    return -1

def removeNode(ll, index):
    if ll is None or index < 0 or index >= ll.size:
        return -1
    if index == 0:
        cur = ll.head.next
        ll.head = cur
        ll.size -= 1
        if ll.size == 0:
            ll.tail = None
        return 0
    pre = findNode(ll, index - 1)
    if pre is not None:
        if index == ll.size - 1:
            ll.tail = pre
            pre.next = None
        else:
            cur = pre.next.next
            pre.next = cur
        ll.size -= 1
        return 0
    return -1

class Stack:
    def __init__(self):
        self.ll = LinkedList()

    def push(self, item):
        insertNode(self.ll, 0, item)

    def pop(self):
        if self.isEmpty():
            return None
        item = self.ll.head.item
        removeNode(self.ll, 0)
        return item

    def peek(self):
        if self.isEmpty():
            return None
        return self.ll.head.item

    def isEmpty(self):
        return self.ll.size == 0

class Queue:
    def __init__(self):
        self.ll = LinkedList()

    def enQueue(self, item):
        insertNode(self.ll, self.ll.size, item)

    def deQueue(self):
        if self.isEmpty():
            return None
        item = self.ll.head.item
        removeNode(self.ll, 0)
        return item

    def isEmpty(self):
        return self.ll.size == 0
    

################################################################################################
#Question 2 Level Order traversal(BFS)
def levelOrderIterative(root):
    q = Queue()
    q.enQueue(root) #root layer
    while(q.ll.head): #while q not empty
        currNode = q.deQueue()
        print(currNode.item, end=" ")
        if(currNode.left):
            q.enQueue(currNode.left)
        if(currNode.right):
            q.enQueue(currNode.right)

def preOrderIterative(root):
    st = Stack()
    st.push(root)
    while(st.ll.head):
        currNode = st.pop()
        print(currNode.item, end=" ")
        if(currNode.right):
            st.push(currNode.right)
        if(currNode.left):
            st.push(currNode.left)

def preOrderReccursive(root):
    if(not root):
        return
    print(root.item, end=" ")
    preOrderReccursive(root.left)
    preOrderReccursive(root.right)

def inOrderReccursive(root):
    if(not root):
        return
    inOrderReccursive(root.left)
    print(root.item, end=" ")
    inOrderReccursive(root.right)

def inOrderIterative(root):
    st = Stack()
    curr = root
    while(curr or not st.isEmpty()):
        if(curr):
            st.push(curr)
            curr = curr.left
        else:
            curr = st.pop()
            print(curr.item, end=" ")
            curr = curr.right

def postOrderReccursive(root):
    if(not root):
        return
    postOrderReccursive(root.left)
    postOrderReccursive(root.right)
    print(root.item, end=" ")

def postOrderIterative(root):
    st = Stack()
    curr = root
    while(True):
        while(curr):
            st.push(curr) #1 is used to check right, other used for printing
            st.push(curr)
            curr = curr.left
        
        if(st.isEmpty()):
            return
        
        curr = st.pop()
        if(st.ll.head and st.peek()==curr):
            curr = curr.right
        else:
            print(curr.item, end=" ")
            curr = None

if __name__ == "__main__":
    root = None
    
    print("\nFirst, let's build the BST:")
    while True:
        try:
            value = input("\nEnter a value to insert (-1 to quit): ")
            if not value:
                continue  # Ignore empty inputs
                
            i = int(value)
            if i == -1:
                break
                
            root = insertBSTNode(root, i)
            print("\nCurrent BST structure:")
            printTree(root)
            print("\nIn-order traversal: ", end="")
            print()
            
        except ValueError:
            print("Invalid input! Please enter an integer.")

    levelOrderIterative(root)
    print()
    preOrderIterative(root)
    preOrderReccursive(root)
    print("\nbruh")
    postOrderReccursive(root)
    print()
    postOrderIterative(root)