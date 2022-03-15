class Solution {
public:
    int rob(vector<int>& nums) 
    {
//         int n =  nums.size();
//         vector<int> dp(n+1, -1);
        
//         dp[0] = nums[0];
        
//         int neg = 0;
        
//         for(int i=1; i<n; i++)
//         {
//             int take = nums[i];
//             if(i>1)
//             {
//                 take += dp[i-2];
//             }
            
//             int nonTake = 0 + dp[i-1];
            
//             dp[i] = max(take, nonTake);
//         }
//         return dp[n-1];
        int n =  nums.size();
        
        int prev = nums[0];
        
        int prev2 = 0;
        
        for(int i=1; i<n; i++)
        {
            int take = nums[i];
            if(i>1)
            {
                take += prev2;
            }
            
            int nonTake = 0 + prev;
            
            int curr_i = max(take, nonTake);
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
    }
};