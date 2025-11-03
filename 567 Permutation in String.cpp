//567 Permutation in String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> count1(26, 0), count2(26, 0);
        int n1 = s1.size(), n2 = s2.size();

        for (int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        for (int i = n1; i < n2; i++) {
            if (count1 == count2) return true;

            count2[s2[i] - 'a']++;
            count2[s2[i - n1] - 'a']--;
        }

        return count1 == count2;
    }
};

int main() {
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    Solution obj;
    bool result = obj.checkInclusion(s1, s2);
    cout << (result ? "True" : "False") << endl;
    return 0;
}

//Time Complexity
//O(n2 × 26) ˜ O(n)
//Because for every window move, you compare 26 letters.
//
//Space Complexity
//O(1) — only constant extra space for 26-letter arrays.

//Company Tags
//Amazon
//Microsoft
//Google
//Facebook (Meta)
//Adobe

