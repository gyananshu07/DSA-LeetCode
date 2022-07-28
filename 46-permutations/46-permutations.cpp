class Solution {
public:
    void f(int ind, int n, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind; i<nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            f(ind+1, n, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        f(0, nums.size(), nums, ans);
        return ans;
    }
};