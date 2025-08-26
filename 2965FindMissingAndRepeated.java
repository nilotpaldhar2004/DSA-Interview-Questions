//Leetcode 2965
import java.util.*;

public class FindMissingAndRepeated {
    public static int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        HashSet<Integer> set = new HashSet<>();
        int repeated = 0, missing = 0;
        int actualSum = 0;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                actualSum += val;

                if (set.contains(val)) {
                    repeated = val; 
                }
                set.add(val);
            }
        }

       
        int totalNumbers = n * n;
        int expectedSum = totalNumbers * (totalNumbers + 1) / 2;

        // Formula: missing = expected + repeated - actual
        missing = expectedSum + repeated - actualSum;

        return new int[]{repeated, missing};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of grid (n): ");
        int n = sc.nextInt();

        int[][] grid = new int[n][n];
        System.out.println("Enter elements of the grid:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = sc.nextInt();
            }
        }

        int[] result = findMissingAndRepeatedValues(grid);
        System.out.println("Repeated: " + result[0]);
        System.out.println("Missing: " + result[1]);

        sc.close();
    }
}


// Companies Asking Similar DSA Questions

// This problem belongs to Array/Matrix + Hashing category, which is very popular in coding interviews.
// Similar types (missing numbers, duplicates, hashset usage) are asked by:

// ✅ Amazon → Array + Hashing based questions (e.g., missing/duplicate problems).

// ✅ Microsoft → Matrix traversal + finding anomalies in sequences.

// ✅ Google → Problems with sum formulas & validation.

// ✅ Adobe, Apple, Facebook (Meta) → Variants of missing/repeated in grids and arrays.

// ✅ Bloomberg, Uber, Oracle → Number placement problems.