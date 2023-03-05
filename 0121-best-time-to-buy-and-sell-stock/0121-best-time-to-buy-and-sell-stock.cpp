class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, maxProfit = 0;
        
        for(int i=0; i<prices.size(); i++)
        {
            cost = min(prices[i], cost);
            int profit = abs(cost - prices[i]);
            maxProfit = max(maxProfit, profit);
        }
        
        return maxProfit;
    }
};