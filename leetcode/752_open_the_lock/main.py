#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys
import collections


class Solution(object):
    def openLock(self, deadends, target):
        dead = set(deadends)
        queue = collections.deque([('0000', 0)])
        seen = {'0000'}
        while queue:
            node, depth = queue.popleft()
            if node == target:
                return depth
            if node in dead:
                continue
            for i in range(4):
                x = int(node[i])
                for d in (-1, 1):
                    y = (x + d) % 10
                    nei = node[:i] + str(y) + node[i+1:]
                    if nei not in seen:
                        seen.add(nei)
                        queue.append((nei, depth+1))
        return -1


arr = json.loads(input())
target = json.loads(input())

sol = Solution()
print(sol.openLock(arr, target))
