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
    int cnt = 0;
    pair<int, int> solve(TreeNode* root){
        if(root == NULL) return {0, 0};
        if(root -> left == NULL && root -> right == NULL) {
            cnt++;
            return {root -> val, 1};
        }
        
        pair<int, int> left = solve(root -> left);
        pair<int, int> right = solve(root -> right);

        if((left.first + right.first + root->val)/(left.second + right.second + 1) == root->val) cnt++;
        return {left.first + right.first + root->val, left.second + right.second + 1};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return cnt;
    }
};