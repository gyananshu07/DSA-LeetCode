class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        int m=grid.size(), n=grid[0].size(), countF=0, countR=0;
        int vis[m][n];
        queue<pair<pair<int, int>, int>> rotten;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    countF++;
                }
                if(grid[i][j] == 2)
                {
                    rotten.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int tm = 0;

        while(!rotten.empty())
        {
            int x = rotten.front().first.first;
            int y = rotten.front().first.second;
            int t = rotten.front().second;
            rotten.pop();
            
            tm = max(tm, t);

            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && vis[nx][ny] == 0 && grid[nx][ny] == 1)
                {
                    vis[nx][ny] = 2;
                    rotten.push({{nx, ny}, t+1});
                    countR++;
                }
            }    
        }

        return countF == countR ? tm : -1;
    }
};