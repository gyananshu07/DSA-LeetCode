class Solution {
public:
    int diagonalSum(vector<vector<int>>& grid) {
         int n = grid.size();
        int sum=0;
        
        for(int i=0; i<grid.size(); i++)
        {
                sum += grid[i][i] + grid[i][n-1-i];
        }
        
        return n%2 == 0? sum : sum = sum-grid[(n-1)/2][(n-1)/2];
    }
};