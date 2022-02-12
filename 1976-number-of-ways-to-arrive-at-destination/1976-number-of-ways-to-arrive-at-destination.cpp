class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = (1e9+7);
        long long maxi = LONG_MAX;
        vector<long long> timeRec(n, maxi);
        vector<long long> ways(n, 0);
        vector<pair<long long, long long>> graph[n];
        
        //Create a graph
        for(auto r: roads)
        {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        
        //Pushing Initial Node
        pq.push({0, 0});
        timeRec[0]=0;
        ways[0]=1;
        
        while(!pq.empty())
        {
            long long node = pq.top().second;
            long long time = pq.top().first;
            pq.pop();
            
            for(auto it: graph[node])
            {
                long long adjNode = it.first;
                long long timeAdjNode  = it.second;
                
                if(time + timeAdjNode < timeRec[adjNode])
                {
                    timeRec[adjNode] = time + timeAdjNode;
                    ways[adjNode] = ways[node];
                    pq.push({timeRec[adjNode], adjNode});
                }
                
                else if(time + timeAdjNode ==  timeRec[adjNode])
                {
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }
            }
        }
        
        return ways[n-1];
    }
};