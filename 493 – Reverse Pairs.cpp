//493
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;
        
        int mid = (low + high) / 2;
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);
        
        // Count reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++) nums[i] = temp[i - low];
        
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    int result = sol.reversePairs(nums);
    cout << "Number of Reverse Pairs: " << result << endl;
    
    return 0;
}


//Time Complexity
//O(n log n) — Similar to merge sort
//Counting reverse pairs: O(n)
//Merging halves: O(n)
//Recursion depth: O(log n)
//
//Space Complexity
//O(n) — for temporary array used during merge
//
//Asked In
//Company	    Year	Difficulty
//Google	    2022	Hard
//Amazon	    2021	Hard
//Microsoft	2023	Hard
//Facebook	2020	Hard
//Bloomberg	2021	Hard
