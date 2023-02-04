//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int row, int col, vector<pair<int, int>> &v, vector<vector<int>> &vis, vector<vector<int>> &grid, int baseRow, int baseCol)
    {
        vis[row][col] = 1;
        v.push_back({row-baseRow, col-baseCol});
        
        int n = grid.size();
        int m = grid[0].size();
        
        int dR[] = {0, -1, 1, 0};
        int dC[] = {-1, 0, 0, 1};
        
        for(int i=0; i<4; i++)
        {
            int nRow = row + dR[i];
            int nCol = col + dC[i];
            
            if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
            {
                dfs(nRow, nCol, v, vis, grid, baseRow, baseCol);
            }
        }
        
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis (n, vector<int> (m, 0));
        set<vector<pair<int, int>>> s;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> v;
                    dfs(i, j, v, vis, grid, i, j);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends