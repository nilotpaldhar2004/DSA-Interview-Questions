//leetcode - 84 Largest Rectangle in Histogram
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    stack<int> s;

   
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    while (!s.empty()) s.pop();

    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int currArea = heights[i] * width;
        ans = max(ans, currArea);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of bars in histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter heights of histogram bars: ";
    for (int i = 0; i < n; i++) cin >> heights[i];

    int result = largestRectangleArea(heights);
    cout << "Largest Rectangle Area in Histogram = " << result << endl;
    return 0;
}


//Asked In:
//This problem is a must-know for advanced stack-based DSA interviews.
//It has been repeatedly asked in:
//
//Company 	  Years
//Amazon	    2021, 2022, 2023
//Google	    2020, 2021
//Microsoft   2022
//Adobe	    2021
//Flipkart	2022
//Bloomberg	2023
//
//Time and Space Complexity
//Metric	         Complexity	Explanation
//Time Complexity 	O(n)	Each bar is pushed and popped from the stack once
//Space Complexity	O(n)	Extra space used for left, right, and stack

