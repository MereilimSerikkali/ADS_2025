class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
    
    def enqueue(self, val):
        new_node = Node(val)
        if not self.rear:
            self.front = self.rear = new_node
            return
        self.rear.next = new_node
        self.rear = new_node
    
    def dequeue(self):
        if not self.front:
            return None
        val = self.front.val
        self.front = self.front.next
        if not self.front:
            self.rear = None
        return val
    
    def peek(self):
        if not self.front:
            return None
        return self.front.val
    
    def is_empty(self):
        return self.front is None


t = int(input().strip())
for _ in range(t):
    n = int(input().strip())
    stream = input().split()
    
    freq = {}
    q = Queue()
    result = []
    
    for ch in stream:
        freq[ch] = freq.get(ch, 0) + 1
        q.enqueue(ch)
        while not q.is_empty() and freq[q.peek()] > 1:
            q.dequeue()
        
        if not q.is_empty():
            result.append(q.peek())
        else:
            result.append("-1")
    
    print(" ".join(result))
