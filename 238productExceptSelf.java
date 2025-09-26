import java.util.*;

public class productExceptSelf{
    public static int[] productExceptSelf(int[] nums){

        int n=nums.length;
        int[] ans= new int[n];

        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        
        int suffix = 1;
        for(int i=n-1; i>=0; i--){
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        
        return ans;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        
        int[] nums = new int[n];
        for(int i=0;i<n;i++){
            System.out.println("Enter the element " + (i+1) );
            nums[i]=sc.nextInt();
        }
        int[] result = productExceptSelf(nums);
        System.out.println("Output (product except self): " + Arrays.toString(result));

        sc.close();;

    }
    
}

// 📊 Time & Space Complexity
// Metric	Complexity
// Time	O(n) — Two linear passes through the array
// Space	O(1) extra space (excluding the output array)


// 🏢 Companies & Year Asked

// According to several interview prep sources, top tech companies such as Facebook, Amazon,
// Apple, Netflix, Google, Microsoft, and Adobe have included this problem (or variants) in their interviews.