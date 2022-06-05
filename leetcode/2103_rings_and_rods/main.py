#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def countPoints(self, rings: str) -> int:
        rods = [0] * 10
        i = 0
        while i < len(rings):
            bit = 0
            if rings[i] == 'R':
                bit = 0b001
            elif rings[i] == 'G':
                bit = 0b010
            elif rings[i] == 'B':
                bit = 0b100
            rods[int(rings[i+1])] |= bit
            i += 2
        ans = 0
        for rod in rods:
            if rod == 0b111:
                ans += 1
        return ans


rings = input()

sol = Solution()
print(sol.countPoints(rings))
