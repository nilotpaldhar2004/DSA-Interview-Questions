//31
//Java solution for LeetCode 31

import java.util.*;

public class NextPermutation {

    public static void nextPermutation(int[] nums) {
        int n = nums.length;
        int pivot = -1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(nums, 0, n - 1);
            return;
        }

        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums, i, pivot);
                break;
            }
        }

        reverse(nums, pivot + 1, n - 1);
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private static void reverse(int[] nums, int i, int j) {
        while (i < j) {
            swap(nums, i++, j--);
        }
    }

   
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of array: ");
        int n = sc.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter array elements: ");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        nextPermutation(nums);

        System.out.println("Next Permutation:");
        for (int num : nums) {
            System.out.print(num + " ");
        }

        sc.close();
    }
}


// Time & Space Complexity

// Time Complexity: O(n)

// Finding pivot → O(n)

// Finding swap index → O(n) (worst case)

// Reversing suffix → O(n)

// Total = O(n)

// Space Complexity: O(1) (in-place swaps, no extra memory)



// Company & Year Asked

// This problem is a classic interview favorite and has been repeatedly asked in top product companies:
// Amazon (2021, 2022)
// Microsoft (2020, 2022)
// Google (2020, 2021, 2023)
// Facebook/Meta (2019, 2021)
// Adobe (2022)