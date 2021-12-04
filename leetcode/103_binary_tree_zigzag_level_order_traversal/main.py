#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, dbg
from collections import deque


class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        curq = deque()
        ans = []
        curq.append(root)
        depth = 0

        while True:
            nextq = deque()
            while curq:
                node = curq.popleft()
                if not node:
                    continue
                if depth % 2 == 0:
                    if node.left:
                        nextq.appendleft(node.left)
                    if node.right:
                        nextq.appendleft(node.right)
                else:
                    if node.right:
                        nextq.appendleft(node.right)
                    if node.left:
                        nextq.appendleft(node.left)
                if len(ans) <= depth:
                    ans.append([])
                ans[depth].append(node.val)
            if not nextq:
                break
            curq = nextq
            # insert list for next level
            depth += 1
            if depth >= 10:
                break

        return ans


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print("{}".format(sol.zigzagLevelOrder(root)).replace(" ", ""))
