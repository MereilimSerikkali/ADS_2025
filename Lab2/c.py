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

    def delete_every_second(self):
        current = self.head
        while current and current.next:
            temp = current.next
            current.next = temp.next  # skip over second node
            current = current.next    # move to the next "first-thread" node

    def to_list(self):
        result = []
        current = self.head
        while current:
            result.append(current.data)
            current = current.next
        return result


# ---- Main Program ----
n = int(input().strip())
arr = list(map(int, input().split()))

ll = LinkedList()
for num in arr:
    ll.append(num)

ll.delete_every_second()
print(" ".join(map(str, ll.to_list())))
