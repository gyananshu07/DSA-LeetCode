class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        vector<int> result;
        
        for(int i=0; i<nums1.size(); i++)
        {
            s1.insert(nums1[i]);
        }
        
        for(int i=0; i<nums2.size(); i++)
        {
             s2.insert(nums2[i]);
        }
        
        for(auto j: s1)
        {
            if(s2.find(j)!=s2.end())
            {
                result.push_back(j);
            }
        }
        
        return result;
    }
};