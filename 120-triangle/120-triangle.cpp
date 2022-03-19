class Solution {
private:
    int f(int  i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i ==  triangle.size()-1) return triangle[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down = triangle[i][j] + f(i+1, j, triangle, dp);
        int dg = triangle[i][j] + f(i+1, j+1, triangle, dp);
        
        return dp[i][j] = min(down,dg);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = m;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        return f(0, 0, triangle, dp);
    }
};