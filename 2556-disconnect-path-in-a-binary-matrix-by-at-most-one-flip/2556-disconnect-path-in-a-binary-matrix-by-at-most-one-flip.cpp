class Solution {
public:
    bool dfs(vector<vector<int>> &grid, int i, int j){ 
        if(i+1 == grid.size() && j+1 == grid[0].size()) return true;
        if(i+1 < grid.size() && grid[i+1][j] == 1){ 
            grid[i][j] = 0;
            if(dfs(grid, i+1, j) ) return true;
        }
        if(j+1 < grid[0].size() && grid[i][j+1] == 1){ 
            grid[i][j] = 0;
            return dfs(grid, i, j+1);
        }
        return false;
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if(dfs(grid, 0, 0) == false) return true;
        grid[0][0] = 1;
        if(dfs(grid, 0, 0) == false) return true;
        return false;
    }
};