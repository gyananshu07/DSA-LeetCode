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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        
        if(root == NULL) return ans;
        
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> level;
            int size = q.size();
            
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                
                level.push_back(node->val);
            }
            long sum = 0;
            double avg = 0.0;
           for(int i=0; i<level.size(); i++)
           {
               sum += level[i];
           }
            
            avg = double(sum)/double(level.size());
            ans.push_back(avg);
        }
        
        return ans;
    }
};