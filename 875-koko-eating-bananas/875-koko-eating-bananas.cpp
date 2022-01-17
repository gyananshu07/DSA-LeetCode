class Solution {

public:
    int hoursRequired(vector<int> piles, int speed)
    {
        int cnt = 0;
        for(int c: piles)
        {
            cnt += c/speed + (c % speed != 0);
        }
        return cnt;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int ans = -1, low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int timeRequired = hoursRequired(piles, mid);		
            if(timeRequired <= H)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};