from Node import Node
class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)

        if not self.head:
            self.head = new_node
            return

        last = self.head
        while last.next:
            last = last.next

        last.next = new_node
        new_node.prev = last

    def prepend(self, data):
        new_node = Node(data)

        if not self.head:
            self.head = new_node
            return

        new_node.next = self.head
        self.head.prev = new_node

        self.head = new_node

    def pop_right(self):
        if self.head is None:
            return None

        current_node = self.head
        self.head = self.head.next
        self.head.prev = None

        current_node.next = None
        return current_node

    def pop_left(self):
        if self.head is None:
            return None

        if self.head.next is None:
            end_node = self.head
            self.head = None
            return end_node

        current_node = self.head
        while current_node.next.next is not None:
            current_node = current_node.next

        end_node = current_node.next
        current_node.next = None

        end_node.prev = None
        return end_node

    def display_content(self):
        node = self.head
        while node.next:
            print(f"{node.data} => ",end="")
            node = node.next

        print(f"{node.data} => ", end="| Now Reverse: ")

        while node:
            print(f"{node.data} => ",end="")
            node = node.prev
        print("END")

    def reverse_link_list(self):
        previous_node = None
        current_node = self.head

        while current_node:
            temp_next = current_node.next
            current_node.next = previous_node
            current_node.prev = temp_next

            previous_node = current_node
            current_node = temp_next

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

        while fast_pointer and fast_pointer.next:
            slow_pointer = slow_pointer.next
            fast_pointer = fast_pointer.next.next

        return slow_pointer


if __name__ == "__main__":
    linkedlist = DoublyLinkedList()
    linkedlist.reverse_link_list()
    linkedlist.append(1)
    linkedlist.append(2)
    linkedlist.append(3)
    linkedlist.append(4)
    linkedlist.display_content()
    linkedlist.reverse_link_list()
    linkedlist.display_content()
    print(f"Popped Element: {linkedlist.pop_left().data}")
    linkedlist.display_content()
    print(f"pop_right Element: {linkedlist.pop_right().data}")
    linkedlist.display_content()
    print(f"pop_right Element: {linkedlist.pop_left().data}")
    linkedlist.display_content()