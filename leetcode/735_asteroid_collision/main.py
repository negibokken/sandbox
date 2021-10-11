#!/usr/bin/python3

from typing import List
import json


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        ans = []
        for new in asteroids:
            while ans and new < 0 < ans[-1]:
                if ans[-1] < -new:
                    ans.pop()
                    continue
                elif ans[-1] == -new:
                    ans.pop()
                break
            else:
                ans.append(new)
        return ans


arr = json.loads(input())

sol = Solution()
print(sol.asteroidCollision(arr))
