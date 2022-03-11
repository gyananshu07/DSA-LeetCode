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
    int countGoodNodes(TreeNode* root, int maxi)
    {
        if(root==NULL)
            return 0;
        
        int count=0;
        if(root->val>=maxi)
        {
            maxi = root->val;
            count++;
        }
        
        return count+countGoodNodes(root->left, maxi)+countGoodNodes(root->right, maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        
        return countGoodNodes(root, root->val);
    }
};