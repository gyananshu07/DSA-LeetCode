class Solution {
public:
    int f (int n, vector<int> &dp)
    {
        if(n == 0 || n == 1)
            return 1; 
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = f(n-2, dp) + f(n-1, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        
        int prev = 1;
        int before_prev = 1;
        int cur = 1;
        
        for(int i=2; i<=n; i++)
        {
            cur = prev + before_prev; 
            before_prev = prev;
            prev = cur;
        }
        
        return cur;
    }
};