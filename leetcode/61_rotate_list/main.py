#!/usr/bin/python3

from typing import Optional
import json


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head
        n, cur = 0, head
        while cur:
            n += 1
            cur = cur.next
        if k == 0 or (k % n) == 0:
            return head
        k %= n
        k = n - k
        i = 0
        cur = head
        prev, target = None, None
        while i < k:
            prev = cur
            cur = cur.next
            i += 1
        prev.next = None
        target = cur
        while cur.next:
            cur = cur.next
        cur.next = head
        return target


def printnode(root):
    ans = []
    while root:
        ans.append(root.val)
        root = root.next
    return ans


arr = json.loads(input())
k = int(input())
head, prev = None, None
for a in arr:
    node = ListNode(a)
    if not head:
        head = node
    if prev:
        prev.next = node
    prev = node

sol = Solution()
print(printnode(sol.rotateRight(head, k)))
