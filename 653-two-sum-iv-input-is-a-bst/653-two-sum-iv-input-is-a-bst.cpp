class BSTIterator {
    stack<TreeNode*> st;
    //reverse is true => before (right)
    //reverse is false => next (left)
    bool reverse = true; //default
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
private:
    void pushAll(TreeNode* node) {
        for(; node != NULL;) {
            st.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }
};

class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        BSTIterator l(root, false); //next
        BSTIterator r(root, true); //before
        
        int i = l.next(); //inorder (left node right)
        int j = r.next(); //reverse inorder (right node left)
        
        while(i < j) {
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};