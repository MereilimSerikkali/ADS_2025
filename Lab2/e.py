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

    def remove_consecutive_duplicates(self):
        current = self.head
        while current and current.next:
            if current.data == current.next.data:
                current.next = current.next.next
            else:
                current = current.next

    def to_list(self):
        result = []
        current = self.head
        while current:
            result.append(current.data)
            current = current.next
        return result

def main():
    n = int(input().strip())
    ll = LinkedList()
    for _ in range(n):
        name = input().strip()
        ll.append(name)
        
    ll.remove_consecutive_duplicates()
    students = ll.to_list()
    students.reverse()
    
    print(f"All in all: {len(students)}")
    print("Students:")
    for s in students:
        print(s)

if __name__ == "__main__":
    main()