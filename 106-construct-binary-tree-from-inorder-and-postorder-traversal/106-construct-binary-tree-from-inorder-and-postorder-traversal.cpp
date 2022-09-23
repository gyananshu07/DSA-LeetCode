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
     TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd,  unordered_map<int, int> &inMap)
    {
        if(postStart>postEnd || inStart>inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart; //returns no. of element in left [9 3 15 20] -> [3] {root} -> {No of element in left =         1}
        
        root->left = buildTree(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, inMap); //check for left in inorder and update value accordingly
        
        root->right = buildTree(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd, inMap); //check for right from root+1 && preOrder Start should be current root+numsLeft+1
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap; //tracks inorder
        
        for(int i=0; i< inorder.size(); i++)
        {
            inMap[inorder[i]] = i; //Inorder with current posi
        }
        
        
        TreeNode* root = buildTree(postorder, 0, postorder.size()-1, inorder, 0,  inorder.size()-1, inMap);
        
        return root;
    }
};