#!/usr/bin/python3

from typing import List
import json


class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        st = set()
        for edge in edges:
            if edge[0] in st:
                return edge[0]
            elif edge[1] in st:
                return edge[1]
            st.add(edge[0]), st.add(edge[1])


arr = json.loads(input())
sol = Solution()
print(sol.findCenter(arr))
