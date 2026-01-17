#LeetCode 2073 — Time Needed to Buy Tickets

class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        time = 0
        target = tickets[k]

        for i in range(len(tickets)):
            if i <= k:
                time += min(tickets[i], target)
            else:
                time += min(tickets[i], target - 1)

        return time


if __name__ == "__main__":
    tickets = list(map(int, input("Enter tickets array: ").split()))
    k = int(input("Enter index k: "))

    sol = Solution()
    print("Time required:", sol.timeRequiredToBuy(tickets, k))

# Company-wise DSA Question (Reported)
# This problem or its variations have appeared in interviews at:

# Company	Year(s)
# Amazon	2021, 2022
# Microsoft	2022
# Google	2023
# Flipkart	2021
# Goldman Sachs	2022
# Infosys / TCS / Accenture	2022–2024

# Time Complexity
# O(n) — Single loop through the array

# Space Complexity
# O(1) — Constant extra space