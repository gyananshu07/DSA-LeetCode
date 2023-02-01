class Solution {
private: 
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>>& board, int dr[], int dc[])
    {
        vis[r][c] = 1;
        
        int n= board.size();
        int m= board[0].size();
        
        for (int i=0; i<4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr>=0 && nr<n && nc>=0 && nc<m
                && !vis[nr][nc] && board[nr][nc]=='O' )
            {
                dfs(nr, nc, vis, board, dr, dc);
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        
        // first row & last row
        for (int j=0; j<m; j++)
        {
            if(board[0][j] == 'O' && !vis[0][j])
            {
                vis[0][j] = 1;
                dfs(0, j, vis, board, dr, dc);
            }
            
            if(board[n-1][j] == 'O' && !vis[n-1][j])
            {
                vis[n-1][j] = 1;
                dfs(n-1, j, vis, board, dr, dc);
            }
        }
        
        // first col & last col
        for (int i=0; i<n; i++)
        {
            if(board[i][0] == 'O' && !vis[i][0])
            {
                vis[i][0] = 1;
                dfs(i, 0, vis, board, dr, dc);
            }
            
            if(board[i][m-1] == 'O' && !vis[i][m-1])
            {
                vis[i][m-1] = 1;
                dfs(i, m-1, vis, board, dr, dc);
            }
        }
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
        
    }
};