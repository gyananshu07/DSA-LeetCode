class Solution {
public:
    void combination(int currIndex, int target, vector<int>& candidates, vector<int> &ds, vector<vector<int>>& ans){
        if(target==0)
        {
            ans.push_back(ds);
             return;
        }
           
        for(int i=currIndex; i<candidates.size(); i++)
        {
            if(i>currIndex && candidates[i] == candidates[i-1]) continue;
            if(target < candidates[i])
            {
                break;
            }
                
            ds.push_back(candidates[i]);
            combination(i+1, target-candidates[i], candidates, ds, ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> currComb;
        combination(0, target, candidates, currComb, ans);
        return ans;
    }
};