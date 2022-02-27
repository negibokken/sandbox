#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        dummy.next = head
        prev = dummy
        cur = head
        while cur:
            if not cur.next:
                break
            first = cur
            second = cur.next
            nxt = second.next

            prev.next = second
            first.next = second.next
            second.next = first

            cur = nxt
            prev = first

        return dummy.next


arr = json.loads(input())
nodes = list(map(ListNode, arr))
prev = None
for node in nodes:
    if prev:
        prev.next = node
    prev = node


def listtoarray(head):
    arr = []
    while head:
        arr.append(head.val)
        head = head.next
    return arr


sol = Solution()
aprint(listtoarray(sol.swapPairs(nodes[0] if len(nodes) > 0 else None)))
