#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import collections


class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        current = self.root
        for letter in word:
            current = current.children[letter]
        current.is_word = True

    def search(self, word):
        current = self.root
        for letter in word:
            current = current.children.get(letter)
            if current is None:
                return False
        return current.is_word

    def startsWith(self, prefix):
        current = self.root
        for letter in prefix:
            current = current.children.get(letter)
            if current is None:
                return False
        return True


orders = json.loads(input())
args = json.loads(input())

ans = []
trie = None
for i, order in enumerate(orders):
    if order == "Trie":
        trie = Trie()
        ans.append(None)
    elif order == "insert":
        trie.insert(args[i])
        ans.append(None)
    elif order == "search":
        f = trie.search(args[i])
        ans.append(f)
    elif order == "startsWith":
        f = trie.startsWith(args[i])
        ans.append(f)

for i, ele in enumerate(ans):
    if ele == None:
        ans[i] = "null"
    elif ele == True:
        ans[i] = "true"
    elif ele == False:
        ans[i] = "false"
aprint(ans)
