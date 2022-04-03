class Solution {
    private:
    int f(int ind1, int ind2, vector<vector<int>> &dp, string text1, string text2)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
        
        if(dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }
        
        if(text1[ind1] == text2[ind2]){
            return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, dp, text1, text2);
        }
        
        return dp[ind1][ind2] = max(f(ind1-1, ind2, dp, text1, text2), f(ind1, ind2-1, dp, text1, text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1] == text2[j-1])
                    curr[j]= 1 + prev[j-1];
                else
                     curr[j] = max(prev[j], curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
};