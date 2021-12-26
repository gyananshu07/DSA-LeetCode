class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, maximum=INT_MIN;
        
        for(int i=0; i<nums.size(); i++)
        {
           if(nums[i]==1)
           {
               count++;
           }
            else if(nums[i]==0)
            {
                count=0;
            }
            maximum = max(maximum,count);
        }
        
       return maximum;
    }
};