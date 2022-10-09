class Solution {
public:
    bool solve(int mid, vector<int> arr, int d)
    {
        int sum = 0;
        int days = 1;
        for(int i: arr)
        {
            if(sum + i <= mid)
            {
                sum += i;
            }
            else
            {
                sum = i;
                days++;
            }
        }
        if(days<=d)
            return true;
        
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0, ans;
        for(int w: weights)
        {
            low = max(low, w);
            high += w;
        }
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(solve(mid, weights, days))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;  
    }
};