//74
//Java solution for LeetCode 18 – 4Sum using sorting + two-pointer approach. Includes user input version for testing.

import java.util.*;

public class Search2DMatrix {
    
    // Binary search inside a row
    public static boolean searchInRow(int[][] matrix, int target, int row) {
        int n = matrix[0].length;
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;  // fixed formula
            if (target == matrix[row][mid]) {
                return true;
            } else if (target > matrix[row][mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }

    // Main search function
    public static boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int startRow = 0, endRow = m - 1;
        
        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;
            if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1]) {
                return searchInRow(matrix, target, midRow);
            } else if (target > matrix[midRow][n - 1]) {
                startRow = midRow + 1;
            } else {
                endRow = midRow - 1;
            }
        }
        return false;
    }

    // Driver code for GitHub with user input
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of rows (m): ");
        int m = sc.nextInt();
        System.out.println("Enter number of columns (n): ");
        int n = sc.nextInt();

        int[][] matrix = new int[m][n];
        System.out.println("Enter matrix elements row-wise:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        System.out.println("Enter target value: ");
        int target = sc.nextInt();

        boolean result = searchMatrix(matrix, target);
        System.out.println("Target found? " + result);

        sc.close();
    }
}

// Time & Space Complexity

// Time Complexity:

// Binary search on rows → O(log m)

// Binary search inside a row → O(log n)

// Total = O(log m + log n)

// Space Complexity: O(1) (only variables, no extra storage)



// Company & Year Asked

// Asked in Amazon (2021, 2023)

// Asked in Google (2022)

// Asked in Microsoft (2020, 2021)

// Asked in Adobe (2023)