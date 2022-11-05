#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(perm, visited):
            if len(nums) == len(visited):
                return [perm]
            perms = []
            for i in range(len(nums)):
                if i not in visited:
                    new_visited = set(visited)
                    new_visited.add(i)
                    perms.extend(dfs(perm+[nums[i]], new_visited))
            return perms
        return dfs([], set())


arr = json.loads(input())

sol = Solution()
aprint(sol.permute(arr))
