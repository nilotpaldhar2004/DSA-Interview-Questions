//3
//Java solution for LeetCode 3

import java.util.*;

public class LongestSubstringWithoutRepeating {

    public static int lengthOfLongestSubstring(String s) {
        int[] lastIndex = new int[256]; 
        Arrays.fill(lastIndex, -1);

        int n = s.length();
        int res = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            char c = s.charAt(right);

            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }

            lastIndex[c] = right;
            res = Math.max(res, right - left + 1);
        }

        return res;
    }

    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String s = sc.nextLine();

        int result = lengthOfLongestSubstring(s);
        System.out.println("Length of Longest Substring Without Repeating Characters: " + result);

        sc.close();
    }
}
