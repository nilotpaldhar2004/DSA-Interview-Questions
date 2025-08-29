//121
import java.util.Arrays;
import java.util.Scanner;

public class BestTimeToBuySell {
    public static int maxProfit(int[] prices) {
        int maxProfit = 0;
        int minPrice = prices[0];

        for (int price : prices) {
            maxProfit = Math.max(maxProfit, price - minPrice);
            minPrice = Math.min(minPrice, price);
        }
        return maxProfit;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of days (length of prices array): ");
        int n = sc.nextInt();
        int[] prices = new int[n];
        System.out.println("Enter prices array:");
        for (int i = 0; i < n; i++) {
            prices[i] = sc.nextInt();
        }

        int result = maxProfit(prices);
        System.out.println("Maximum profit = " + result);
        sc.close();
    }
}
