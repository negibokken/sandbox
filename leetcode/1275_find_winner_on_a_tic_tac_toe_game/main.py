#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        board = [[''] * 3 for _ in range(3)]
        sign = 'x'
        for move in moves:
            board[move[0]][move[1]] = sign
            sign = 'o' if sign == 'x' else 'x'

        def convert(c):
            return 'A' if c == 'x' else 'B'

        for i in range(3):
            if board[i][0] == '':
                continue
            if board[i][0] == board[i][1] == board[i][2]:
                return convert(board[i][0])
        for j in range(3):
            if board[0][j] == '':
                continue
            if board[0][j] == board[1][j] == board[2][j]:
                return convert(board[0][j])
        if board[0][0] == board[1][1] == board[2][2] and board[0][0] != '':
            return convert(board[0][0])
        if board[0][2] == board[1][1] == board[2][0] and board[0][2] != '':
            return convert(board[0][2])

        if len(moves) == 9:
            return "Draw"
        return "Pending"


arr = json.loads(input())

sol = Solution()
print(sol.tictactoe(arr))
