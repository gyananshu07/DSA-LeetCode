class Solution {
public:
    int maxArea(vector<int>& height) {
        int areaMax=INT_MIN, lo=0, hi=height.size()-1, area=0;
        
        if(lo==(hi-1))
        {
            return min(height[lo], height[hi]);
        }
        
        while(lo<hi)
        {
            area = (hi-lo) * min(height[lo], height[hi]);
            areaMax = max(area, areaMax);
            
            if(height[lo]<=height[hi])
            {
                lo++;
            }
            else
            {
                hi--;
            }
            
        }
        return areaMax;
    }
};