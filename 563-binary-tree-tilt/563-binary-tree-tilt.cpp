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
    int recursive(TreeNode* root, int &sum)
    {
        if(root==NULL) return 0;
        
        int lh = recursive(root->left, sum);
        int rh = recursive(root->right, sum);
        sum+=abs(rh-lh);
        
        return lh+rh+root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int sum=0;
        
        recursive(root, sum);
        
        return sum;
    }
};