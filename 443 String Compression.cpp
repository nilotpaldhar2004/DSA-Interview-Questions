//LeetCode 443 String Compression
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }
            chars[idx++] = ch;
            if (count > 1) {
                string str = to_string(count);
                for (char dig : str) {
                    chars[idx++] = dig;
                }
            }
            i--;  
        }
        chars.resize(idx);
        return idx;
    }
};

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    cout << "Enter the characters (space separated): ";
    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    Solution sol;
    int newLength = sol.compress(chars);
    cout << "Compressed length = " << newLength << endl;
    cout << "Compressed array: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}

//Time & Space Complexity
//Time Complexity: O(n) — We traverse the array once and process each group of consecutive characters in constant (amortized) time. 
//Space Complexity: O(1) extra space — The compression is done in place (aside from the input array), and we only use a handful of variables.
//
//Companies & Year Asked
//Amazon — 2023
//Google — 2022
//Redfin — 2022
