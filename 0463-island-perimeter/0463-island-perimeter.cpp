class Solution
{
public:
    int ans = 0;
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        vis[r][c] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if ((nr < 0 or nr == n) and nc >= 0)
                ans++;
                
            if ((nc < 0 or nc == m) and nr >= 0)
                ans++;

            if (nr >= 0 and nr < n and nc >= 0 and nc < m)
            {
                if (!grid[nr][nc])
                    ans++;

                if (grid[nr][nc] and !vis[nr][nc])
                    dfs(nr, nc, grid, vis);
            }
        }
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] and !vis[i][j])
                    dfs(i, j, grid, vis);
            }
        }

        return ans;
    }
};