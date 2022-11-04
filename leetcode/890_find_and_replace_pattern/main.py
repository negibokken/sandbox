#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        def match(word):
            m1, m2 = {}, {}
            for w, p in zip(word, pattern):
                if w not in m1:
                    m1[w] = p
                if p not in m2:
                    m2[p] = w
                if (m1[w], m2[p]) != (p, w):
                    return False
            return True

        return [word for word in words if match(word)]


arr = json.loads(input())
pattern = json.loads(input())

sol = Solution()
aprint(sol.findAndReplacePattern(arr, pattern))
