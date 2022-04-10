class Solution {
private:
    long f(int i, int buy, int maxi, vector<vector<vector<int>>> &dp, vector<int>& prices)
    {
        if(maxi==0) return 0;
        if(i == prices.size())
        {
            return 0;
        }

        if(dp[i][buy][maxi]!=-1) return dp[i][buy][maxi];

        int profit = 0;

        if(buy)
        {
            profit = max((-prices[i] + f(i+1, 0, maxi, dp, prices)), f(i+1, 1, maxi, dp, prices));
        }

        else
        {
            profit = max((prices[i] + f(i+1, 1, maxi-1, dp, prices)), f(i+1, 0, maxi, dp, prices));
        }

        return dp[i][buy][maxi] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        
        return (int) f(0, 1, k, dp, prices);
    }
};