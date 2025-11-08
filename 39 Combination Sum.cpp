//LeetCode Problem 39 Combination Sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>> s;

    void getAllcombination(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& combin) {
        if (idx == arr.size() || tar < 0) return;

        if (tar == 0) {
            if (s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }
      
        combin.push_back(arr[idx]);
        getAllcombination(arr, idx, tar - arr[idx], ans, combin);

        combin.pop_back();
        getAllcombination(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllcombination(arr, 0, target, ans, combin);
        return ans;
    }
};

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    Solution sol;
    vector<vector<int>> result = sol.combinationSum(arr, target);

    cout << "\nCombinations that sum to " << target << ":\n";
    for (auto& vec : result) {
        cout << "[ ";
        for (auto val : vec) cout << val << " ";
        cout << "]\n";
    }

    return 0;
}

//Complexity Analysis
//Type	Complexity	 Explanation
//Time	O(2^n * n)	 Each number can be included or excluded; copying combinations costs O(n)
//Space	O(n)	     Recursion stack depth + temporary combination storage
//
//Companies Where Asked
//This is a top interview problem and has appeared in:
//Amazon (2023, 2022)
//Google (2021)
//Bloomberg (2020)
//Microsoft (2022)
//Adobe (2023)
