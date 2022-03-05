#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def __init__(self):
        self.q = []

    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        i = 1
        prev = dummy
        nxt = None
        while head and i <= right:
            if i < left:
                prev = head
                head = head.next
                i += 1
                continue
            self.q.append(head)
            head = head.next
            i += 1
        while self.q:
            node = self.q.pop()
            prev.next = node
            prev = node
        prev.next = head

        return dummy.next


arr = json.loads(input())
prev = None
nodes = []
for a in arr:
    node = ListNode(a)
    nodes.append(node)
    if prev:
        prev.next = node
    prev = node


left = int(input())
right = int(input())

sol = Solution()


def d(head):
    arr = []
    while head:
        arr.append(head.val)
        head = head.next
    return arr


aprint(d(sol.reverseBetween(nodes[0] if len(
    nodes) > 0 else None, left, right)))
