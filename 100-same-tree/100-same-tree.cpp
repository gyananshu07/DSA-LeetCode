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
    bool sameTree(TreeNode* p, TreeNode* q)
    {
        if(p == NULL || q == NULL) return p==q;
        
        return p->val == q->val && (sameTree(p->left, q->left) && sameTree(p->right, q->right));
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       return sameTree(p, q);
    }
};