class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int i=0, count=0, k=0; 
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                count++;
                k = max(k, count);
            }
            else
                count=0;
        }
        
        return k;
    }
};