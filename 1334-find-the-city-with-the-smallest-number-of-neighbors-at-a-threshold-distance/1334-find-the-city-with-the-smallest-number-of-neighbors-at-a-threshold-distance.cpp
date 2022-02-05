class Solution {
public:
    void djakstra(int n, int source, vector<pair<int, int>> graph[], int distanceThreshold, vector<int> &citiesCount)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> dist(n, INT_MAX);
        
        dist[source]=0;
        pq.push({0, source}); //weight & node
        
        while(!pq.empty())
        {
            int distInt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it: graph[node])
            {
                int next=it.first;
                int nextDist=it.second;
                if(dist[next] > distInt+nextDist)
                {
                    dist[next]=distInt+nextDist;
                    pq.push({dist[next], next});
                }
            }
        }
        
        int count = 0;
        for(int j = 0; j < n; j++){
            if(source != j && dist[j] <= distanceThreshold)  count++;
        }
        
        citiesCount.push_back(count);
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> graph[n];
        vector<int> citiesCount;
        
        for(auto e: edges)
        {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        
        for(int i=0; i<n; i++)
        {
            djakstra(n, i, graph, distanceThreshold, citiesCount);
        }
        
        int minCities = INT_MAX;
        int ans=0;
        for(int i = 0; i<citiesCount.size(); i++){
            if(citiesCount[i] <= minCities){
                minCities = citiesCount[i];
                ans = i;
            }
        }
        
         return ans;
    }
};