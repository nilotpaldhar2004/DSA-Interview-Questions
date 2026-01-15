#20 Leetcode
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mp = {')': '(', '}': '{', ']': '['}

        for ch in s:
            if ch in mp:  # closing bracket
                top = stack.pop() if stack else '#'
                if mp[ch] != top:
                    return False
            else:  # opening bracket
                stack.append(ch)

        return not stack


# ---------- User Input Handling ----------
if __name__ == "__main__":
    s = input("Enter the parentheses string: ").strip()
    sol = Solution()
    print("Is Valid Parentheses?", sol.isValid(s))

# Company-wise DSA Question (Reported)

# Company	        Year(s) Reported
# Amazon	        2018, 2020, 2022
# Microsoft	        2017, 2019, 2021
# Google	             2019
# Facebook (Meta)	     2020
# Adobe         	     2018
# IBM	                 2017
# Infosys / TCS       2019–2023

# Time Complexity
# O(n)
# Space Complexity
# O(n)