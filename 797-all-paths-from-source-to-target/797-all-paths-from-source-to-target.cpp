class Solution {
public:
    vector<vector<int>> result;
    
    void dfs(int source, vector<vector<int>> graph, vector<int> &path)
    {
        path.push_back(source);
        
        if(source==graph.size()-1) result.push_back(path);
        else
        {
            for(auto it: graph[source])
            {
                dfs(it, graph, path);
            }
        
        }
        
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        
        dfs(0, graph, path);
        
        return result;   
    }
};