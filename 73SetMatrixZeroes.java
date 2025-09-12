//73
//Java solution for LeetCode 73

import java.util.*;

public class SetMatrixZeroes {

    public static void setZeroes(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;
        
        Set<Integer> rowcon = new HashSet<>();
        Set<Integer> colcon = new HashSet<>();
       
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    rowcon.add(i);
                    colcon.add(j);
                }
            }
        }
        
       
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (rowcon.contains(i) || colcon.contains(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int m = sc.nextInt();
        System.out.print("Enter number of columns: ");
        int n = sc.nextInt();

        int[][] matrix = new int[m][n];
        System.out.println("Enter matrix elements: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        setZeroes(matrix);

        System.out.println("Matrix after setting zeroes:");
        for (int[] row : matrix) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}


// Time & Space Complexity

// Time Complexity: O(m * n) → scanning the matrix twice.
// Space Complexity: O(m + n) → for storing row and column sets.
// 👉 There’s an optimized solution with O(1) extra space (using the first row and column as markers).


// Companies & Year Asked

// This is a very popular matrix manipulation problem, often used to test in-place updates:
// Amazon (2021, 2022, 2023)
// Microsoft (2020, 2022)
// Adobe (2022)
// Goldman Sachs (2021)
// Apple (2021)
// Google (2020, 2022)