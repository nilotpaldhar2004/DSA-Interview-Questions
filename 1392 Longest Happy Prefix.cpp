//LeetCode 1392:- Longest Happy Prefix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
    int n = s.size();
    int len = 0;  
    vector<int> lps(n, 0);

    for (int i = 1; i < n; i++) {
        while (len > 0 && s[i] != s[len]) {
            len = lps[len - 1];
        }
        if (s[i] == s[len]) len++;
        lps[i] = len;
    }

    return s.substr(0, lps[n - 1]);
}

};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution sol;
    string result = sol.longestPrefix(s);

    cout << "\nLongest Happy Prefix: " << (result.empty() ? "None" : result) << endl;
    return 0;
}

//Complexity Analysis
//Type   	Explanation	                        Complexity
//Time	    Each character is processed once	  O(n)
//Space  	LPS array of size n					  O(n)


//Companies Where Asked
//This problem (KMP / prefix-suffix) pattern appeared in:
//Amazon (2023)
//Google (2022)
//Adobe (2021)
//Microsoft (2020)
//Often asked when testing string pattern matching and KMP understanding.
