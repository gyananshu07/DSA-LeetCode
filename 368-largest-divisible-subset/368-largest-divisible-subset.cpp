class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n =  nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        
        int maxi = 1;
        int lastIndex = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
        {
            hash[i]=i;
            for(int prev=0; prev<i; prev++)
            {
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
                {
                    dp[i] = 1 + dp[prev];  //increase the count of IS
                    hash[i] = prev; //update the prev index in hash 
                }
            }
            
            if(dp[i]>maxi) //max of all IS length
            {
                maxi = dp[i];
                lastIndex = i;  //stores the max of index to iterate in the hash
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] !=lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        
        reverse(temp.begin(), temp.end());
        
        return temp;
        
    }
};