class Solution {
private:
    void combination(int currIndex, int k, vector<int>& arr, vector<int> &ds, vector<vector<int>>& ans){
        if(currIndex == arr.size())
        {
            if(ds.size() == k)
            {
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(arr[currIndex]);
        combination(currIndex+1, k, arr, ds, ans);
        
        ds.pop_back();
        combination(currIndex+1, k, arr, ds, ans);
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> currComb, arr;
        
        for(int i=0; i<n; i++)
        {
            arr.push_back(i+1);
        }
        
        combination(0, k, arr, currComb, ans);
        
        return ans;
    }
};