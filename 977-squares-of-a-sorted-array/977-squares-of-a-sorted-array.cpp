class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int lo=0, hi=nums.size()-1;
        vector<int> ans(hi+1, 0);
        int index=nums.size()-1;
        
        while(lo<=hi)
        {
            if(nums[lo]*nums[lo] < nums[hi]*nums[hi])
            {
                ans[index] = nums[hi]*nums[hi];
                hi--;
            }
            
            else
            {
                ans[index] = nums[lo]*nums[lo];
                lo++;
            }
            
            index--;
        }
        
        return ans;
    }
};