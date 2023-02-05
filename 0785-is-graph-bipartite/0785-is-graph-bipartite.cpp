class Solution {
private:
    bool checkBipartite(int node, int col, vector<int>& color, vector<vector<int>>& graph)
    {
        color[node] = col;
        
        for(auto it: graph[node])
        {
            if(color[it] == -1)
            {
                color[it] = 1-color[node];
                if(checkBipartite(it, color[it], color, graph)==false)
                {
                    return false;
                }
            }
            else if(color[it] == color[node])
            {
                return false;
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
                if(checkBipartite(i, 0, color, graph) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};