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
        vector<int> ahead(2, 0), curr(2, 0);
        
        ahead[0] = ahead[1] = 0;
        
        for(int i=n-1; i>=0; i--)
        {
            for(int buy = 0; buy<=1; buy++)
            {
                int profit = 0;
                
                if(buy)
                {
                    profit = max((-prices[i] + ahead[0]), ahead[1]);
                }
        
                else
                {
                    profit = max((prices[i] + ahead[1]), ahead[0]);
                }
                
                curr[buy] = profit;
            }
            
            ahead = curr;
        }
        return ahead[1];
        
    }
};