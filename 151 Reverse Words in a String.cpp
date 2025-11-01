//151

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            string word = "";

            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        return ans.substr(1);
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    string result = sol.reverseWords(s);
    cout << "Reversed Words: " << result << endl;

    return 0;
}

//Time & Space Complexity
//Time Complexity: O(N) — Each character is visited a constant number of times.
//Space Complexity: O(N) — For storing intermediate words and the final result.
//
//
//Asked In (Companies + Year)
//Company	        Year
//Amazon	        2023
//Google	        2022
//Microsoft	        2022
//Adobe   	        2023
//Facebook (Meta)	2021
