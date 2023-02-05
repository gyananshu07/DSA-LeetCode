class Solution {
private:
  bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<int> adj[])
  {
      vis[node] = 1;
      pathVis[node] = 1;
      check[node] = 0;
      
      for(auto it: adj[node])
      {
          if(!vis[it])
          {
              if(dfs(it, vis, pathVis, check, adj) == true)
              {
                  check[node] = 0;
                  return true;
              }
          }
          else if(vis[it] == 1 && pathVis[it] == 1)
          {
              check[node] = 0;
              return true;
          }
      }
      
      check[node] = 1;
      pathVis[node] = 0;
      
      return false;
  }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size(); // total number of rows present in graph
        vector<int> adj[V];
        
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<int> vis(V, 0), pathVis(V, 0), check(V, 0), safeNodes;
        
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, pathVis, check, adj);
            }
        }
        
        for(int i=0; i<V; i++)
        {
            if(check[i]==1)
            {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};