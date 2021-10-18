#!/usr/bin/python3

import sys
import json


class Solution:
    def c(self, mid, K, arr):
        part, cnt = 0, 0
        prev = 0
        for a in arr:
            part += (a-prev)
            prev = a
            if part >= mid:
                part = 0
                cnt += 1
        return cnt >= K+1

    def solve(self, N, L, K, arr):
        left, right = -1, L + 1
        while right - left > 1:
            mid = int((left+right)/2)
            if self.c(mid, K, arr):
                left = mid
            else:
                right = mid
        return right


[N, L] = list(map(int, input().split(" ")))
K = int(input())
arr = list(map(int, input().split(" ")))
sol = Solution()
print(sol.solve(N, L, K, arr))
