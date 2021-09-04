#!/usr/bin/python3

from typing import List
import json


class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        



arr = json.loads(input())

sol = Solution()
