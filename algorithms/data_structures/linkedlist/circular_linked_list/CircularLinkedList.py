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
        print(self.head)

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



if __name__ == "__main__":
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