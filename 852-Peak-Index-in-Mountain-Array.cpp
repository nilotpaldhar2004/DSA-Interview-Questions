//852
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, ed = arr.size() - 2;

        while (st <= ed) {
            int mid = st + (ed - st) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid; // Peak found
            } 
            else if (arr[mid - 1] < arr[mid]) {
                st = mid + 1; // Move right
            } 
            else {
                ed = mid - 1; // Move left
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter size of mountain array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of mountain array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int peak = sol.peakIndexInMountainArray(arr);
    if (peak != -1)
        cout << "Peak element index: " << peak << endl;
    else
        cout << "No peak found (invalid mountain array)." << endl;

    return 0;
}

//Time Complexity
//O(log n) — Binary search halves the range each time.
//Space Complexity
//O(1) — Uses constant extra space.
//
//Asked In
//Company	    Year	Difficulty
//Amazon	    2021	Medium
//Google	    2022	Medium
//Adobe	    2023	Medium
//Bloomberg	2022	Medium
