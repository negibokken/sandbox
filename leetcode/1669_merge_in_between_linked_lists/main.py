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
        prev = None
        cnt = 0
        while cnt <= b:
            if cnt == a:

            cnt += 1
        return None


list1_raw = json.loads(input())
list1 = [ListNode(ele) for ele in list1_raw]
prev = None
for e in list1:
    if prev:
        prev.next = e
    prev = e
a = json.loads(input())
b = json.loads(input())
list2_raw = json.loads(input())
list2 = [ListNode(ele) for ele in list2_raw]
prev = None
for e in list1:
    if prev:
        prev.next = e
    prev = e

sol = Solution()
print(sol.mergeInBetween(list1, a, b, list2))
