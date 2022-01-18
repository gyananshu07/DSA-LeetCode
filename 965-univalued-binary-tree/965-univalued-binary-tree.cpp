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
private:
    bool inorder(TreeNode* node, int value)
    {
        if(node==NULL) return true;
        
        if(node->val!=value) return false;
        bool lh = inorder(node->left, value);
        bool rh = inorder(node->right, value);
        
        return (lh&&rh);
    }
    
public:
    bool isUnivalTree(TreeNode* root) {
        int value=root->val;
        
        return inorder(root, value);
    }
};