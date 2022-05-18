class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0]; //as i<j so we can get max values at each index and calclulate for i+1
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            ans=max(ans,prev+nums[i]-i); // main equation (nums[i]+i) +(nums[j]-j)
            prev=max(prev,nums[i]+i); // maximum prev update to use it in next iterations
        }
        return ans;
    }
};