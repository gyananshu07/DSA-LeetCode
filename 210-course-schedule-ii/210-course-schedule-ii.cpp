class Solution {
public:
    vector<int> ans;
    bool checkCycle(int node, vector<vector<int>>& graph,  vector<int> &vis,  vector<int> &dfsVis)
    {
        vis[node]=1;
        dfsVis[node]=1;
        
        for(auto it: graph[node])
        {
            if(!vis[it])
            {
                if(checkCycle(it, graph, vis, dfsVis)) return true;
            }
            else if(dfsVis[it])
            {
                return true;
            }
        }
        dfsVis[node]=0;
        ans.push_back(node);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> graph(n);
        vector<int> vis(n,0), dfsVis(n,0), blank;
        bool flag=false;
        
        for(auto p: prerequisites)
        {
            graph[p[0]].push_back(p[1]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                if(checkCycle(i, graph, vis, dfsVis))
                {
                    return blank;
                }
            }
        }
 
        return ans;
    }
};