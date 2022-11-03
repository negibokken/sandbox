#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def __init__(self):
        self.paths = []

    def dfs(self, graph: List[List[int]], path: List[int], v: int):
        if v == len(graph) - 1:
            self.paths.append(path)
            return
        for u in graph[v]:
            self.dfs(graph, path[:]+[u], u)

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.dfs(graph, [0], 0)
        return self.paths


arr = json.loads(input())

sol = Solution()
aprint(sol.allPathsSourceTarget(arr))
