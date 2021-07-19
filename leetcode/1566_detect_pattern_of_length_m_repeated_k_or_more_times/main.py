#/usr/bin/python3

from typing import List

class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        for i in range(len(arr)):
            cnt = 1
            cur = arr[i:i+m]
            for j in range(i+m, len(arr), m):
                # print("cnt:{} {} {}".format(cnt, cur, arr[j:j+m]))
                if cur == arr[j:j+m]:
                    cnt += 1
                else:
                    break
            if cnt >= k:
                return True
        return False

n = int(input())
arr = [int(x) for x in input().split(' ')]
m, k = [int(x) for x in input().split(' ')]

s = Solution()
# print("")
print("true" if s.containsPattern(arr,m,k) == True else "false")
