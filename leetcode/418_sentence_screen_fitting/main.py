#!/usr/bin/python3

from typing import List
import json


class Solution:
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        nums = [len(d) for d in sentence]
        n = len(sentence)
        ans, row, col, j = 0, 0, 0, 0
        while row < rows:
            col = 0
            while col + nums[j % n] <= cols:
                col += nums[j % n]
                j += 1
                if (j % n) == 0:
                    break
                else:
                    col += 1
            row += 1
            if (j % n) == 0:
                break
        # 一周するために必要な space 数
        spaces = ((row-1) * cols) + col
        total = rows * cols
        ans = (total//(spaces+1)) if spaces != 0 else 0
        print(total, spaces)
        # print("total", rows*cols)
        # print("spaces", spaces)
        return ans


arr = json.loads(input())
rows = int(input())
cols = int(input())

sol = Solution()
print(sol.wordsTyping(arr, rows, cols))
