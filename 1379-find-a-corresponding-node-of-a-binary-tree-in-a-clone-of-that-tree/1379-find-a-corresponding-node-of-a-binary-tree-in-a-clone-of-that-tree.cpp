/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void f(TreeNode* root, TreeNode* target,TreeNode*& res){
        if(root==nullptr)
            return;
        if(root->val==target->val){
            res=root;
            return;
        }
        f(root->left,target,res);
        f(root->right,target,res);
            
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res=new TreeNode(-1);
        f(cloned,target,res);
        return res;
    }
};