#!/usr/bin/python3

from typing import List
import json
from collections import deque


class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    def flattenHelper(self, head):
        prev = None
        cur = head
        while cur is not None:
            if cur is not None and cur.child is not None:
                nxt = cur.next
                cur.next = cur.child
                cur.child.prev = cur
                last = self.flattenHelper(cur.child)
                cur.child = None
                cur = last
                cur.next = nxt
                if nxt is not None:
                    nxt.prev = last
            prev = cur
            cur = cur.next
        return prev

    def flatten(self, head: 'Node') -> 'Node':
        self.flattenHelper(head) 
        return head


def connectLinkedList(arr):
    if len(arr) == 0:
        return None
    nodes = list(map(lambda x: Node(x, None, None, None) if x is not None else None, arr))
    prev = None
    cnt = 1
    heads = []
    headsCnt = []
    for node in nodes:
        if node is None:
            cnt += 1
            prev = None
            continue
        elif (node is not None) and cnt != 0:
            headsCnt.append(cnt)
            cnt = 0
            heads.append(node)
        if prev is not None:
            prev.next = node
        node.prev = prev
        prev = node

    for i, head in enumerate(heads[1:]):
        i = i + 1
        cnt = 0
        cur = heads[i-1]
        while cnt < headsCnt[i] - 1:
            cur = cur.next
            cnt += 1
        cur.child = head
    return nodes[0]


def toa(head):
    arr = []
    while head is not None:
        arr.append(head.val)
        head = head.next
    return arr

arr = json.loads(input())
root = connectLinkedList(arr)

sol = Solution()
print(toa(sol.flatten(root)))

