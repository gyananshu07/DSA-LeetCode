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
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));
        
//         return f(m-1, n-1, grid, dp);
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0) 
                    dp[i][j] = grid[i][j];
                
                else
                {
                    int up=0, left=0;
                    
                    if(i>0)
                        up = grid[i][j] + dp[i-1][j];
                    else
                        up += 1e9;
                
                    if(j>0)
                        left = grid[i][j] + dp[i][j-1];
                    else
                        left += 1e9;
                
                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
            
};