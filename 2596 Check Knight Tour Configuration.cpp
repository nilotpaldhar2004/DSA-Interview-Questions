//leetcode 2596
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

       
        if (grid[0][0] != 0) return false;

        vector<pair<int,int>> pos(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        for (int k = 0; k < n * n - 1; k++) {
            int dx = abs(pos[k].first - pos[k + 1].first);
            int dy = abs(pos[k].second - pos[k + 1].second);

            if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    int n;
    cout << "Enter board size n: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the grid:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    if (obj.checkValidGrid(grid))
        cout << "Valid Knight Tour Configuration\n";
    else
        cout << "Invalid Knight Tour Configuration\n";

    return 0;
}

//Asked In (Interview / DSA)
//
//Amazon (2022–2023)
//Microsoft (2021)
//Google (2020)
//Flipkart


//Complexity
//
//Time: O(n²)
//Space: O(n²)

