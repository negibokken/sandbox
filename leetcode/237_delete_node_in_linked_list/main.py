#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        nxt = node.next
        node.val = nxt.val
        node.next = nxt.next


arr = json.loads(input())
target, targetNode = int(input()), None
nodes = [ListNode(num) for num in arr]

for i in range(1, len(arr)):
    if target == nodes[i].val:
        targetNode = nodes[i]
    nodes[i-1].next = nodes[i]

sol = Solution()
sol.deleteNode(targetNode)
ans = []
cur = nodes[0]
while cur:
    ans.append(cur.val)
    cur = cur.next
aprint(ans)
