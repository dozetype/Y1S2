class TrieNode:
    def __init__(self, char=None):
        self.char = char
        self.first_child = None
        self.next_sibling = None
        self.is_end_of_word = False

class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)  # Add to the end

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)  # Remove from the front
        return None

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)


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
        new_node = TrieNode(char)
        new_node.next_sibling = node.first_child
        node.first_child = new_node
        return new_node

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

    # all the previous codes will be given to students as template.
    # THe following codes are codes for tutorial questions

    def collect_all_words(self, node, prefix, results):
        if node.is_end_of_word:
            results.append(prefix)

        child = node.first_child
        while child:
            self.collect_all_words(child, prefix + child.char, results)
            child = child.next_sibling

    def find_words_with_prefix(self, prefix): #question 2
        results = []
        node = self.root
        for char in prefix:
            node = self._find_child(node, char)
            if(not node):
                return []
            
        def collect(node, prefix, results):
            if(node.is_end_of_word):
                results.append(prefix)
            child = node.first_child
            while(child):
                collect(child, prefix+child.char, results)
                child = child.next_sibling
            
        collect(node, prefix, results)
        return results
        

    def count_words(self, node): #question 1
        if node.is_end_of_word:
            cnt = 1
        else:
            cnt = 0

        child = node.first_child
        while child:
            cnt += self.count_words(child)
            child = child.next_sibling
        return cnt

    # def find_shortest_word_with_prefix(self, prefix):#question 3
    #     # Step 1: Traverse to the end of the prefix
    #     node = self.root
    #     for char in prefix:
    #         node = self._find_child(node, char)
    #         if not node:
    #             return None  # Prefix not found

    #     # Step 2: BFS
    #     queue = Queue()
    #     queue.enqueue((node, prefix, 0))  # (node, word, depth)
    #     shortest_words = []
    #     min_depth = None

    #     while not queue.is_empty():
    #         node, word, depth = queue.dequeue()

    #         if node.is_end_of_word:
    #             if min_depth is None:
    #                 min_depth = depth
    #             if depth == min_depth:
    #                 shortest_words.append(word)
    #             elif depth > min_depth:
    #                 break  # We already found the shortest level, skip deeper

    #         if min_depth is not None and depth >= min_depth:
    #             continue  # don't enqueue deeper nodes

    #         child = node.first_child
    #         while child:
    #             queue.enqueue((child, word + child.char, depth + 1))
    #             child = child.next_sibling

    #     return shortest_words
    


def hash_insert(key, hash_table):
#write your codes here
    slot = hash_func(key)
    curr = slot
    while curr != -1: #Check for Duplicate first
        if hash_table[curr].key == key:
            return -1  # Duplicate
        curr = hash_table[curr].next

    for i in range(TABLESIZE):
        newSlot = (slot + i) % TABLESIZE
        if hash_table[newSlot].indicator == EMPTY:
            hash_table[newSlot].key = key
            hash_table[newSlot].indicator = USED
            if newSlot != slot: #Not First Try
                curr = slot
                while hash_table[curr].next != -1: #Finding Link
                    curr = hash_table[curr].next
                hash_table[curr].next = newSlot
            return newSlot

    return float("inf")

def hash_find(key, hash_table):
#write your codes here
    slot = hash_func(key)
    if(hash_table[slot].indicator == EMPTY): #first try empty, no pt cont
        return -1
    while(slot>=0):
        if(hash_table[slot].key == key): #Found
            return slot
        elif(hash_table[slot].indicator == USED): #Go next 
            slot = hash_table[slot].next
    return -1 #Don't exist


    def bfs(self):
        q = Queue()
        node = self.root
        q.enqueue((node, ""))
        while(not q.is_empty()):
            node, prefix = q.dequeue()
            if(node.is_end_of_word):
                print(prefix)
            child = node.first_child
            while(child):
                q.enqueue((child, prefix+child.char))
                child = child.next_sibling

# Assume Trie, TrieNode, and Queue classes have already been defined.

# Create a new Trie instance
trie = Trie()

# Insert words into the Trie
trie.insert("cat")
trie.insert("car")
trie.insert("care")
trie.insert("cane")
trie.insert("camera")
trie.insert("campus")
trie.insert("camp")
trie.insert("dog")
trie.insert("dot")
trie.insert("zzzzzzzzzzz")

# 1. Count total words in the Trie
print("Total words in Trie:", trie.count_words(trie.root))  # Output: 8

# 2. Find all words that start with a given prefix
prefix1 = "ca"
results = trie.find_words_with_prefix(prefix1)
print(f"Words starting with '{prefix1}': ", results)
# Output: ['cat', 'car', 'care', 'camera', 'campus', 'camp']

prefix2 = "do"
print(f"Words starting with '{prefix2}':", trie.find_words_with_prefix(prefix2))
# Output: ['dog', 'dot']

prefix3 = "z"
print(f"Words starting with '{prefix3}':", trie.find_words_with_prefix(prefix3))
# Output: []

# 3. Find the shortest word with a given prefix
print(f"Shortest word starting with '{prefix1}':", trie.find_shortest_word_with_prefix(prefix1))
# Output: "car"

print(f"Shortest word starting with '{prefix2}':", trie.find_shortest_word_with_prefix(prefix2))
# Output: "dog"

print(f"Shortest word starting with '{prefix3}':", trie.find_shortest_word_with_prefix(prefix3))
# Output: None

trie.bfs()