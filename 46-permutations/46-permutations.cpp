class Solution {
public:
    void f(int n, vector<int>& nums, int freq[], vector<int>& ds, vector<vector<int>>& ans)
    {
        if(ds.size() == n)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<n; i++)
        {
            if(!freq[i])
            {
                //Pick
                ds.push_back(nums[i]);
                freq[i] = 1;
                f(n, nums, freq, ds, ans);  
                // Not-Pick
                ds.pop_back();
                freq[i] = 0;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        
        for(int i=0; i<nums.size(); i++) freq[i] = 0;
        
        f(nums.size(), nums, freq, ds, ans);
        return ans;
    }
};