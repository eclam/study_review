from Node import Node
class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def get_last_node_greedy(self):
        # O(N)
        if not self.head:
            return None

        last = self.head
        while last.next != self.head:
            last = last.next
        return last

    def get_last_node_quick(self):
        # O(1)
        if not self.head:
            return None

        if self.head.prev == self.head:
            return self.head

        return self.head.prev

    def append(self, data):
        new_node = Node(data)

        if not self.head:
            self.head = new_node
            self.head.next = new_node
            self.head.prev = new_node
            return

        last_node = self.get_last_node_quick()
        last_node.next = new_node

        new_node.prev = last_node
        new_node.next = self.head
        self.head.prev = new_node

    def prepend(self, data):
        new_node = Node(data)

        if not self.head:
            new_node.next = new_node
            new_node.prev = new_node
            self.head = new_node
            return

        last_node = self.get_last_node_quick()

        new_node.next = self.head
        self.head.prev = new_node

        self.head = new_node
        last_node.next = self.head

    def pop_right(self):
        # Case: Empty
        if self.head is None:
            return None

        # Case: Single Node
        current_node = self.head
        if self.head.next == self.head:
            self.head = None
            current_node.next = None
            current_node.prev = None
            return current_node

        # Case: Generic
        while current_node.next.next is not self.head:
            current_node = current_node.next

        end_node = current_node.next

        current_node.next = self.head
        self.head.prev = current_node

        end_node.prev = None
        end_node.next = None
        return end_node

    def pop_left(self):
        # Case: Empty
        if self.head is None:
            return None

        # Case: Single Node
        current_node = self.head
        if self.head.next == self.head:
            self.head = None
            current_node.next = None
            current_node.prev = None
            return current_node

        # Case: Generic
        last_node = self.get_last_node_quick()
        self.head = self.head.next
        self.head.prev = last_node
        last_node.next = self.head

        return current_node

    def display_content(self):
        # O(N)
        if not self.head:
            print("-EMPTY-")
            return
        print(self.head.data)

        node = self.head
        while node.next != self.head:
            print(f"{node.data} <=> ",end="")
            node = node.next

        print(f"{node.data} <=> ", end="Go Back to beginning... | Now Reverse: ")

        while node != self.head:
            print(f"{node.data} <=> ",end="")
            node = node.prev

        print(f"{node.data} <=> ", end="Go Back to beginning...\n")

    def reverse_link_list(self):
        previous_node = None
        current_node = self.head

        while True:
            temp_next = current_node.next
            current_node.next = previous_node
            current_node.prev = temp_next

            previous_node = current_node
            current_node = temp_next
            if current_node == self.head:
                break

        self.head.next = previous_node
        self.head = previous_node



if __name__ == "__main__":
    linkedlist = DoublyLinkedList()
    linkedlist.append(1)
    linkedlist.display_content()
    check = linkedlist.pop_left()
    linkedlist.display_content()
    linkedlist.append(1)
    check = linkedlist.pop_right()
    linkedlist.display_content()
    linkedlist.append(2)
    linkedlist.append(3)
    linkedlist.append(4)
    linkedlist.prepend(1)
    linkedlist.display_content()
    linkedlist.reverse_link_list()
    linkedlist.display_content()
    print(f"Popped Element: {linkedlist.pop_right().data}")
    linkedlist.display_content()
    print(f"pop_left Element: {linkedlist.pop_left().data}")
    linkedlist.display_content()
    print(f"pop_left Element: {linkedlist.pop_left().data}")
    linkedlist.display_content()
    print(f"pop_left Element: {linkedlist.pop_left().data}")
    linkedlist.display_content()
    linkedlist.append(3)
    linkedlist.append(2)
    linkedlist.display_content()
    print(f"Popped Element: {linkedlist.pop_right().data}")
    linkedlist.display_content()
    print(f"Popped Element: {linkedlist.pop_right().data}")
    linkedlist.display_content()
    data = linkedlist.pop_left()
    if data is None:
        print(f"pop_left Element empty works")

    data = linkedlist.pop_right()
    if data is None:
        print(f"pop_right Element empty works")

    linkedlist.display_content()