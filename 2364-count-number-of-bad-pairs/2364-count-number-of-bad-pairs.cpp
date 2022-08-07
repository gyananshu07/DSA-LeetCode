class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        long long pair_count = 0;
        long long n = nums.size();
        
        for(int i=0; i<nums.size(); i++)
        {
            pair_count += mpp[i-nums[i]]++;
        }
        
        return (long long)(n*(n-1)/2) - pair_count;
    }
};