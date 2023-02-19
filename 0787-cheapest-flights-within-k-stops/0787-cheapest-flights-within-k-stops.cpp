class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
                
        vector<pair<int, int>> adj[n];
        
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int steps = it.first;
            int node = it.second.first;
            int time = it.second.second;
            
            if(steps>k) continue;
            
            for(auto adjNode : adj[node])
            {
                int curNode = adjNode.first;
                int curTime = adjNode.second;
                
                if(time + curTime < dist[curNode] && steps <= k)
                {
                    dist[curNode] = time + curTime;
                    q.push({steps+1, {curNode, time + curTime}});
                }
                    
            }
        }
        if(dist[dst] == 1e9) return -1;
        
        return dist[dst];
    }
};