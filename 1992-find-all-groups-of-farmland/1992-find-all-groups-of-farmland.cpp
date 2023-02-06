class Solution {
private:
    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& land, vector<int> &temp)
    {
        int n = land.size();
        int m = land[0].size();
        
        queue<pair<int, int>> q; // queue
        
        q.push({i, j});
        vis[i][j] = 1;
        
        //push starting coordinates of BFS of a connected component to temp
        temp.push_back(i);
        temp.push_back(j);
        
        //4 Dir ->  R,  D, L, U
        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};
        
        int lrow = 0, lcol = 0; //stores the last row & col
        
        while(!q.empty())
        {
            int row = q.front().first; 
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + dr[i]; //neighbour row
                int ncol = col + dc[i]; //neighbour col
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m
                  && !vis[nrow][ncol] && land[nrow][ncol] == 1) //check if the neigbouring row & col is in boundary & visited &                   that is a farmland
                {
                    vis[nrow][ncol] = 1;  //mark visited
                    q.push({nrow, ncol}); //push new row & col to queue
                    
                }
            }
            
            //stores the last row & col
            lrow = row;
            lcol = col;            
        }
        
        //push ending coordinates of BFS of a connected component to temp
        temp.push_back(lrow);
        temp.push_back(lcol);
        
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0)); //visited array
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                vector<int> temp;
                if(!vis[i][j] && land[i][j]==1) //check if not visited and is a farmland
                {
                    bfs(i, j, vis, land, temp); // BFS Call
                    ans.push_back(temp); // ans 2D array
                }
            }
        }
        
        return ans; //returns the 2D array
    }
};