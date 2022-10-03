class Solution {
public:
    TreeNode* buildBST(vector<int>& preorder,int& index,int lowerBound,int upperBound){
        if(index>=preorder.size()) return NULL;
        if(preorder[index]<lowerBound || preorder[index]>upperBound) return NULL;
        
        TreeNode* node=new TreeNode(preorder[index++]);
        node->left=buildBST(preorder,index,lowerBound,node->val);
        node->right=buildBST(preorder,index,node->val,upperBound);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return buildBST(preorder,index,INT_MIN,INT_MAX);
    }
};