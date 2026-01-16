#387 leetcode
from collections import Counter

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = Counter(s)
        for i, ch in enumerate(s):
            if count[ch] == 1:
                return i
        return -1

if __name__ == "__main__":
    s = input("Enter the string: ").strip()
    sol = Solution()
    print("Index of first unique character:", sol.firstUniqChar(s))

# Company-wise DSA Question (Reported)
# Company	           Year(s) Reported
# Amazon	          2018, 2020, 2022
# Microsoft	          2019, 2021
# Google	             2018
# Facebook (Meta)	     2020
# Apple	                 2019
# Adobe	                 2018
# Infosys / TCS / Wipro	2019–2023

# Time Complexity
# O(n)
# Counting characters: O(n)
# Traversing string: O(n)
#
# Space Complexity
# O(1)