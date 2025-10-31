//242
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int count[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    bool result = sol.isAnagram(s, t);
    if (result)
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are NOT anagrams." << endl;

    return 0;
}

//Time & Space Complexity
//Time Complexity: O(N) — Traverse both strings once.
//Space Complexity: O(1) — Uses a fixed array of 26 elements.
//
//Asked In (Companies + Year)
//Company	      Year
//Amazon	      2023
//Microsoft	      2022
//Google	      2021
//Adobe	          2023
//Meta            2023
//Walmart	      2022
