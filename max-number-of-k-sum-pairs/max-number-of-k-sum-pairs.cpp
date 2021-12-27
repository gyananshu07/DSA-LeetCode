class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int lo=0, hi=nums.size()-1, count=0, sum=0;
        
        while(lo<hi)
        {
            sum = nums[lo]+nums[hi];
            if(sum==k)
            {
                count++;
                lo++;
                hi--;
            }
            else if(sum>k)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
        return count;
    }
};