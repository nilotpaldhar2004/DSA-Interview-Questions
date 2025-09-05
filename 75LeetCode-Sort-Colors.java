//Java solution for LeetCode 75 – Sort Colors using the Dutch National Flag algorithm (one-pass, in-place). Includes user input version for easy testing.
import java.util.*;

public class sorted{
    public static void sorted(int[] nums){
        int n=nums.length;
        int l=0,m=0,h=n-1;
        while (m<=h) {
            if(nums[m]==0){
                swap(nums,l,m);
                m++;
                l++;
            }
            else if (nums[m]==1) {
                m++;
            }
            else{
                swap(nums,m,h);
                      h--;
                
            }
        }
    }

    private static void swap(int[] nums,int i,int j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }

public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    System.out.print("Enter the no. of element : ");
    int n = sc.nextInt();
    int[] nums = new int[n];
    System.out.println("Enter array elements (only 0, 1, or 2):");
    for(int i=0;i<n;i++){
          nums[i]=sc.nextInt();
    }
    sorted(nums);
    System.out.println("Sorted colors array: "+ Arrays.toString(nums));
    sc.close();

}
}