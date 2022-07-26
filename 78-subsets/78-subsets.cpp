class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size(), i=0;
        int x=1<<n;
        
        while(i<x)
        {
            vector<int> subset;
            for(int bit=0; bit<nums.size(); bit++)
            {
                if(i & (1<<bit))
                {
                    subset.push_back(nums[bit]);
                }
            }
            ans.push_back(subset);
            i++;
        }
           return ans; 
    }
};