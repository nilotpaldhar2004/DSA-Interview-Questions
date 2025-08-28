//136
import java.util.Arrays;
import java.util.Scanner;

public class SingleNumber {
    public static int singleNumber(int[] nums) {
        int ans = 0;
        for (int val : nums) {
            ans ^= val;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int result = singleNumber(nums);
        System.out.println("The number that appears only once is: " + result);
        sc.close();
    }
}

// This is a popular bit manipulation / XOR problem known to show up in real coding interviews. It’s favored for its:

// O(n) time complexity

// O(1) space complexity

// According to multiple prep sources, this question is often used in interviews at Amazon
