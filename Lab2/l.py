class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# implement this function
# don't change anything else
def findMaxSum(n: int, head: ListNode) -> int:
    # Kadane's algorithm for linked list
    current_sum = head.val
    max_sum = head.val
    node = head.next
    
    while node:
        current_sum = max(node.val, current_sum + node.val)
        max_sum = max(max_sum, current_sum)
        node = node.next
    
    return max_sum


n = int(input())
a = list(map(int, input().split()))
head = ListNode(0)
tail = ListNode(0)

for i in range(n):
    tmp = ListNode(a[i])
    if i == 0:
        head = tmp
        tail = tmp
    else:
        tail.next = tmp
        tail = tmp

print(findMaxSum(n, head))
