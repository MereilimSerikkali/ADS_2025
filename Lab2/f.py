class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def insert_at(self, data, pos):
        new_node = Node(data)
        if pos == 0:  
            new_node.next = self.head
            self.head = new_node
            if not self.tail:
                self.tail = new_node
            return

        current = self.head
        index = 0
        while current and index < pos - 1:
            current = current.next
            index += 1

        if not current:  
            return

        new_node.next = current.next
        current.next = new_node

        if new_node.next is None:  
            self.tail = new_node

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next
        print()


n = int(input().strip())
ll = LinkedList()

for _ in range(n):
    ll.append(int(input().strip()))

data = int(input().strip())  
pos = int(input().strip())  

ll.insert_at(data, pos)
ll.print_list()
