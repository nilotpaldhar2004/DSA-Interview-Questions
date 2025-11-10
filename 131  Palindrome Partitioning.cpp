//LeetCode 131 – Palindrome Partitioning

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s2 == s;
    }

    void getAllpairs(string s, vector<string>& partitions, vector<vector<string>>& ans) {
        if (s.empty()) {
            ans.push_back(partitions);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);
            if (ispalin(part)) {
                partitions.push_back(part);
                getAllpairs(s.substr(i + 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllpairs(s, partitions, ans);
        return ans;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution obj;
    vector<vector<string>> result = obj.partition(s);

    cout << "\nAll possible palindrome partitions:\n";
    for (auto& part : result) {
        cout << "[ ";
        for (auto& str : part)
            cout << str << " ";
        cout << "]\n";
    }

    return 0;
}

//Time Complexity:
//O(2n * n) ? because there are 2n possible partitions and checking palindrome takes O(n).
//Space Complexity:
//O(n) for recursion stack + O(n) for temporary storage of partitions.

//Asked In:
//Amazon (2023)
//Google (2022)
//Microsoft (2021)
//Adobe (2020)
//Bloomberg (2021)
