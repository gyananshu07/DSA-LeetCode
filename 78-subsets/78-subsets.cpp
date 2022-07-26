class Solution {
public:
    void f(int i, int n, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans)
    {
        if(i == n)
        {
            ans.push_back(ds);
            return;
        }
        
//         Pick
        ds.push_back(nums[i]);
        f(i+1, n, nums, ds, ans);
        
//         Not-Pick
        ds.pop_back();
        f(i+1, n, nums, ds, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0, nums.size(), nums, ds, ans);
        return ans;
    }
};