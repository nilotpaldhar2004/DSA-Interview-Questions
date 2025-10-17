#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);

    lmax[0] = height[0];
    for (int i = 1; i < n; i++) {
        lmax[i] = max(lmax[i - 1], height[i]);
    }

    rmax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rmax[i] = max(rmax[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += min(lmax[i], rmax[i]) - height[i];
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter height of bars: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int water = trap(height);
    cout << "Total trapped rainwater: " << water << endl;

    return 0;
}

//Asked In:
//This problem has been asked by top product companies, such as:
//Amazon (2021, 2022, 2023)
//Google (2020, 2022)
//Microsoft (2021)
//Facebook / Meta (2021)
//Apple (2022)
//Adobe (2021)
//Flipkart (2023)

//Time & Space Complexity
//Metric	Complexity	Explanation
//Time Complexity	    O(n)	Single traversal for leftMax, rightMax, and total water
//Space Complexity	O(n)	Two auxiliary arrays (lmax[], rmax[])
