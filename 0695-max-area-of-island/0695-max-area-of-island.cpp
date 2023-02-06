class Solution {
    
private:
    int ans=0;
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>>& grid)
    {
        queue<pair<int, int>> q;
        
        q.push({r, c});
        vis[r][c] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        
        int cnt = 1;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
        
            for(int i=0; i<4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m &&
                   !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    cnt++;
                    q.push({nrow, ncol});
                }
            }
        }
        ans = max(cnt, ans);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    bfs(i, j, vis, grid);
                }
            }
        }
        
        return ans;
    }
};