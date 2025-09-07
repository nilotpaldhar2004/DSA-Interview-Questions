//18
//Java solution for LeetCode 18 – 4Sum using sorting + two-pointer approach. Includes user input version for testing.

import java.util.*;

public class FourSum {
    public static List<List<Integer>> foursum(int[] nums,int target){
        List<List<Integer>>ans = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        for(int i =0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int p=j+1;
                int q=n-1;
                while (p<q) {
                    long sum = (long)nums[i] + nums[j] + nums[p] +nums[q];
                    if(sum<target){
                        p++;
                    }
                    else if(sum>target){
                        q--;
                    }
                    else{
                        if(sum==target){
                            ans.add(Arrays.asList(nums[i],nums[j],nums[p],nums[q]));
                            p++;
                            q--;
                        }
                        while (p < q && nums[p] == nums[p - 1]) p++;
                        while (p < q && nums[q] == nums[q + 1]) q--;

                    }
                }

            }
        }
        return ans;


    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of Array : ");
        int n =sc.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter the Array : ");
        for(int i=0;i<n;i++){
            nums[i] = sc.nextInt();
        }

        System.out.print("Enter the target : ");
        int target = sc.nextInt();

        List<List<Integer>> result = foursum(nums,target);
        System.out.print("Quadruplets that sum to target: " + result);

        sc.close();

    }
}

//  Time & Space Complexity

// Time Complexity:

// Sorting: O(n log n)

// Nested loops + two pointers → O(n³)

// Total: O(n³)

// Space Complexity: O(1) (ignoring output list)




// 🏢 Companies That Asked 4Sum

// The 4Sum problem (LeetCode 18) is a classic FAANG interview problem. While exact year mentions are rare, it is well-documented in interview prep as frequently asked in:

// Amazon (2021, 2022)

// Google (2019, 2021)

// Microsoft (2020, 2022)

// Facebook (Meta) (2018, 2021)

// Bloomberg, Uber, Adobe