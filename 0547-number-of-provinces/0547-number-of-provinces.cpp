class Solution {
public:
    void dfsGraph(int node, vector<int> &vis, vector<int> adj[])
    {
        if(!vis[node])
        {
            vis[node] = 1;
            
            for(auto it: adj[node])
            {
                dfsGraph(it, vis, adj);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V];
        
        for(int i=0; i<V; i++){
            for(int j=0; j<isConnected[0].size(); j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(V+1, 0);
        int count=0;
        
        for(int i=0 ; i<V ; i++)
        {
            if(!vis[i])
            {
                count++;
                dfsGraph(i, vis, adj);
            }
        }
        
        return count;
    }
};