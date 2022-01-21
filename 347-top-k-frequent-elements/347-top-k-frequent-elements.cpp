class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count=0;
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        
        for(auto n : nums)
        {
            mp[n]++;
        }
        
        for(auto m : mp)
        {
            pq.push({m.second, m.first});
        }
        
        while(count!=k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        
        return ans;
        
    }
};