class Solution {
public:
    
    void dfs(int node, int parent, vector<int> &low, vector<int> &tin, int &timer, vector<vector<int>> &ans, vector<vector<int>> &graph, vector<int> &vis)
    {
        vis[node]=1;
        low[node]=tin[node]=timer++;
        
        for(auto it: graph[node])
        {
            if(it==parent) continue;
            
            else if(!vis[it])
            {
                vector<int> res;
                dfs(it, node, low, tin, timer, ans, graph, vis);
                low[node] = min(low[node], low[it]);
                if(low[it]>tin[node])
                {
                    res.push_back(node);
                    res.push_back(it);
                } 
                if(!res.empty())
                    ans.push_back(res);
            }
            
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector<vector<int>> graph(n);
        vector<vector<int>> ans;
        
        //Three Arrays -> visited [0, 0, 0 ...] / low-> [-1, -1, -1, ...] / tin-> [-1, -1, -1, ...]
        vector<int> vis(n, 0);
        vector<int> low(n, -1);
        vector<int> tin(n, -1);
        
        int timer=0;
        
        for(auto c: connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, -1, low, tin, timer, ans, graph, vis);
            }
        }
        
        return ans;
    }
};