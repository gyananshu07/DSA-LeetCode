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
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));
        
//         int mini = 1e8;
        
//         for(int j=0; j<n; j++)
//         {
//             mini = min(mini, f(m-1, j, matrix, dp));
//         }
        
//         return mini;
//     }
// };
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n, 0), curr(n, 0);
        
        int mini = 1e8;
        
        for(int j=0; j<m; j++)
        {
            prev[j] = matrix[0][j];
        }
        
        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int up = matrix[i][j] + prev[j];
                int ld = matrix[i][j];
                
                if(j-1>=0)
                    ld += prev[j-1];
                else
                    ld += 1e8;
                
                int rd = matrix[i][j];
                
                if(j+1<n)
                    rd += prev[j+1];
                else
                    rd += 1e8;
                
                curr[j] = min(up, min(ld, rd));
            }
            prev = curr;
        }
        
        for(int j=0; j<n; j++)
        {
            mini = min(mini, prev[j]);
        }
        
        return mini;
    }
};