class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        queue<pair<int, int>> q;
        q.push({k, 0});
        
        vector<pair<int, int>> adj[n+1];
        
        for(auto time : times)
        {
            adj[time[0]].push_back({time[1], time[2]});
        }
        
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int node = it.first;
            int time = it.second;
            
            for(auto adjNode : adj[node])
            {
                int curNode = adjNode.first;
                int curTime = adjNode.second;
                
                if(curTime + time < dist[curNode])
                {
                    dist[curNode] = curTime + time;
                    q.push({curNode, curTime + time});
                }
            }
        }
        
        int res = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            if(dist[i] == 1e9) return -1;
            res=max(res, dist[i]);
        }
        
        return res;
    }
};