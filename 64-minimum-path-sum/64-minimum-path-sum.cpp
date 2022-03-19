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
        vector<int> prev(n, 0);
        
        for(int i=0; i<m; i++)
        {
            vector<int> curr(n, 0);
            
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0) 
                    curr[j] = grid[i][j];
                
                else
                {
                    int up=0, left=0;
                    
                    if(i>0)
                        up = grid[i][j] + prev[j];
                    else
                        up += 1e9;
                
                    if(j>0)
                        left = grid[i][j] + curr[j-1];
                    else
                        left += 1e9;
                
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
            
};