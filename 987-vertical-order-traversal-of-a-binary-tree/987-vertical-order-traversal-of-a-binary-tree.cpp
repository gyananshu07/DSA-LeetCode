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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp; // x, y, node->val
        queue<pair<TreeNode*, pair<int, int>>> q; //q(node, vertical level, horizontal level )
        
        q.push({root, {0,0}}); // pushing root element with x & y as 0,0
        
        //Level order Traversal
    
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            TreeNode*  node = p.first;
            int x=p.second.first, y=p.second.second;
            mp[x][y].insert(node->val);
            
            // Check left & right of nodes and push accordingly
            if(node->left)
            {
                q.push({node->left, {x-1, y+1}});
            }
            
            if(node->right)
            {
                q.push({node->right, {x+1, y+1}});
            }
            
        }
        
        vector<vector<int>> ans;
        
        for(auto m: mp)
        {
            vector<int> col;
            for(auto am: m.second)
            {
                col.insert(col.end(), am.second.begin(), am.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};