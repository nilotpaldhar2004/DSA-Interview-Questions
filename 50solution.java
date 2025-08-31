import java.util.Scanner;
//50
class Solution {
    public double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 0) return 0.0;
        if (x == 1) return 1.0;
        if (x == -1 && n % 2 == 0) return 1.0;
        if (x == -1 && n % 2 != 0) return -1.0;

        long binform = n;
        if (n < 0) {
            x = 1 / x;
            binform = -binform;
        }

        double ans = 1.0;
        while (binform > 0) {
            if (binform % 2 == 1) {
                ans *= x;
            }
            x *= x;
            binform /= 2;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
      
        System.out.print("Enter base (x): ");
        double x = sc.nextDouble();

        System.out.print("Enter exponent (n): ");
        int n = sc.nextInt();

       
        Solution sol = new Solution();
        double result = sol.myPow(x, n);

        System.out.println("Result: " + result);
        
        sc.close();
    }
}


// Time Complexity

// O(log n) → Each step halves the exponent.

// Space Complexity

// O(1) → Uses constant space.

// Asked In (Company & Year)

// Amazon (2019, 2021, 2022)

// Microsoft (2020, 2023)

// Google (2018, 2021)

// Adobe (2022)

// Bloomberg (2021)

// Apple (2020)