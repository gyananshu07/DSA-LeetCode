class Solution {
private:
    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& land, vector<int> &temp)
    {
        int n = land.size();
        int m = land[0].size();
        
        queue<pair<int, int>> q;
        
        q.push({i, j});
        vis[i][j] = 1;
        temp.push_back(i);
        temp.push_back(j);
        
        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};
        
        int lrow = 0, lcol = 0; 
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m
                  && !vis[nrow][ncol] && land[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    
                }
            }
            lrow = row;
            lcol = col;            
        }
        temp.push_back(lrow);
        temp.push_back(lcol);
        
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        
        vector<int> temp;
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                vector<int> temp;
                if(!vis[i][j] && land[i][j]==1)
                {
                    bfs(i, j, vis, land, temp);
                    ans.push_back(temp);
                }
            }
        }
        
        return ans;
    }
};