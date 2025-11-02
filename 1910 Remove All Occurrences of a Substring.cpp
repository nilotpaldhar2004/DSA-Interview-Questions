//LeetCode Problem #1910
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s, part;
    cout << "Enter the main string: ";
    getline(cin, s);
    cout << "Enter the substring to remove: ";
    getline(cin, part);

    string result = sol.removeOccurrences(s, part);
    cout << "Final string after removing occurrences: " << result << endl;

    return 0;
}

//Time & Space Complexity
//Time Complexity: O(N × M)
//N = length of s, M = length of part
//Each erase and find may take O(N), and it repeats until all parts are removed.
//
//Space Complexity: O(1)
//In-place modification of string.

//Asked In (Companies + Year)
//Company    	Year
//Amazon	    2023
//Microsoft 	2022
//TCS Digital	2023
//Infosys   	2024
//Adobe	        2022
