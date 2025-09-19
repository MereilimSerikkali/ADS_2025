class Node(object):
    def __init__(self, val=0, next=None):
        self.val: int = val
        self.next: Node = next


def insert(head: Node, node: Node, p: int):  
    if p == 0:  
        node.next = head
        return node
    current = head
    index = 0
    while current and index < p - 1:
        current = current.next
        index += 1
    node.next = current.next
    current.next = node
    return head


def remove(head: Node, p: int):  
    if not head:
        return None
    if p == 0:  
        return head.next
    current = head
    index = 0
    while current and index < p - 1:
        current = current.next
        index += 1
    if current and current.next:
        current.next = current.next.next
    return head


def printAll(head: Node):  
    if not head:
        print(-1)
        return
    current = head
    out = []
    while current:
        out.append(str(current.val))
        current = current.next
    print(" ".join(out))


def replace(head: Node, p1: int, p2: int):  
    if p1 == p2:
        return head
    dummy = Node(0, head)
    prev = dummy
    for _ in range(p1):
        prev = prev.next
    node_to_move = prev.next
    prev.next = node_to_move.next
    prev = dummy
    for _ in range(p2):
        prev = prev.next
    node_to_move.next = prev.next
    prev.next = node_to_move
    return dummy.next


def reverse(head: Node):  
    prev = None
    current = head
    while current:
        nxt = current.next
        current.next = prev
        prev = current
        current = nxt
    return prev


def cyclic_left(head: Node, x: int):  
    if not head or not head.next or x == 0:
        return head
    length = 1
    tail = head
    while tail.next:
        tail = tail.next
        length += 1
    x %= length
    if x == 0:
        return head
    current = head
    for _ in range(x - 1):
        current = current.next
    new_head = current.next
    current.next = None
    tail.next = head
    return new_head


def cyclic_right(head: Node, x: int):  
    if not head or not head.next or x == 0:
        return head
    length = 1
    tail = head
    while tail.next:
        tail = tail.next
        length += 1
    x %= length
    if x == 0:
        return head
    return cyclic_left(head, length - x)


head: Node = None

while True:
    vals = [int(i) for i in input().split()]
    if vals[0] == 0:
        break
    elif vals[0] == 1:
        head = insert(head, Node(vals[1]), vals[2])
    elif vals[0] == 2:
        head = remove(head, vals[1])
    elif vals[0] == 3:
        printAll(head)
    elif vals[0] == 4:
        head = replace(head, vals[1], vals[2])
    elif vals[0] == 5:
        head = reverse(head)
    elif vals[0] == 6:
        head = cyclic_left(head, vals[1])
    elif vals[0] == 7:
        head = cyclic_right(head, vals[1])
