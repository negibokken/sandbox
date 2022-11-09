#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        dummy = ListNode()
        dummy.next = list1
        cur, prev = dummy, None
        cnt = 0
        before_a, after_b = None, None
        while cnt <= b+2:
            if cnt == a:
                before_a = cur
            elif cnt == b + 2:
                after_b = cur
            cur = cur.next
            cnt += 1
        before_a.next = list2
        cur = list2
        while cur:
            prev = cur
            cur = cur.next
        prev.next = after_b
        return dummy.next


def printListNode(head):
    while head:
        print(head.val)
        head = head.next
    print("\n")


list1_raw = json.loads(input())
list1 = [ListNode(ele) for ele in list1_raw]
prev = None
for e in list1:
    if prev:
        prev.next = e
    prev = e
# printListNode(list1[0])
a = json.loads(input())
b = json.loads(input())
list2_raw = json.loads(input())
list2 = [ListNode(ele) for ele in list2_raw]
prev = None
for e in list2:
    if prev:
        prev.next = e
    prev = e
# printListNode(list2[0])
# printListNode(list2[0])
sol = Solution()
ans = sol.mergeInBetween(list1[0], a, b, list2[1])
arr = []
while ans:
    arr.append(ans.val)
    ans = ans.next
aprint(arr)
