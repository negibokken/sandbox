#!/usr/bin/python3

from typing import List
import json


class Solution:
    def findOrder(self, numCourses: int, prerequities: List[List[int]]) -> List[int]:
        verticies = [[] for i in range(numCourses)]
        verticiesn = [0] * numCourses
        st = set([i for i in range(numCourses)])
        for p in prerequities:
            verticies[p[1]].append(p[0])
            verticiesn[p[0]] += 1

        cur = -1
        ans = []
        for v, n in enumerate(verticiesn):
            if n == 0:
                cur = v
                break
        if cur == -1:
            return ans

        while st:
            ans.append(cur)
            st.remove(cur)
            if not st:
                return ans
            for v in verticies[cur]:
                verticiesn[v] -= 1
            update = False
            for v in st:
                if verticiesn[v] == 0:
                    cur = v
                    update = True
                    break
            if not update:
                return []

        return ans


numCourses = int(input())
prerequiites = json.loads(input())

sol = Solution()
print("{}".format(sol.findOrder(numCourses, prerequiites)).replace(" ", ""))
