#!/usr/bin/python3

from typing import List
import json


class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp = {}
        for i in range(len(nums2)):
            mp[nums2[i]] = i
        ans = []
        for num in nums1:
            ans.append(mp[num])
        return ans


nums1 = json.loads(input())
nums2 = json.loads(input())
sol = Solution()
print(sol.anagramMappings(nums1, nums2))
