class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            mpp[nums[i]]++;
        }
        
        int count=0;
        
        for(auto m: mpp)
        {
            if(m.second > n/2)
                return m.first;
        }
        
        return -1;
    }
};