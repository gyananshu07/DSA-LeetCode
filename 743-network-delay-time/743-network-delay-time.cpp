class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<vector<pair<int, int>>> graph(n+1);
//         vector<int> distance(n, INT_MAX), vis(n,0);
//         int answer=INT_MIN;
//         queue<int> q;
        
//         for(auto t: times)
//         {
//             graph[t[0]].push_back({t[1], t[2]});
//         }
        
//         distance[k]=0;
//         q.push(k);
        
//         while(!q.empty())
//         {
//             int t=q.front();
//             q.pop();
//             for(auto it: graph[t])
//             {
//                 if(distance[it.first]>distance[t]+it.second)
//                 {
//                     distance[it.first]=distance[t]+it.second;
//                     q.push(it.first);
//                 }
//             }
//         }
    
//         for(int i=1; i<=n; i++)
//         {
//            answer = max(answer, distance[i]);
//         }
        
//         return answer==INT_MAX ? -1 : answer;
         vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++)
                adj[times[i][0]].push_back({times[i][1],times[i][2]});
        vector<int> dist(n+1,INT_MAX);
        queue<int> q;
        q.push(k);
        dist[k]=0;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(pair<int,int> it:adj[t])
            {
                if(dist[it.first]>dist[t]+it.second)
                {
                    dist[it.first]=dist[t]+it.second;
                    q.push(it.first);
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            res=max(res,dist[i]);
        }
        return res;
    }
    
};