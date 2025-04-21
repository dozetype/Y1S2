class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverse_between(head: ListNode, left: int, right: int) -> ListNode:
    if not head or left == right:
        return head

    dummy = ListNode(0)
    dummy.next = head
    prev = head

    # Step 1: Move `prev` to the node before `left`
    for _ in range(left - 2):
        prev = prev.next

    # Step 2: Reverse the sublist from left to right
    curr = prev.next
    next_node = None

    for _ in range(right - left):
        next_node = curr.next
        curr.next = next_node.next
        next_node.next = prev.next
        prev.next = next_node

    return head

# Helper function to print the linked list
def print_list(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("None")

# Example usage
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)

print("Original list:")
print_list(head)

new_head = reverse_between(head, 2, 4)
print("Reversed sublist (2,4):")
print_list(new_head)
