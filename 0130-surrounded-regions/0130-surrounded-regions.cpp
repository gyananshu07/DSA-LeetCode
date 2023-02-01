class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (i==0 || j==0 || i==(n-1) || j==(m-1))
                {
                    if (board[i][j]=='O')
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }    
            }
        }
        
        int dx[]= {0, 1, 0, -1};
        int dy[]= {1, 0, -1, 0};
        
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int i=0; i<4; i++)
            {
                int nr= x+dx[i];
                int nc= y+dy[i];
                
                if (nr>=0 && nr<n && nc>=0 && nc<m
                    && !vis[nr][nc] && board[nr][nc]=='O' )
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
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