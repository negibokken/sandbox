class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        sl = list(s)
        l, r = 0, len(s) - 1
        while l < r:
            if not sl[l].isalpha():
                l += 1
            elif not sl[r].isalpha():
                r -= 1
            else:
                sl[l], sl[r] = sl[r], sl[l]
                l, r = l+1, r-1
        return "".join(sl)

s = input()
sol = Solution()
print(sol.reverseOnlyLetters(s))
