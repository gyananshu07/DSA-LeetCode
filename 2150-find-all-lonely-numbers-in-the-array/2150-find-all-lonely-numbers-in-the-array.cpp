class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto n: nums)
        {
            if(mp[n]==1 && mp.count(n-1)==0 && mp.count(n+1)==0)
            {
                ans.push_back(n);
            }
        }
        
        return ans;
    }
};