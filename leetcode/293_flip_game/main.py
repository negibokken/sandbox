#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        i = 0
        ans = []
        while i < len(currentState) - 1:
            if currentState[i] == '+' and currentState[i+1] == '+':
                str = currentState[:i] + "--" + currentState[i+2:]
                ans.append(str)
            i += 1
        return ans


arr = input()

sol = Solution()
print(sol.generatePossibleNextMoves(arr))
