class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        int n = nums.size();
        
        for(auto it: nums)
        {
            mpp[it]++;
        }
        
        for(auto m: mpp)
        {
            if(m.second > n/3)
                ans.push_back(m.first); 
        }
        
        return ans;
    }
};