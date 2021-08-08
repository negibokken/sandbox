#!/usr/bin/python3

from typing import List
import json
import sys


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [sys.maxsize] * (len(cost))
        for i in range(len(dp)):
            if i < 2:
                dp[i] = cost[i]
            else:
                dp[i] = cost[i] + min(dp[i-1], dp[i-2])
        return min(dp[len(cost)-1], dp[len(cost)-2])


cost = json.loads(input())
sol = Solution()
print(sol.minCostClimbingStairs(cost))
