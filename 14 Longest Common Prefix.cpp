#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isalpanum(char ch) {
        if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;
        while (st < end) {
            if (!isalpanum(s[st])) {
                st++;
                continue;
            }
            if (!isalpanum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    bool result = sol.isPalindrome(s);
    if (result)
        cout << "The given string IS a palindrome." << endl;
    else
        cout << "The given string is NOT a palindrome." << endl;

    return 0;
}

//Time & Space Complexity
//Time Complexity: O(n) — we check each character once.
//Space Complexity: O(1) — constant extra space.
//
//Asked In (Companies + Year)
//This question is commonly asked in interviews focusing on string manipulation and two-pointer techniques.
//Based on multiple interview archives:
//Company	        Year
//Amazon  	       2023
//Microsoft   	   2022
//Google	       2021
//Bloomberg   	   2023
//Adobe	           2022
//Facebook (Meta)  2020
