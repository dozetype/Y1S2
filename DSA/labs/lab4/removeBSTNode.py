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
    # if(not node):
    #     return -1
    
    # parent = None
    # curr = root
    # while(curr and curr.item!=value):#if curr is none or curr.item is found, break
    #     parent = curr
    #     if(value < curr.item):
    #         curr = curr.left
    #     else:
    #         curr = curr.right
    
    # if(not curr): #unable to find value
    #     return -1
    
    # #now curr needs to be deleted
    # #case 1 Has no children
    # if(not curr.left and not curr.right):
    #     if(parent.left == curr):
    #         parent.left = None
    #     else:
    #         parent.right = None

    # #case 2 Has 1 child
    # elif(not curr.left or not curr.right):
    #     child = curr.left if curr.left else curr.right #if left exist child=left, else =right
    #     if(parent.left == curr):
    #         parent.left = child
    #     else:
    #         parent.right = child

    # #Case 3
    # else:
    #     successor = findMin(curr.right)
    #     result = removeBSTNode(curr.right, successor.item)
    #     curr.item = successor.item
    #     if(result==1):
    #         return -1
    # return 0
    if(not node): #return if nothing in tree
        return -1
    curr = node
    parent = None
    while(curr):
        if(value < curr.item): #traverse left
            parent = curr
            curr = curr.left
        elif(value > curr.item): #traverse right
            parent = curr
            curr = curr.right
        elif(value == curr.item): #found
            if(curr.left): #check for left child(handles both 1 and 2 children)
                parent = curr
                target = curr.left
                while(target.right):
                    parent = target
                    target = target.right
                curr.item = target.item
                if(parent.left == target):
                    parent.left = target.left
                else:
                    parent.right = target.left
            elif(curr.right): #check for right 
                parent = curr
                target = curr.right
                while(target.left):
                    parent = target
                    target = target.left
                curr.item = target.item
                if(parent.left == target):
                    parent.left = target.right
                else:
                    parent.right = target.right
            else: #if 0 child
                if(parent == None):
                    return -1
                elif(parent.left == curr):
                    parent.left = None
                else:
                    parent.right = None

            return 0
        else:
            return -1

def printBSTInOrder(node):
    """ Print BST items in sorted order using in-order traversal. """
    if node:
        printBSTInOrder(node.left)
        print(node.item, end=" ")
        printBSTInOrder(node.right)

def printTree(node, level=0, prefix="Root: "):
    """ Pretty prints the tree structure for better visualization """
    if node is not None:
        print(" " * level + prefix + str(node.item))
        if node.left or node.right:
            if node.left:
                printTree(node.left, level + 4, "L--- ")
            if node.right:
                printTree(node.right, level + 4, "R--- ")

if __name__ == "__main__":
    root = None
    print("Binary Search Tree Node Removal Program")
    print("=====================================")
    
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
            printBSTInOrder(root)
            print()
            
        except ValueError:
            print("Invalid input! Please enter an integer.")

    print("\nNow let's remove nodes:")
    while True:
        try:
            value = input("\nEnter a value to remove (-1 to quit): ")
            if not value:
                continue  # Ignore empty inputs
                
            i = int(value)
            if i == -1:
                break
                
            result = removeBSTNode(root, i)
            if result == 0:
                print("\nBST structure after removal:")
                printTree(root)
                print("\nIn-order traversal: ", end="")
                printBSTInOrder(root)
                print()
            else:  # result == -1
                print("Value not found in the tree!")
            
        except ValueError:
            print("Invalid input! Please enter an integer.")