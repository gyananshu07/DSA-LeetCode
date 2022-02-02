class Solution {
public:
    bool checkCycle(int i, int parent, vector<vector<int>>& graph, vector<int>& vis)
    {
        vis[i]=1;
        for(auto it: graph[i])
        {
            if(vis[it]==0)
            {
                if(checkCycle(it, i, graph, vis)) return true;
            }
            
            else if(it!=parent) return true;
        }
        vis[i]=0;
        
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> vis(n,0);
        vector<vector<int>> graph(n);
        
        for(auto edge: edges)
        {
            
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            
            if(checkCycle(edge[0], -1, graph, vis))
            {
                return edge;
            }
        }
        
        return {1,4,5,3};
    }
};