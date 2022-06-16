#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        return []


recipes = json.loads(input())
ingredients = json.loads(input())
supplies = json.loads(input())

sol = Solution()
aprint(sol.findAllRecipes(recipes, ingredients, supplies))
