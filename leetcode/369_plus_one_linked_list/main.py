#!/usr/bin/python3

from typing import List
import json


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        q = []
        cur = head
        while cur:
            q.append(cur)
            cur = cur .next
        while q:
            node = q.pop()
            node.val += 1
            if node.val >= 10:
                node.val = node.val % 10
                if not q:
                    carry = ListNode(1)
                    carry.next = head
                    head = carry
            else:
                break
        return head


arr = json.loads(input())
nodes = list(map(ListNode, arr))
prev = None
for node in nodes:
    if prev:
        prev.next = node
    prev = node


def walk(node):
    arr = []
    while node:
        arr.append(node.val)
        node = node.next
    ans = []
    for i in arr:
        ans.append(i)
    return ans


sol = Solution()
print("{}".format(walk(sol.plusOne(nodes[0]))).replace(" ", ""))
