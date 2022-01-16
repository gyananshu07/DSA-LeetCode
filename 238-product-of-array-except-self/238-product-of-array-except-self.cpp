class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> right(n,0);
        int prod=1;
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            prod*=nums[i];
            right[i]=prod;
        }
        
        prod=1;
        vector<int> ans(n,0);
        
        for(int i=0; i<nums.size()-1; i++)
        {
            int lp=prod;
            int rp=right[i+1];
            
            prod*=nums[i];
            ans[i]=rp*lp;
        }
        
        ans[n-1]=prod;
        return ans;
    }
};