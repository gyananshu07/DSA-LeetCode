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

    void recursive(TreeNode* node, int& sum, int depth, int deepest)
    {
        if(node==NULL) return;
        
        if(depth==deepest)
        {
            sum+=node->val;
        }
        
        recursive(node->left, sum, depth+1, deepest);
        recursive(node->right, sum, depth+1, deepest);
    }
    
    int maxDepth(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        
        return 1+max(lh, rh);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int deepest=maxDepth(root);
        recursive(root, sum,1, deepest);
        
        return sum;
    }
};