class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,l,r;
        vector<pair<int,int>>v;
        vector<int>ans;
        
        for(i=0;i<nums.size();i++){
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        
        l=0,r=v.size()-1;
        
        while(l<r){
            if(v[l].first+v[r].first==target){
                ans.push_back(v[l].second);
                ans.push_back(v[r].second);
                break;
            }
            else if(v[l].first+v[r].first>target){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};