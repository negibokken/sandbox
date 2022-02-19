#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def simplifyPath(self, path: str) -> str:
        path = path.rstrip('/')
        arr = path.split("/")
        simplified_arr = []
        for ele in arr:
            if ele == "..":
                if len(simplified_arr) > 1:
                    simplified_arr.pop()
                continue
            elif ele == "" and len(simplified_arr) > 0:
                continue
            elif ele == ".":
                continue
            simplified_arr.append(ele)
        if len(simplified_arr) == 1:
            simplified_arr.append("")
        return "/".join(simplified_arr)


str = json.loads(input())

sol = Solution()
print(sol.simplifyPath(str))
