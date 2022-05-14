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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=INT_MIN;
        height(root, diameter);
        return diameter-1;
    }
    
private:
    int height(TreeNode* root, int& diameter)
    {
        
        if(root==NULL) return 0;
        
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        
        int temp = 1+max(lh, rh);
        int ans = max(temp, lh+rh+1);
        diameter = max(diameter, ans);
        
        return 1+max(lh,rh);
    }
    
};