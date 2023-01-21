class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        
        for(auto n1: nums1)
        {
            mp[n1]++;
        }
        
        int ans = INT_MAX;
        
        for(auto it: nums2)
        {
            if(mp[it]>0)
            {
               ans = min(ans, it);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};