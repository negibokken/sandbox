#!/usr/bin/python3

from typing import Optional
import json


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head
        while slow and fast:
            if fast.next and fast.next.next:
                fast = fast.next.next
            else:
                return False
            slow = slow.next
            if slow == fast:
                return True
        return False


arr = json.loads(input())
pos = int(input())
nodes = list(map(ListNode, arr))
prev = None
for i in range(len(nodes)):
    if prev:
        prev.next = nodes[i]
    prev = nodes[i]
if pos >= 0:
    nodes[len(nodes)-1].next = nodes[pos]

sol = Solution()
print(sol.hasCycle(nodes[0]))
