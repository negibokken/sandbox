#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals = sorted(intervals)
        current_start = -1
        current_end = -1
        for [start, end] in intervals:
            if current_end > start:
                return False
            current_end = end
        return True


arr = json.loads(input())

sol = Solution()
print(sol.canAttendMeetings(arr))
