class Solution {
    void f(int i, int n, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans)
    {
        if(i >= n)
        {
            ans.push_back(ds);
            return;
        }
        
        //Pick
        ds.push_back(nums[i]);
        f(i+1, n, nums, ds, ans);

        //Not-Pick
        ds.pop_back();
        
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        
        f(i+1, n, nums, ds, ans);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        f(0, nums.size(), nums, ds, ans);
        return ans;
    }
};