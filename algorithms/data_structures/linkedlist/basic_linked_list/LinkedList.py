from Node import Node
class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)

        if not self.head:
            self.head = new_node
            return

        last = self.head
        while last_node.next:
            last_node = last_node.next

        last_node.next = new_node

    def prepend(self, data):
        new_node = Node(data)

        if not self.head:
            self.head = new_node
            return

        new_node.next = self.head
        self.head = new_node

    def pop_left(self):
        if self.head is None:
            return None

        current_node = self.head
        self.head = self.head.next
        return current_node

    def pop_right(self):
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
        return end_node

    def display_content(self):
        node = self.head
        while node:
            print(f"{node.data} => ",end="")
            node = node.next

        print("End")

    def reverse_link_list(self):
        previous_node = None
        current_node = self.head

        while current_node:
            temp_next = current_node.next
            current_node.next = previous_node
            previous_node = current_node
            current_node = temp_next

        self.head = previous_node



if __name__ == "__main__":
    linkedlist = LinkedList()
    linkedlist.reverse_link_list()
    linkedlist.append(1)
    linkedlist.append(2)
    linkedlist.append(3)
    linkedlist.append(4)
    linkedlist.display_content()
    linkedlist.reverse_link_list()
    linkedlist.display_content()
    print(f"Popped Element: {linkedlist.pop_right().data}")
    linkedlist.display_content()
    print(f"pop_left Element: {linkedlist.pop_left().data}")
    print(f"Popped Element: {linkedlist.pop_right().data}")
    print('Reverse 1 element linked list: START')
    linkedlist.reverse_link_list()
    linkedlist.display_content()
    print('Reverse 1 element linked list: END')
    print(f"Popped Element: {linkedlist.pop_right().data}")
    linkedlist.display_content()