//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> distMat (n, vector<int> (m, 0));
        
        queue<pair<pair<int, int>, int>> q; // {{r, c}, steps}
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && mat[i][j] == 1) // if Grid has One
                {
                    vis[i][j] = 1; // Mark Visited
                    q.push({{i, j}, 0}); // Step 0
                }
            }
        }
        
        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};
                 // R, D, L, U
        
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            
            distMat[r][c] = steps;
            
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc] == 0)
                {
                    vis[nr][nc] = 1; // Mark Visited
                    q.push({{nr, nc}, steps + 1}); // Steps increment
                }
            }
            
        }
        
        return distMat;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends