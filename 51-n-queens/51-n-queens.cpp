class Solution {
public:
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftCol, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++)
        {
            if(leftCol[row] == 0 && upperDiagonal[(n-1) + col-row] == 0 && lowerDiagonal[row+col] == 0)
            {
                board[row][col] = 'Q';
                
                leftCol[row] = 1;
                upperDiagonal[(n-1) + col-row] = 1;
                lowerDiagonal[row+col] = 1;
                
                solve(col+1, n, board, ans, leftCol, upperDiagonal, lowerDiagonal);
                
                board[row][col] = '.';
                
                leftCol[row] = 0;
                upperDiagonal[(n-1) + col - row] = 0;
                lowerDiagonal[row+col] = 0;
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i = 0; i<n; i++)
        {
            board[i] = s;
        }
        
        vector<int> leftCol(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        
        solve(0, n, board, ans, leftCol, upperDiagonal, lowerDiagonal);
        
        return ans;
    }
};