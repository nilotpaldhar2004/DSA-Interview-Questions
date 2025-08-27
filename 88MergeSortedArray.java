//Leetcode 88
import java.util.*;

public class MergeSortedArray {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int idx = m + n - 1;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j]) {
                nums1[idx--] = nums2[j--];
            } else {
                nums1[idx--] = nums1[i--];
            }
        }

        while (j >= 0) {
            nums1[idx--] = nums2[j--];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

       
        System.out.print("Enter size of nums1 (m+n): ");
        int size1 = sc.nextInt();
        System.out.print("Enter number of valid elements in nums1 (m): ");
        int m = sc.nextInt();
        System.out.print("Enter size of nums2 (n): ");
        int n = sc.nextInt();

      
        int[] nums1 = new int[size1];
        System.out.println("Enter " + m + " elements of nums1 (sorted):");
        for (int i = 0; i < m; i++) {
            nums1[i] = sc.nextInt();
        }

      
        for (int i = m; i < size1; i++) {
            nums1[i] = 0;
        }

      
        int[] nums2 = new int[n];
        System.out.println("Enter " + n + " elements of nums2 (sorted):");
        for (int i = 0; i < n; i++) {
            nums2[i] = sc.nextInt();
        }

     
        merge(nums1, m, nums2, n);

        
        System.out.println("Merged Sorted Array: " + Arrays.toString(nums1));

        sc.close();
    }
}
