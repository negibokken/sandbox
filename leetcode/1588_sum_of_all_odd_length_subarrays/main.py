#!/usr/bin/python3

from typing import List
import json


class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        ans = 0
        i = 0
        while i < len(arr):
            temp = 0
            ta = []
            j = i
            while j < len(arr):
                temp += arr[j]
                ta.append(arr[j])
                if (j-i + 1) % 2:
                    ans += temp
                j += 1
            i += 1

        return ans


arr = json.loads(input())

sol = Solution()
print(sol.sumOddLengthSubarrays(arr))
