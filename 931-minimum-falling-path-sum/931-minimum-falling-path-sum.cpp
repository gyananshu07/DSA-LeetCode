class Solution {
private:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(j<0 || j>=matrix[0].size()) return 1e8;
        if(i==0) return matrix[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = matrix[i][j] + f(i-1, j, matrix, dp);
        int ld = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int rd = matrix[i][j] + f(i-1, j+1, matrix, dp);
        
        return dp[i][j] = min(up, min(ld, rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int mini = 1e8;
        
        for(int j=0; j<n; j++)
        {
            mini = min(mini, f(m-1, j, matrix, dp));
        }
        
        return mini;
    }
};