class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int m = (arr.size()-1)/2;
        sort(arr.begin(), arr.end());
        
        int median = arr[m], left=0, right=arr.size()-1, counter=0;
        vector<int> ans(k);
        
        
        while(counter<k){
            int leftValue = abs(arr[left]-median);
            int rightValue = abs(arr[right]-median);
            
            if(rightValue>=leftValue)
            {
                ans[counter] = arr[right];
                right--;
            }
            else
            {
                ans[counter] = arr[left];
                left++;
            }
            counter++;
        }
        
        return ans;
    }
};