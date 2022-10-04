/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    void helper(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        helper(root->left);
        mp[root->val]++;
        helper(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;       
        
        helper(root);
        
        int maxValue = INT_MIN;
        
        for(auto m: mp)
        {                                        
            if(maxValue < m.second)              // for loop to find maxValue of freq. of occurence
            {
                maxValue = m.second;
            }
        }
		
        for(auto m: mp)
        {                                       // for loop to find element value and push to ans
            if(m.second == maxValue)
            {
                ans.push_back(m.first);
            }
        }
        
        return ans;
    }
};