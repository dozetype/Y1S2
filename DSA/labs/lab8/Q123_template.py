class TrieNode:
    def __init__(self, char=None):
        self.char = char
        self.first_child = None
        self.next_sibling = None
        self.is_end_of_word = False

class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        return None

    def is_empty(self):
        return len(self.items) == 0

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def _find_child(self, node, char):
        current = node.first_child
        while current:
            if current.char == char:
                return current
            current = current.next_sibling
        return None

    def _add_child(self, node, char):
        #add your implementations to insert a child following the alphabetical order
        newNode = TrieNode(char)

        #inserting at the front
        if(not node.first_child or char < node.first_child.char):
            newNode.next_sibling = node.first_child
            node.first_child = newNode
            return node.first_child
        
        #Finding the position to insert
        prev = node.first_child
        curr = node.next_sibling
        while(curr and curr.char < char):
            prev = curr
            curr = curr.next_sibling

        #Inserting at middle or end
        newNode.next_sibling = curr
        prev.next_sibling = newNode
        return newNode

    def insert(self, word):
        node = self.root
        for char in word:
            child = self._find_child(node, char)
            if not child:
                child = self._add_child(node, char)
            node = child
        node.is_end_of_word = True

    def search(self, word):
        node = self.root
        for char in word:
            node = self._find_child(node, char)
            if not node:
                return False
        return node.is_end_of_word

    def print_words_alphabetically(self):
        # add you implementations
        dfs(self.root, "")


    def print_words_reverse_alphabetically(self):
        #add your implementations
        words = []
        self.revDFS(self.root, "", words)
        for word in words:
            print(word)

    def revDFS(self, node, prefix, words):
        st = Stack() #used to reverse the LL
        child = node.first_child
        while(child):
            st.push(child)
            child = child.next_sibling
        #going down the tree from the right side first
        while(not st.is_empty()):
            child = st.pop()
            self.revDFS(child, prefix+child.char, words)
        
        if(node.is_end_of_word):
            words.append(prefix)


def dfs(node, prefix):
    if node.is_end_of_word:
        print(prefix)
    #DFS
    child = node.first_child
    while child:
        dfs(child, prefix+child.char)
        child = child.next_sibling

# Assume Trie, TrieNode, and Queue classes have already been defined.
# Create a new Trie instance
trie = Trie()
trie.insert("car")
trie.insert("care")
trie.insert("cat")
trie.insert("camp")
trie.insert("camera")


trie.print_words_reverse_alphabetically()
trie.print_words_alphabetically()
