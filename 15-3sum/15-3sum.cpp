class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>>ans;
        int n = nums.size();
        
        //sorting the array
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++) {
            int first = nums[i];
            int target = -first;
            
            int start = i+1, end = n-1;
            while(start<end) {
                int sum = nums[start]+nums[end];
                if(sum == target) {
                    ans.push_back({nums[i],nums[start],nums[end]});
                    while(start < end && nums[start+1] == nums[start]) start++;
                    while(start < end && nums[end-1] == nums[end]) end--;
                    start++;
                    end--;
                } else if(sum > target) {
                    end--;
                } else {
                    start++;
                }
            }
            
            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        
        return ans;
    }
};