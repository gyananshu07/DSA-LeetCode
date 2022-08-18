class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = arr.size();
        priority_queue<pair<int, int>> pq;
        
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto m: mp)
        {
            pq.push({m.second, m.first});
        }
        int ans = 0;
        int val = 0;
        
        while(!pq.empty())
        {
            val += pq.top().first;
            pq.pop();
            ans++;
            if(n/2 <= val)
            {
               break;
            }
        }
        
        return ans;
    }
};