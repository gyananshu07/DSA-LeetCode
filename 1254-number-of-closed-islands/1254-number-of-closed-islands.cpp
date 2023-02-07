class Solution
{
    private:
        
    void bfs(int r, int c, vector<vector < int>> &vis, vector< vector< int>> &grid)
    {
        vis[r][c] = 1;

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({ r,
            c });

        int dr[] = { 0,
            -1,
            0,
            1
        };
        int dc[] = { -1,
            0,
            1,
            0
        };

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({ nrow,
                        ncol });
                }
            }
        }
    }

    public:
        int closedIsland(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            
            int ans = 0;

            vector<vector < int>> vis(n, vector<int> (m, 0));
            
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if ((i*j == 0 || i == n-1 || j == m-1) && !vis[i][j] && grid[i][j] == 0)
                    {
                        bfs(i, j, vis, grid);
                    }
                }
            }

            for (int i = 1; i < n-1; i++)
            {
                for (int j = 1; j < m-1; j++)
                {
                    if (!vis[i][j] && grid[i][j] == 0)
                    {
                        bfs(i, j, vis, grid);
                        ans++;
                    }
                }
            }

            return ans;
        }
};