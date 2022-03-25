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
        vector<vector<long>> dp(n, vector<long>(amount+1, -1));
        
        long ans = f(n-1, amount, coins, dp);
        
        return (int) ans;
    }
};