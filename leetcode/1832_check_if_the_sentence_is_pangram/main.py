#!/usr/bin/python3

class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        st = set()
        for c in sentence:
            st.add(c)
        for i in range(26):
            if (chr(ord('a') + i)) not in st:
                return False
        return True


str = input()

sol = Solution()
print("true" if sol.checkIfPangram(str) else "false")
