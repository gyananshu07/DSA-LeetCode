class Solution {
public:
    void bfs(int i, vector<vector<int>>& rooms, vector<int>& vis)
    {
        queue<int> q;
        q.push(i);
        vis[i]=1;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it: rooms[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }   
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(), 0);
        
        bfs(0, rooms, vis);
        
        for(int i=0; i<rooms.size(); i++)
        {
            if(vis[i]==0)
            {
                return false;
            }
        }
        
        return true;
    }
};