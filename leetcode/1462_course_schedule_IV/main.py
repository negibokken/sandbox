#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys


class Solution:

    def checkIfPrerequisite(self, n: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        connected = [[False] * n for i in range(n)]

        for i, j in prerequisites:
            connected[i][j] = True

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    connected[i][j] = connected[i][j] or (
                        connected[i][k] and connected[k][j])

        return [connected[i][j] for i, j in queries]


numCourses = int(input())
prerequisites = json.loads(input())
queries = json.loads(input())

sol = Solution()
aprint(sol.checkIfPrerequisite(numCourses, prerequisites, queries))
