class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
       vector<int> Sum (nums.size(),0);
        for(int i=0; i<nums.size(); i++)
        {   
            if(i==0)
            {
              Sum[i]=nums[i];
            }
            else
            {
                Sum[i]=Sum[i-1]+nums[i];
            }
        }
        return Sum;
    }
};