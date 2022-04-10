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
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        
        return (int) f(0, 1, dp, prices);
        
    }
};