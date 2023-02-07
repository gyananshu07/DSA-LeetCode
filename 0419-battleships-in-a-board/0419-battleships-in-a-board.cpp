class Solution {
private:
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>>& board)
    {
        vis[r][c] = 1;
        
        int n = board.size();
        int m = board[0].size();
        
        queue<pair<int, int>> q;
        q.push({r, c});
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 'X')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && board[i][j] == 'X')
                {
                    bfs(i, j, vis, board);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};