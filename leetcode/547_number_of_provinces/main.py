#!/usr/bin/python3

from typing import List
import json


class Solution:
    def bfs(self, v, isConnected, visited):
        if visited[v]:
            return
        visited[v] = True
        n = len(isConnected)
        for i in range(n):
            if isConnected[v][i] and not visited[i]:
                self.bfs(i, isConnected, visited)

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [False]*n
        ans = 0
        for i in range(n):
            if not visited[i]:
                self.bfs(i, isConnected, visited)
                ans += 1
        return ans


arr = json.loads(input())

sol = Solution()
print(sol.findCircleNum(arr))
