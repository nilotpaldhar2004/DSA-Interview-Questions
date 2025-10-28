//4
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        int total_left = (m + n + 1) / 2;

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = total_left - i;

            int max_left1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int min_right1 = (i == m ? INT_MAX : nums1[i]);
            int max_left2 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int min_right2 = (j == n ? INT_MAX : nums2[j]);

            if (max_left1 <= min_right2 && max_left2 <= min_right1) {
                if ((m + n) % 2 == 1) 
                    return max(max_left1, max_left2);
                else 
                    return ( (double)max(max_left1, max_left2) + (double)min(min_right1, min_right2) ) / 2.0;
            } 
            else if (max_left1 > min_right2) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    Solution sol;
    int m, n;
    cout << "Enter size of first array: ";
    cin >> m;
    vector<int> nums1(m);
    cout << "Enter " << m << " sorted elements for first array:\n";
    for (int i = 0; i < m; i++) cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> n;
    vector<int> nums2(n);
    cout << "Enter " << n << " sorted elements for second array:\n";
    for (int i = 0; i < n; i++) cin >> nums2[i];

    double result = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median of the two sorted arrays: " << result << "\n";

    return 0;
}

//Time & Space Complexity
//Time Complexity: O(log (min(m, n))) — we binary search on the smaller array. 
//Space Complexity: O(1) — a constant number of extra variables.
//
//Companies & Year Asked
//Amazon, Google, Meta, Apple — (2022)
//Goldman Sachs — (2022)
