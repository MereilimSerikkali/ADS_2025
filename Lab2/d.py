class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
        
class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node  
    def traverse(self):
        current = self.head
        while current:
            yield current.data
            current = current.next

n = int(input().strip())
arr = list(map(int, input().split()))

dll = DoublyLinkedList()
for num in arr:
    dll.append(num)
    
freq = {}
for num in dll.traverse():
    freq[num] = freq.get(num, 0) + 1
    
max_freq = max(freq.values())
modes = [num for num, f in freq.items() if f == max_freq]
modes.sort(reverse = True)
print(" ".join(map(str, modes)))