#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class SmallestInfiniteSet:

    def __init__(self):
        self.cur = 1
        self.set = set()

    def popSmallest(self) -> int:
        if self.set:
            for s in self.set:
                self.set.remove(s)
                return s
        else:
            self.cur += 1
            return self.cur - 1

    def addBack(self, num: int) -> None:
        if self.cur > num:
            self.set.add(num)

        # Your SmallestInfiniteSet object will be instantiated and called as such:
        # obj = SmallestInfiniteSet()
        # param_1 = obj.popSmallest()
        # obj.addBack(num)


arr1 = json.loads(input())
arr2 = json.loads(input())

st = None
ans = []
for i in range(len(arr1)):
    order = arr1[i]
    if order == "SmallestInfiniteSet":
        st = SmallestInfiniteSet()
        ans.append(None)
    elif order == "addBack":
        st.addBack(arr2[i][0])
        ans.append(None)
    elif order == "popSmallest":
        ele = st.popSmallest()
        ans.append(ele)

aprint(ans)
