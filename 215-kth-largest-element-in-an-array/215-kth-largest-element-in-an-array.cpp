class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(auto n : nums)
        {
            pq.push(n);
        }
        
        int n = nums.size(), ans=0, count=0 ;
        
        while(count!=k)
        {
            ans=pq.top();
            pq.pop();
            count++;
        }
        
        return ans;
    }
};