class Solution {
private:
    long f(int i, int buy, vector<vector<int>> &dp, vector<int>& prices)
    {
        if(i == prices.size())
        {
            return 0;
        }
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        int profit = 0;
        
        if(buy)
        {
            profit = max((-prices[i] + f(i+1, 0, dp, prices)), f(i+1, 1, dp, prices));
        }
        
        else
        {
            profit = max((prices[i] + f(i+1, 1, dp, prices)), f(i+1, 0, dp, prices));
        }
        
        return dp[i][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int buy = 0; buy<=1; buy++)
            {
                int profit = 0;
                
                if(buy)
                {
                    profit = max((-prices[i] + dp[i+1][0]), dp[i+1][1]);
                }
        
                else
                {
                    profit = max((prices[i] + dp[i+1][1]), dp[i+1][0]);
                }
                
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
        
    }
};