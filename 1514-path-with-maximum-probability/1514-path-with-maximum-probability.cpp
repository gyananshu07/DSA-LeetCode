class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0);
        
         for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }
        
        pq.push({1.0, start});
        maxProb[start]=1;
        
        while(!pq.empty())
        {
            int currNode=pq.top().second;
            double currProb=pq.top().first;
            pq.pop();
            
            for(auto it: graph[currNode])
            {
                if((currProb*it.second) > maxProb[it.first])
                {
                    maxProb[it.first] = currProb*it.second;
                    pq.push(make_pair(maxProb[it.first], it.first));
                }
            }
        }
        
        return maxProb[end]; 
    }
};

