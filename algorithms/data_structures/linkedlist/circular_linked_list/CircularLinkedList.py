from Node import Node

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def get_last_node(self):
        # O(N)
        if not self.head:
            return None

        last = self.head

        while last.next != self.head:
            last = last.next
        return last

    def append(self, data):
        # O(N)
        new_node = Node(data)

        if not self.head:
            new_node.next = new_node
            self.head = new_node
            return

        last_node = self.get_last_node()

        new_node.next = self.head
        last_node.next = new_node

    def prepend(self, data):
        # O(N)
        new_node = Node(data)

        if not self.head:
            new_node.next = new_node
            self.head = new_node
            return

        last_node = self.get_last_node()

        new_node.next = self.head
        self.head = new_node

        last_node.next = self.head

    def display_content(self):
        # O(N)
        if self.head is None:
            print("-EMPTY-")
            return
        # print(self.head)

        node = self.head
        while node.next != self.head:
            print(f"{node.data} => ",end="")
            node = node.next

        print(f"{node.data} => ", end="Go Back to beginning...\n")

    def pop_left(self):
        if self.head is None:
            return None

        current_node = self.head
        if self.head.next == self.head:
            current_node.next = None
            self.head = None
            return current_node

        last_node = self.get_last_node()

        self.head = self.head.next
        last_node.next = self.head

        current_node.next = None
        return current_node

    def pop_right(self):
        if self.head is None:
            return None

        current_node = self.head
        while current_node.next.next is not None:
            current_node = current_node.next

        end_node = current_node.next
        current_node.next = None
        return end_node

    def reverse_link_list(self):
        # O(N)
        previous_node = None
        current_node = self.head

        while True:
            temp_next = current_node.next
            current_node.next = previous_node
            previous_node = current_node
            current_node = temp_next
            if current_node == self.head:
                break

        self.head.next = previous_node
        self.head = previous_node

    def get_mid_node(self):
        '''
            Turtoise & Hare Method
            Cases to handle:
                - empty case ==> Return None
                - Single Element ==> return 1st node
                - 2 nodes ==> return 1st case
                - odd number
                - even number
        '''
        if not self.head:
            return None

        fast_pointer = slow_pointer = self.head

        # Note: iter +1 so fast_pointer != head
        slow_pointer = slow_pointer.next
        fast_pointer = fast_pointer.next.next

        while fast_pointer != self.head and fast_pointer.next != self.head:
            slow_pointer = slow_pointer.next
            fast_pointer = fast_pointer.next.next

        return slow_pointer

def basic_test():
    linkedlist = CircularLinkedList()
    linkedlist.prepend(1)
    linkedlist.append(2)
    linkedlist.append(3)
    linkedlist.append(4)
    linkedlist.display_content()
    linkedlist.reverse_link_list()
    linkedlist.display_content()
    print(f"pop_left Element: {linkedlist.pop_left().data}")
    linkedlist.display_content()
    print(f"pop_left Element: {linkedlist.pop_left().data}")
    linkedlist.display_content()
    print(f"pop_left Element: {linkedlist.pop_left().data}")
    linkedlist.display_content()
    print(f"pop_left Element: {linkedlist.pop_left().data}")
    linkedlist.display_content()

def get_mid_node_test():
    linkedlist = CircularLinkedList()

    if(linkedlist.get_mid_node() == None):
        print('Successful -- 0 Node Case is None')
    else:
        print('Unsuccessful -- 0 Node case is not None')

    linkedlist.append(0)
    assert(linkedlist.get_mid_node().data == 0)
    linkedlist.display_content()

    linkedlist.append(1)
    print(f"2 Node Case: {linkedlist.get_mid_node().data}")
    assert(linkedlist.get_mid_node().data == 1)
    linkedlist.display_content()

    linkedlist.append(2)
    print(f"Basic Odd # Node Case: {linkedlist.get_mid_node().data}")
    assert(linkedlist.get_mid_node().data == 1)
    linkedlist.display_content()

    linkedlist.append(3)
    print(f"Basic Even # Node Case: {linkedlist.get_mid_node().data}")
    assert(linkedlist.get_mid_node().data == 2)
    linkedlist.display_content()

    linkedlist.append(4)
    linkedlist.append(5)
    linkedlist.append(6)
    print(f"Odd # Node Case: {linkedlist.get_mid_node().data}")
    assert(linkedlist.get_mid_node().data == 3)
    linkedlist.display_content()
    linkedlist.append(7)
    print(f"Odd Even # Node Case: {linkedlist.get_mid_node().data}")
    assert(linkedlist.get_mid_node().data == 4)
    linkedlist.display_content()

if __name__ == "__main__":
    # basic_test()
    get_mid_node_test()