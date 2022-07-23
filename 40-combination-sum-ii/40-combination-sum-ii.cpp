class Solution {
public:
    void recur(int ind, int tar, vector<int>& c, vector<vector<int>>& ans, vector<int>& ds){
        if(tar==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<c.size();i++){
            if(i>ind && c[i]==c[i-1]) continue;
            if(c[i]>tar) break;
            
            ds.push_back(c[i]);
            recur(i+1, tar-c[i], c, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        int n=c.size();
        vector<vector<int>> ans;
        vector<int> ds;
        recur(0, target, c, ans, ds);
        return ans;
    }
};