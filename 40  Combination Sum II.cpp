//LeetCode 40 Combination Sum II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>& arr, int target, int start, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < arr.size(); i++) {
            if (i > start && arr[i] == arr[i - 1]) continue;  
            if (arr[i] > target) break;                       
            curr.push_back(arr[i]);
            helper(arr, target - arr[i], i + 1, curr, ans);   
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(arr.begin(), arr.end());   
        helper(arr, target, 0, curr, ans);
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

    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<vector<int>> result = obj.combinationSum2(arr, target);

    cout << "\nUnique combinations that sum to target:\n";
    for (auto& comb : result) {
        cout << "[ ";
        for (auto& num : comb) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}

//Time Complexity:
//O(2n) — Each element can either be included or excluded.
//Sorting takes O(n log n).
//
//Space Complexity:
//O(k) — For recursion stack and current combination list (k = combination length).
//
//Asked In:
//Amazon (2023)
//Microsoft (2022)
//Google (2021)
//Adobe (2021)
