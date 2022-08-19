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
    void helper(TreeNode *root, string str, vector<string>&st){
        if(!root->left && !root->right){
            st.push_back(str);
            return;
        }
        if(root->left){
            helper(root->left , str + "->" + to_string(root->left->val),st);
        }
         if(root->right){
            helper(root->right , str + "->" + to_string(root->right->val),st);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>st;
        if(root == NULL) return st;
        helper(root,to_string(root->val),st);
        return st;
    }
};