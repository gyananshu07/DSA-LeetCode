class Solution {
public:
    void dfs(int node, vector<vector<int>> &graph, vector<int> &vis)
    {
        vis[node]=1;
        
        for(auto it: graph[node])
        {
            if(!vis[it])
            {
                dfs(it, graph, vis);
            }
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<int> vis(n,0);
        int ans=0, edgeCount=0;
        
        for(auto c: connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
            edgeCount++;
        }
        
        if(edgeCount<n-1)
        {
            return -1;
        }
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i, graph, vis);
            }
        }
        
        return ans-1;
    }
};