#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& arr) {
    int slow = arr[0], fast = arr[0];
    
    
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements (with at least one duplicate):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findDuplicate(arr);
    cout << "Duplicate number is: " << result << endl;

    return 0;
}

//Time & Space Complexity:
//Metric	Complexity	Explanation
//Time Complexity	    O(n)	Both the slow and fast pointers traverse the array once
//Space Complexity	O(1)	Uses constant extra space (no additional data structures)


//Companies & Years Asked
//This problem is very popular and has been asked in:

//Amazon – 2021, 2022
//Google – 2021
//Facebook (Meta) – 2020, 2022
//Microsoft – 2021
//Apple – 2021
//Adobe – 2022
//Netflix – 2023
//It’s a top DSA problem from the Floyd’s Cycle Detection / Linked List category and part of LeetCode Top 100 / Blind 75.
