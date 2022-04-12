class Solution {
private:
    int f(int i, int prevInd, vector<int>& nums, vector<vector<int>> &dp)
    {
        if(i==nums.size())
        {
            return 0;
        }
        
        if(dp[i][prevInd+1] != -1 ) return dp[i][prevInd+1];
        
        int len = 0 + f(i+1, prevInd, nums, dp); //notTake
            
        if(prevInd == -1 || nums[i]>nums[prevInd])
        {
            len = max(len, 1 + f(i+1, i, nums, dp)); //take
        }
        
        return dp[i][prevInd+1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi=1;
        
        vector<int> dp(n, 1);
        
        for(int i = 0 ; i<n; i++)
        {
            for(int prev=0; prev<i; prev++)
            {
                if(nums[prev]<nums[i])
                {
                    dp[i] = max(1+dp[prev], dp[i]);
                }
            }
            
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};