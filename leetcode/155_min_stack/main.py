#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys


class StackValue:
    def __init__(self, _val, _min):
        self.value = _val
        self.min = _min


class MinStack:

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        mi = sys.maxsize
        if len(self.stack) > 0:
            mi = self.stack[-1].min
        self.stack.append(StackValue(val, min(mi, val)))

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        if len(self.stack) > 0:
            return self.stack[-1].value
        return sys.maxsize

    def getMin(self) -> int:
        if len(self.stack) > 0:
            return self.stack[-1].min
        return sys.maxsize


arr1 = json.loads(input())
arr2 = json.loads(input())

ans = []
stack = None
for i in range(len(arr1)):
    if arr1[i] == "MinStack":
        stack = MinStack()
        ans.append('null')
    elif arr1[i] == "push":
        stack.push(arr2[i][0])
        ans.append('null')
    elif arr1[i] == "pop":
        stack.pop()
        ans.append('null')
    elif arr1[i] == "getMin":
        mi = stack.getMin()
        ans.append(mi)
    elif arr1[i] == "top":
        ans.append(stack.top())
    else:
        print("error")


aprint(ans)
