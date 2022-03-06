#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: Optional[ListNode], m: int, n: int) -> Optional[ListNode]:
        if not head:
            return None

        left, right = head, head
        stop = False

        def recurseAndReverse(right, m, n):
            nonlocal left, stop
            if n == 1:
                return
            right = right.next

            if m > 1:
                left = left.next

            recurseAndReverse(right, m-1, n-1)

            if left == right or right.next == left:
                stop = True

            if not stop:
                left.val, right.val = right.val, left.val
                left = left.next

        recurseAndReverse(right, m, n)
        return head


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
