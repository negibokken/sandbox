#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
from operator import itemgetter


class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        tiles = sorted(tiles, key=lambda tile: tile[0])
        print(tiles)
        temp = []
        i, j, ans, current, N = 0, 0, 0, 0, len(tiles)
        prev = None
        while i < N:
            tile = tiles[i]
            if temp and tile[1] - temp[0][0] + 1 >= carpetLen:
                t = temp.pop(0)
                prev = t
                l, r = t
                current -= r-l+1
                continue
            temp.append(tile)
            l, r = tile
            current += r - l + 1
            ans = max(ans, current)
            if prev and carpetLen - (temp[-1][1] - temp[0][0]) > 0:
                left = carpetLen - (temp[-1][1] - temp[0][0])
                space = temp[0][0] - left
                mark = "!" if space <= prev[1] else ""
                print(mark, left, ", ", space, ", ",
                      prev[1], "==>", prev[1] - space + 1)
                if space <= prev[1]:
                    ans = max(ans, ans+prev[1] - space + 1)

            i += 1
        return ans


arr = json.loads(input())
carpetLen = int(input())

sol = Solution()
print(sol.maximumWhiteTiles(arr, carpetLen))
