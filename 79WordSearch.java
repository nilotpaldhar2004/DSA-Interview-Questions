//79
//Java solution for LeetCode 739

import java.util.*;

public class WordSearch {

    public static boolean exist(char[][] board, String word) {
        int rows = board.length;
        int cols = board[0].length;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                if (board[i][j] == word.charAt(0) && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean dfs(char[][] board, String word, int i, int j, int idx) {
        
        if (idx == word.length()) return true;

        
        if (i < 0 || j < 0 || i >= board.length || j >= board[0].length
                || board[i][j] != word.charAt(idx)) {
            return false;
        }

       
        char temp = board[i][j];
        board[i][j] = '#';

       
        boolean found = dfs(board, word, i + 1, j, idx + 1) ||
                        dfs(board, word, i - 1, j, idx + 1) ||
                        dfs(board, word, i, j + 1, idx + 1) ||
                        dfs(board, word, i, j - 1, idx + 1);

       
        board[i][j] = temp;

        return found;
    }

    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter rows and columns: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        sc.nextLine(); // consume newline

        char[][] board = new char[m][n];
        System.out.println("Enter board row by row (characters without space):");
        for (int i = 0; i < m; i++) {
            String row = sc.nextLine();
            for (int j = 0; j < n; j++) {
                board[i][j] = row.charAt(j);
            }
        }

        System.out.print("Enter word to search: ");
        String word = sc.nextLine();

        boolean result = exist(board, word);
        System.out.println("Word found? " + result);

        sc.close();
    }
}

// Time & Space Complexity

// Time Complexity: O(M * N * 4^L)
// M*N → number of cells.
// L → length of the word.
// Each DFS explores up to 4 directions.
// Space Complexity: O(L) (recursion stack for DFS).


// Companies & Year Asked

// This problem is very popular in interviews:
// Amazon (2020, 2022, 2023)
// Google (2021, 2022)
// Microsoft (2021)
// Apple (2020)
// Adobe (2022)
// Facebook/Meta (2019, 2021)