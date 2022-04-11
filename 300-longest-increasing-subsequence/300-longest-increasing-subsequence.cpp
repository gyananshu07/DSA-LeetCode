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
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = n-1; i>=0; i--)
        {
            for(int prevInd = i-1; prevInd>=-1; prevInd--)
            {
                int len = 0 + dp[i+1][prevInd+1]; //notTake
            
                if(prevInd == -1 || nums[i]>nums[prevInd])
                {
                    len = max(len, 1 + dp[i+1][i+1]); //take
                }
        
                dp[i][prevInd+1] = len;
            }
        }
        return dp[0][-1+1];
        
    }
};