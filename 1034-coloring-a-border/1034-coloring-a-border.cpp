class Solution {
public:
    vector<int> dr = {-1,1,0,0};
    vector<int> dc = {0,0,1,-1};
    
    bool isValid(int row, int col,int ROW,int COL)
    {
     // If cell lies out of bounds
     if (row < 0 || col < 0 || row >= ROW || col >= COL)
         return false;
     else
         return true;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        bool vis[m][n];
        memset( vis, false, sizeof(vis));
        
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = true;
        int cncolor = grid[row][col]; // connected component color
               
         while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(int i=0; i < 4; i++)
            {
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];
                // any component lies outside then, it is border cell
                if(!isValid(nr,nc,m,n)){
                   grid[curr.first][curr.second] = color;
                   continue;
                }
                // even if one of adjcent cell donot have the same color then it's also a border
                if(grid[nr][nc] != cncolor && !vis[nr][nc]){
                    // as it may be possible that it was intially 2 but it has changed to 1,
                    // so check for visited also
                    grid[curr.first][curr.second] = color;
                }
                
                if(!vis[nr][nc] && grid[nr][nc] == cncolor){
                     q.push({nr,nc});
                     vis[nr][nc] = true;
                 } 
            }
          }
        
       return grid; 
    }
};