//Leetcode - 33
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int st = 0, end = nums.size() - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == tar)
                return mid;

            // Left half is sorted
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= tar && tar < nums[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            } 
            // Right half is sorted
            else {
                if (nums[mid] < tar && tar <= nums[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements (rotated sorted): ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target element: ";
    cin >> target;

    int index = sol.search(nums, target);
    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found in the array." << endl;

    return 0;
}

//Time Complexity
//O(log n) — Binary search on rotated sorted array.
//
//Space Complexity
//O(1) — Constant extra space.
//
//Asked In
//Company	    Year	Difficulty
//Amazon	    2022	Medium
//Microsoft	2021	Medium
//Google	    2020	Medium
//Facebook	2023	Medium
//Adobe	    2022	Medium
