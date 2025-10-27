//540
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2; 
            } else {
                high = mid; 
            }
        }
        return nums[low];
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted array elements (all appear twice except one): ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int result = sol.singleNonDuplicate(nums);
    cout << "The single non-duplicate element is: " << result << endl;

    return 0;
}


//Time Complexity
//O(log n) — Binary search halves the search space at each step.
//
//Space Complexity
//O(1) — Constant extra space used.
//
//Asked In
//Company	    Year	Difficulty
//Amazon	    2021	Medium
//Microsoft	    2022	Medium
//Google	    2023	Medium
//Bloomberg	    2022	Medium
