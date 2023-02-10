class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        
        vector<int> adj[V];
        vector<int> vis(V, 0), topo, indegree(V, 0);
	    queue<int> q;
        
        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
	    
	    for(int i=0; i<V; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i=0; i<V; i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        topo.push_back(node);
	        
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    
        if(topo.size() == V)
        {
            return topo;
        }
        
	    return {};
    }
};