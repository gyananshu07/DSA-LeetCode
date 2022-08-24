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
   int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int width = 0;
        queue<pair<TreeNode*,int>>qu;
        qu.push({root,0});
        
        while(!qu.empty()){
            int size = qu.size();
            int min_n_level = qu.front().second;
            int first,last;
            
            for(int i=0;i<size;i++){
                long curr_id = qu.front().second - min_n_level;//this is done to prevent overflow
                //which arries when tree is skwed
                
                TreeNode*node = qu.front().first;
                qu.pop();
                if(i==0) first = curr_id;//store first element;
                if(i==size-1) last = curr_id;//store last element and at last we ll subtraact it
                
                if(node->left) qu.push({node->left,curr_id*2+1});
                if(node->right) qu.push({node->right,curr_id*2+2});
            }
            width = max(width,last-first+1);
        }
        return width;
        
    }
};