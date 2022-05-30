class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans;
        
        for(int i = 0 ; i <= n ; i++)
        {    
            if(!binary_search(nums.begin(), nums.end(), i))
            {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};