#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
from operator import itemgetter


class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        tiles = sorted(tiles, key=lambda tile: tile[0])
        temp = []
        i, j, ans, current, N = 0, 0, 0, 0, len(tiles)
        while i < N:
            tile = tiles[i]
            if temp and tile[1] - temp[0][0] + 1 >= carpetLen:
                l, r = temp.pop(0)
                current -= r-l+1
                continue
            temp.append(tile)
            l, r = tile
            current += r - l + 1
            ans = max(ans, current)
            i += 1
        return ans


arr = json.loads(input())
carpetLen = int(input())

sol = Solution()
print(sol.maximumWhiteTiles(arr, carpetLen))
