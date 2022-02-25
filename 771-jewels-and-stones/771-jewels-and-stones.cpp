class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        unordered_map<char, int> mp;
        string temp = jewels + stones;
        
        for(auto t: temp)
        {
            mp[t]++;
        }
        
        for(auto m: mp)
        {
            if(m.second>=2 && find(jewels.begin(), jewels.end(), m.first) != jewels.end() && find(stones.begin(), stones.end(), m.first) != stones.end())
            {
                count = count + m.second-1;
            }
        }
        
        return count;
    }
};