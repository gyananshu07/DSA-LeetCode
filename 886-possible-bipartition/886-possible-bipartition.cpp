class Solution
{
    public:
        
        bool bipartitionBFS(int node, vector<int> &dislike, vector<vector<int>> &graph)
        {
            queue<int> q;
            q.push(node);
            dislike[node]=0;
            
            while(!q.empty())
            {
                int front = q.front();
                q.pop();
                
                for(auto it: graph[front])
                {
                    if(dislike[it] == -1) //if no like/dislike is set->-1, if like->0, dislike->-1
                    {
                        dislike[it] = 1 - dislike[front]; // revrse if node was like change to dislike
                        q.push(it);
                    }
                    
                    else if(dislike[it] == dislike[front])
                    {
                        return false;
                    }
                }
            }
            
            return true;
        }
    
        bool possibleBipartition(int N, vector<vector<int>>& dislikes)
        {
            vector<vector<int>> graph(N+1);
            vector<int> dislike(N+1, -1);
            
            for(auto d: dislikes)
            {
                graph[d[0]].push_back(d[1]);
                graph[d[1]].push_back(d[0]);
            }
            
            for(int i=1; i<=N; i++)
            {
                if(dislike[i] == -1)  
                {
                    if(!bipartitionBFS(i, dislike, graph))
                    {
                        return false;
                    }
                }
            }
            
            return true;
        }
};