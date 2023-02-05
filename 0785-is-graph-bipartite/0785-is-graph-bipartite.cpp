class Solution {
private:
    bool checkBipartite(int node, vector<int>& color, vector<vector<int>>& graph)
    {
        queue<int> q;
        
        q.push(node);
        color[node] = 0;
        
        while(!q.empty()){
            int curNode = q.front();
            q.pop();
            
            for(auto it: graph[curNode])
            {
                if(color[it] == -1)
                {
                    color[it] = 1-color[curNode];
                    q.push(it);
                }
                else if(color[it] == color[curNode])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                if(checkBipartite(i, color, graph) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};