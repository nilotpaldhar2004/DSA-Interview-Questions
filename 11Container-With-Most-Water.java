//11
import java.util.Arrays;
import java.util.Scanner;

public class ContainerWithMostWater {
    public static int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        int maxArea = 0;

        while (left < right) {
            int width = right - left;
            int ht = Math.min(height[left], height[right]);
            maxArea = Math.max(maxArea, width * ht);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of lines (n): ");
        int n = sc.nextInt();

        int[] height = new int[n];
        System.out.println("Enter the heights array:");
        for (int i = 0; i < n; i++) {
            height[i] = sc.nextInt();
        }

        int result = maxArea(height);
        System.out.println("Maximum water container area = " + result);

        sc.close();
    }
}
