from collections import deque
#496 leetcode
class Solution:
    def nextGreaterElement(self, nums1, nums2):
        stack = []
        next_greater = {}
        for num in nums2:
            while stack and stack[-1] < num:
                next_greater[stack.pop()] = num
            stack.append(num)

        return [next_greater.get(num, -1) for num in nums1]

# ---------- User Input Handling ----------
if __name__ == "__main__":
    n1 = int(input("Enter size of nums1: "))
    nums1 = list(map(int, input("Enter nums1 elements: ").split()))

    n2 = int(input("Enter size of nums2: "))
    nums2 = list(map(int, input("Enter nums2 elements: ").split()))

    sol = Solution()
    result = sol.nextGreaterElement(nums1, nums2)

    print("Next Greater Elements:", result)


# Company	   Year(s) Reported
# Amazon	      2019, 2021
# Google	       2020
# Microsoft	      2018, 2022
# Facebook (Meta)	2020
# Adobe	            2021
# Uber	            2019

# Time Complexity
# O(n + m)
# n = len(nums2)
# m = len(nums1)
# Each element is pushed & popped once
#
# Space Complexity
# O(n)
# Stack + HashMap