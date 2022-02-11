class Solution {
public:
    vector<int> ans;
//     bool checkCycle(int node, vector<vector<int>>& graph,  vector<int> &vis,  vector<int> &dfsVis)
//     {
//         vis[node]=1;
//         dfsVis[node]=1;
        
//         for(auto it: graph[node])
//         {
//             if(!vis[it])
//             {
//                 if(checkCycle(it, graph, vis, dfsVis)) return true;
//             }
//             else if(dfsVis[it])
//             {
//                 return true;
//             }
//         }
//         dfsVis[node]=0;
//         ans.push_back(node);
//         return false;
//     }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> graph(n);
        vector<int> vis(n,0), indegree(n,0), blank;
        bool flag=false;
        queue<int> q;
        
        for(auto p: prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
            
        }
        
        int count=0;
 
        while(!q.empty())
        {
            int front=q.front();
            ans.push_back(front);
            q.pop();
            count++;
            
            for(auto it: graph[front])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        
        if(count!=n) return blank;
        return ans;
    }
};