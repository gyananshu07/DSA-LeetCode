class Solution {
private:
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(row==0 && col==0)
        {
            return grid[row][col];
        }
        
        if(row<0 || col<0)
        {
            return 1e9;
        }
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int up = grid[row][col] + f(row-1, col, grid, dp);
        int left = grid[row][col] + f(row, col-1, grid, dp);
        
        return dp[row][col] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return f(m-1, n-1, grid, dp);
    }
};