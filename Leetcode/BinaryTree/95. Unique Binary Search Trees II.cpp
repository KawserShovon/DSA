
 vector<TreeNode*> generateTreesHelper(int st, int end)
 {
    if(st>end)
    {
        vector<TreeNode*> base ;
        return base;
    }
    
    vector<TreeNode*> ans;
    for(int i=st; i<=end; i++)
    {
        vector<TreeNode*> left = generateTreesHelper(st,i-1);
        vector<TreeNode*> right = generateTreesHelper(i+1,end);
        for(TreeNode* l:left)
        {
            for(TreeNode* r:right)
            {
                TreeNode* root =new TreeNode(i);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }

    return ans;
 }
   
 vector<TreeNode*> generateTrees(int n)
 {
    return generateTreesHelper(1,n);
 }
