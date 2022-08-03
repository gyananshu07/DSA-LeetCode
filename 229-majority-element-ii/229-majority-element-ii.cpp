class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i]==num1)
            {
                count1++;
            }
            
            else if(nums[i]==num2)
            {
                count2++;
            }
            
            else if(count1 == 0)
            {
                num1 = nums[i];
                count1++;
            }
            
            else if(count2 == 0)
            {
                num2 = nums[i];
                count2++;
            }
            
            else{
                count1--;
                count2--;
            }
        }
        
        int cnt1 = 0, cnt2 = 0;
        for(auto i : nums){
            if(i == num1)
                cnt1++;
            else if(i == num2)
                cnt2++;
        }
        
        if(cnt1 > (n/3))
            ans.push_back(num1);
        if(cnt2 > (n/3))
            ans.push_back(num2);
        
        return ans;
    }
};