vector<TreeNode*> helper(int n)
{
    if(n==1)
    {
        vector<TreeNode*> base;
        base.push_back(new TreeNode(0));
        return base;
    }

    vector<TreeNode*> ans;
    for(int i=1; i<n; i= i+2)
    {
        vector<TreeNode*> left =helper(i);
        vector<TreeNode*> right = helper(n-i-1);
        for(TreeNode* l:left)
        {
            for(TreeNode* r:right)
            {
                TreeNode* root = new TreeNode(0);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }

    return ans;
}

vector<TreeNode*> allPossibleFBT(int n)
{

    return helper(n);

}

