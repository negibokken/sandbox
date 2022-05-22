#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        lengths = {}
        result = 1
        for i in arr:
            if i-difference not in lengths:
                lengths[i-difference] = 0
            # print("i: {}, i-diff: {}".format(i, i-difference))
            lengths[i] = 1 + lengths[i-difference]
            result = max(result, lengths[i])
        return result


arr = json.loads(input())
diff = int(input())

sol = Solution()
print(sol.longestSubsequence(arr, diff))
