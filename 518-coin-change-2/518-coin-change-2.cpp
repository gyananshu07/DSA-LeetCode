class Solution {
private:
    long f(int ind, int amount, vector<int>& coins, vector<vector<long>> &dp)
    {
        if(ind==0)
        {
            return (amount%coins[0]==0);
        }
        
        if(amount==0) 
            return 1;
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        long notTake = 0 + f(ind-1, amount, coins, dp);
        
        long take = 0;
        
        if(coins[ind]<=amount)
        {
            take = f(ind, amount-coins[ind], coins, dp);
        }
        
        return dp[ind][amount] = take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount+1, 0));
        
        for(int T=0; T<=amount; T++)
        {
            dp[0][T] = (T%coins[0]==0);
        }
        
        for(int ind=1; ind<n; ind++)
        {
            for(int T=0; T<=amount; T++)
            {
                long notTake = dp[ind-1][T];
                long take = 0;
                
                if(coins[ind]<=T)
                {
                    take = dp[ind][T-coins[ind]];
                }
                
                dp[ind][T] = take + notTake;
            }
        }
        
        return dp[n-1][amount];
    }
};