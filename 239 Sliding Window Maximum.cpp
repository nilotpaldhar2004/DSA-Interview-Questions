#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;

 
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

 
    for (int i = k; i < nums.size(); i++) {
        res.push_back(nums[dq.front()]);

   
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

    
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    
    res.push_back(nums[dq.front()]);

    return res;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter window size (k): ";
    cin >> k;

    vector<int> result = maxSlidingWindow(nums, k);
    cout << "Maximum elements in each window: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}

//Asked In:
//This question has been repeatedly asked by top tech companies, including:
//Amazon – 2021, 2022
//Google – 2020, 2023
//Microsoft – 2022
//Facebook (Meta) – 2021
//Adobe – 2021
//Netflix – 2023
//Uber – 2022
//
//
//Time and Space Complexity
//Metric	         Complexity	Explanation
//Time Complexity  	O(n)	Each element is added and removed from the deque at most once
//Space Complexity	O(k)	Deque stores up to k indices at a time
