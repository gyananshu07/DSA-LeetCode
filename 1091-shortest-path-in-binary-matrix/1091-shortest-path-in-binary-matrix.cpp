class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (grid[0][0] == 1 or grid[n-1][m-1] == 1)return -1;
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q; //{dist, {row, col}}
        
        q.push({1, {0, 0}});
        dist[0][0] = 0;
        
        vector<vector<int>> directions={{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == m-1)
            {
                return dis;
            }
            
            for(auto direction: directions)
            {
                int nr = r + direction[0];
                int nc = c + direction[1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0)
                {
                    if(dis + 1 < dist[nr][nc])
                    {
                        dist[nr][nc] = dis + 1;
                        q.push({dis + 1, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};