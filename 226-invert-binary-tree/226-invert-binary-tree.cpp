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
    TreeNode* postorder(TreeNode* node)
    {
        if(node==NULL) return NULL;
    
        swap(node->left, node->right);
        postorder(node->left);
        postorder(node->right);

        return node;
    }
    
    
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        return postorder(root);
        
    }
};