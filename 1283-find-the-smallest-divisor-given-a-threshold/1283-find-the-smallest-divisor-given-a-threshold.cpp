class Solution {
public:
    int calculate(vector<int> nums, int div)
    {
        int sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=(nums[i]/div);
            
            if(nums[i] % div !=0)
            {
                sum++;
            }
        }
        
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1, hi=*max_element(nums.begin(), nums.end());
        int ans=hi;
        
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            int sum = calculate(nums, mid);
            
            if(sum<=threshold)
            {
                ans=mid;
                hi=mid-1;
            }
            
            else
            {
                lo=mid+1;
            }
        }
        
        return ans;
    }
};