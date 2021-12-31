#!/usr/bin/python3

from typing import List
import json
from collections import OrderedDict


class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        od = OrderedDict()
        for n in nums:
            if not n in od:
                od[n] = 0
            od[n] += 1
        l = []
        for k, v in od.items():
            l.append([v, k])
        l = sorted(l, key=lambda x: (x[0], -(x[1])))
        ans = []
        for ll in l:
            for i in range(ll[0]):
                ans.append(ll[1])
        return ans


nums = json.loads(input())

sol = Solution()
print("{}".format(sol.frequencySort(nums)).replace(" ", ""))
