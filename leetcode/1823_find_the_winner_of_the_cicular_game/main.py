#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Node:
    def __init__(self, _val, _next=None, _prev=None):
        self.val = _val
        self.next = _next
        self.prev = _prev


def makeRingList(n):
    nodes = [Node(i+1) for i in range(0, n)]
    for i in range(0, n):
        nodes[i].next = nodes[(i+1) % n]
        nodes[i].prev = nodes[(n+i-1) % n]
    return nodes[0]


class Solution:

    def findTheWinner(self, n: int, k: int) -> int:
        cnt = 1
        cur, prev = makeRingList(n), None
        while 1:
            if cur == cur.next:
                return cur.val
            nxt = cur.next
            if (cnt % k) == 0:
                cur.prev.next, cur.next.prev = cur.next, cur.prev
            cnt += 1
            prev, cur = cur, nxt
        return None


n = int(input())
k = int(input())

sol = Solution()
print(sol.findTheWinner(n, k))
