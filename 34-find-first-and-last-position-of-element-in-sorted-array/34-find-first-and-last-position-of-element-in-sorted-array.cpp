class Solution {
    
public:
    int index(vector<int> arr, int x, bool findStartValue)
    {
        int l=0, r=arr.size()-1, ans=-1;
        while (l <= r)
        {
        int m = l + (r - l) / 2;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else if(arr[m] > x)
            r = m - 1;
        
        // Check if x is present at mid
        else
        {
            ans=m;
            if(findStartValue)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        } 
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result={-1, -1}; 
        bool findStartValue=true;
        
        int start=index(nums, target, findStartValue=true);
        int end=index(nums, target, findStartValue=false);
        
        result[0]=start;
        result[1]=end;
        
        return result;
    }
};