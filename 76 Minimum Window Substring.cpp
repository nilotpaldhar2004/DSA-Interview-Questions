//76 Minimum Window Substring
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(128, 0);  
        vector<int> window(128, 0);

        int required = 0;
        for (char c : t) {
            if (need[c] == 0) required++; 
            need[c]++;
        }

        int formed = 0, left = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (need[c] > 0 && window[c] == need[c])
                formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if (need[leftChar] > 0 && window[leftChar] < need[leftChar])
                    formed--;

                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    Solution sol;
    string result = sol.minWindow(s, t);
    cout << "\nMinimum Window Substring: " << (result.empty() ? "None" : result) << endl;

    return 0;
}

//Time and Space Complexity
//Complexity Type   	Description															   Big-O
//Time	            Each character is visited at most twice (by left and right pointers)	  O(N + M)
//Space	            Two hash maps of constant size (ASCII 128)						       O(1)


//Companies Where Asked
//LeetCode 76 — Minimum Window Substring
//was frequently asked in interviews by:
//Google (2023)
//Amazon (2022)
//Facebook / Meta (2022)
//Microsoft (2021)
//Adobe (2021)
//Bloomberg (2023)
