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
        dummy .next = head
        num = 0
        cur = dummy.next
        while cur:
            cur = cur.next
            num += 1
        i = 0
        prev = dummy
        cur = dummy.next
        while cur:
            if i == num-n:
                prev.next = cur.next
                break
            prev = cur
            cur = cur.next
            i += 1
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
