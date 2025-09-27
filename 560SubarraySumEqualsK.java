//560
import java.util.*;

public class SubarraySumEqualsK {
    public static int subarraySum(int[] nums, int k) {
        int res = 0;
        int curr = 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1); 

        for (int num : nums) {
            curr += num;
            res += map.getOrDefault(curr - k, 0);
            map.put(curr, map.getOrDefault(curr, 0) + 1);
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] nums = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        int result = subarraySum(nums, k);
        System.out.println("Number of subarrays with sum " + k + " = " + result);

        sc.close();
    }
}

// 📊 Time & Space Complexity
// Metric	Complexity
// Time	O(n) — iterate through the array once
// Space	O(n) — HashMap stores prefix sums

// 🏢 Companies & Year Asked
// Based on multiple interview prep sources:
// Amazon (2020, 2021, 2022)
// Google (2021, 2022)
// Facebook / Meta (2020, 2021)
// Microsoft (2021, 2022)
// Apple (2022)
// Adobe (2021)