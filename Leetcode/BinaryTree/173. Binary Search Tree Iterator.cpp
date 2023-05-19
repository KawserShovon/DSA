
class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        allLeft(root);
    }

    void allLeft(TreeNode* root)
    {
        while(root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode *node = st.top();
        st.pop();
        allLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return st.size() != 0;
    }
};