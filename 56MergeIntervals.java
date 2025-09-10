//56
//Java solution for LeetCode 56

import java.util.*;

public class MergeIntervals {

    public static int[][] merge(int[][] intervals) {
        if (intervals.length <= 1) {
            return intervals;
        }

        
        Arrays.sort(intervals, Comparator.comparingInt(i -> i[0]));

        List<int[]> result = new ArrayList<>();
        int[] newInterval = intervals[0];
        result.add(newInterval);

        
        for (int[] interval : intervals) {
            if (interval[0] <= newInterval[1]) {
               
                newInterval[1] = Math.max(newInterval[1], interval[1]);
            } else {
                
                newInterval = interval;
                result.add(newInterval);
            }
        }

        return result.toArray(new int[result.size()][]);
    }

   
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of intervals: ");
        int n = sc.nextInt();
        int[][] intervals = new int[n][2];

        System.out.println("Enter intervals (start end): ");
        for (int i = 0; i < n; i++) {
            intervals[i][0] = sc.nextInt();
            intervals[i][1] = sc.nextInt();
        }

        int[][] merged = merge(intervals);

        System.out.println("Merged Intervals:");
        for (int[] interval : merged) {
            System.out.println(interval[0] + " " + interval[1]);
        }

        sc.close();
    }
}

// Time & Space Complexity

// Time Complexity:
// Sorting: O(n log n)
// Merging: O(n)
// Total = O(n log n)
// Space Complexity:
// Output list: O(n) (in worst case when no intervals overlap).
// Sorting is in-place (Java’s sort uses O(log n) stack for recursion).


// Companies & Year Asked

// This problem is extremely popular and frequently asked:
// Google (2020, 2022, 2023)
// Facebook/Meta (2019, 2021)
// Amazon (2021, 2022)
// Microsoft (2020, 2022)
// Apple (2021)
// Adobe (2022)