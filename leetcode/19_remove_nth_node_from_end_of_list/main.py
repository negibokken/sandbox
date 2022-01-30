#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect

# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode()
        dummy.next = head
        fast, slow = dummy, dummy
        for i in range(n+1):
            fast = fast.next
        while fast:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return dummy.next


n = int(input())
arr = json.loads(input())
nodes = list(map(ListNode, arr))
prev = None
for node in nodes:
    if prev:
        prev.next = node
    prev = node

sol = Solution()
head = sol.removeNthFromEnd(nodes[0], n)
arr = []


def walk(h):
    while h:
        arr.append(h.val)
        h = h.next


walk(head)

print("{}".format(arr).replace(" ", ""))
