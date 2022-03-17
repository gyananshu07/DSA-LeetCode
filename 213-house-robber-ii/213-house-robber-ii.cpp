class Solution {
private:
int helpFun(vector<int>& nums1)
{
    int n =  nums1.size();
        
        int prev = nums1[0];
        
        int prev2 = 0;
        
        for(int i=1; i<n; i++)
        {
            int take = nums1[i];
            if(i>1)
            {
                take += prev2;
            }
            
            int nonTake = 0 + prev;
            
            int curr_i = max(take, nonTake);
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
}
public:
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();
        
        if(n==1) return nums[0];
        
        for(int i=0; i<n; i++)
        {
            if(i!=0) temp1.push_back(nums[i]); //except first element
            if(i!=n-1) temp2.push_back(nums[i]); //except last element
        }
        
        return max(helpFun(temp1), helpFun(temp2)); //ans will be mx of both
    }
};