#!/usr/bin/python3

from typing import List
import json
import collections


class Solution:
    def minOperations(self, logs: List[str]) -> int:
        q = collections.deque()
        for log in logs:
            if log == "./":
                continue
            elif log == "../":
                if len(q) != 0:
                    q.pop()
            else:
                q.append(log)
        return len(q)


logs = json.loads(input())
sol = Solution()
print(sol.minOperations(logs))
