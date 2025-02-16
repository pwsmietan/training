# Python program to illustrate how to find the middle element
# by using Floyd's Cycle Finding Algorithm


class Node:
    def __init__(self, x):
        self.data = x
        self.next = None


# Function to get the middle of the linked list
def getMiddle(head):

    # Initialize the slow and fast pointer to the
    # head of the linked list
    slow_ptr = head
    fast_ptr = head

    while fast_ptr is not None and fast_ptr.next is not None:

        # Move the fast pointer by two nodes
        fast_ptr = fast_ptr.next.next

        # Move the slow pointer by one node
        slow_ptr = slow_ptr.next

    # Return the slow pointer which is currently pointing to the
    # middle node of the linked list
    return slow_ptr.data


def main():

    # Create a hard-coded linked list:
    # 10 -> 20 -> 30 -> 40 -> 50 -> 60
    head = Node(10)
    head.next = Node(20)
    head.next.next = Node(30)
    head.next.next.next = Node(40)
    head.next.next.next.next = Node(50)
    head.next.next.next.next.next = Node(60)

    print(getMiddle(head))


if __name__ == "__main__":
    main()
