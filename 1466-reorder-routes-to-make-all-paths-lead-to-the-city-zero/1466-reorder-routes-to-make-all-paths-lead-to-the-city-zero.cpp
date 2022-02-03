class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visited(n);
        vector<vector<int>> adj(n), back(n);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        int ans = 0;
        
        for (auto c : connections){
            adj[c[0]].push_back(c[1]);
            back[c[1]].push_back(c[0]);
        }
        
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            
            for (auto a: adj[curr]){
                if (!visited[a]){
                    ans++;
                    q.push(a);
                    visited[curr] = 1;
                }
            }

            for (auto b: back[curr]){
                if (!visited[b]) 
                {
                    q.push(b);
                    visited[curr] = 1;
                }
            }
        }
        return ans;
    }
};