#/usr/bin/python3

import sys
from typing import List
from math import floor

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        if n1 < n2:
            n1, n2, nums1, nums2 = n2, n1, nums2, nums1
        lo, hi = 0, n2*2
        while lo <= hi:
            mid2 = int((lo+hi)/2)
            mid1 = n1 + n2 - mid2

            l1 = -sys.maxsize if mid1 == 0 else nums1[int((mid1-1)/2)]
            l2 = -sys.maxsize if mid2 == 0 else nums2[int((mid2-1)/2)]
            r1 = sys.maxsize if (mid1 == n1 * 2) else nums1[int(mid1/2)]
            r2 = sys.maxsize if (mid2 == n2 * 2) else nums2[int(mid2/2)]

            if l1 > r2:
                lo = mid2 + 1
            elif l2 > r1:
                hi = mid2 - 1
            else:
                return (max(l1,l2) + min(r1,r2))/2
        return -1
    # A1.
    #    arr = []
    #    i, j = 0, 0
    #    while True:
    #        if i >= len(nums1) and j >= len(nums2):
    #            break
    #        elif i >= len(nums1):
    #            arr.append(nums2[j])
    #            j += 1
    #        elif j >= len(nums2):
    #            arr.append(nums1[i])
    #            i += 1
    #        elif nums1[i] <= nums2[j]:
    #            arr.append(nums1[i])
    #            i += 1
    #        else:
    #            arr.append(nums2[j])
    #            j += 1
    #    n = len(arr)
    #    m = floor(n/2)
    #    if  n == 0:
    #        return 0.0
    #    elif (n % 2) == 0:
    #        return (arr[m-1]+arr[m])/2
    #    else:
    #        return arr[m]

sol = Solution()
nums1 = []
try:
    nums1 = list(map(int, input().split(" ")))
except:
    nums1 = []

nums2 = []
try:
    nums2 = list(map(int, input().split(" ")))
except:
    nums2 = []

print("{:.5f}".format(sol.findMedianSortedArrays(nums1,nums2)))
