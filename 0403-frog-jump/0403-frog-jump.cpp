class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        unordered_set<int> stone_set;
        int N = stones.size();
        
        for(int stone: stones) 
            stone_set.insert(stone);
        
        set<pair<int, int>> visited;
        
        queue<pair<int, int>> q;
        q.push({stones[0], 1});
        pair<int, int> current;
        int stone, i;
            
        while(!q.empty()) {
            
            current = q.front();
            q.pop();
            
            if(current.first == stones[N-1])
                return true;
            
            stone = current.first + current.second;
            
            if(stone_set.find(stone) != stone_set.end()) {
                for(i=-1;i<2;i++) {

                    if(current.second+i != 0) {
                        if(visited.find({stone, current.second+i}) == visited.end()) {
                            visited.insert({stone, current.second+i});
                            q.push({stone, current.second+i});
                        }
                    }
                }
            }
        }
        
        return false;
        
    }
};