#!/usr/bin/python3

from typing import List
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
        while head:
            while left <= i and i < right:
                self.q.append(head)
                prev = head
                head = head.next
                i += 1
            prev = head
            head = head.next
            i += 1

        return None


arr = json.loads(input())
prev = None
for a in arr:
    node = ListNode(a)
    if not prev:
        prev.next = node
    prev = node


left = int(inputo)
right = int(inputo)

sol = Solution()
