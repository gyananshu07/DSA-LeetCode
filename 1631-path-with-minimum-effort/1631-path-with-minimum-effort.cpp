class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> q;
        //{diff, {row, col}} -> min prority queue
        
        q.push({0, {0, 0}});
        dist[0][0] = 0;
        
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == m-1)
            {
                return dis;
            }
            
            for(int i=0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int efforts = max(abs(grid[r][c] - grid[nr][nc]), dis);
                    
                    if(efforts < dist[nr][nc])
                    {
                        dist[nr][nc] = efforts;
                        q.push({efforts, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};