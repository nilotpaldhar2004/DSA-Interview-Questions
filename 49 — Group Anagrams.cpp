//LeetCode 49 — Group Anagrams
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto it : strs) {
            string temp = it;
            sort(it.begin(), it.end());  
            mp[it].push_back(temp);    
        }
        vector<vector<string>> ans;
        for (auto& x : mp)
            ans.push_back(x.second);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings (space separated): ";
    for (int i = 0; i < n; i++) cin >> strs[i];

    Solution sol;
    vector<vector<string>> result = sol.groupAnagrams(strs);

    cout << "\nGrouped Anagrams:\n";
    for (auto& group : result) {
        for (auto& word : group) cout << word << " ";
        cout << endl;
    }

    return 0;
}


//Time and Space Complexity
//Time Complexity:
//Sorting each string: O(K log K), where K = average word length
//For all strings: O(N × K log K)
//Space Complexity: O(N × K)
//(to store all grouped words in the unordered map)

//Companies Where Asked
//LeetCode 49 “Group Anagrams” has been frequently asked in:
//Google (2023)
//Amazon (2023)
//Microsoft (2022)
//Facebook / Meta (2022)
//Uber (2021)
//This problem helps test hash maps, string manipulation, and sorting-based grouping skills
