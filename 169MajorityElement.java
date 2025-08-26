
import java.util.*;

public class MajorityElement {
    public static int majorityElement(int[] nums) {
        int freq = 0;
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            if (freq == 0) {
                ans = nums[i];
            }
            if (nums[i] == ans) {
                freq++;
            } else {
                freq--;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] nums = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int result = majorityElement(nums);
        System.out.println("Majority Element: " + result);

        sc.close();
    }
}
// Companies Asking This Question

// This problem is very common in coding interviews, especially FAANG and top product companies.

// ✅ Amazon

// ✅ Google

// ✅ Microsoft

// ✅ Facebook (Meta)

// ✅ Apple

// ✅ Adobe

// ✅ Bloomberg
