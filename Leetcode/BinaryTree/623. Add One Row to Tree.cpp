TreeNode* addOneRow(TreeNode* root, int val, int depth)
{
    if(depth ==1)
    {
        TreeNode* node = new TreeNode(val);
        node->left = root;
        return node;
    }

    queue<TreeNode*>pq;
    queue<TreeNode*>cq;

    pq.push(root);

    while(depth-->2 and pq.size()>0)
    {   
        int size = pq.size();
        while(size-->0)
        {
            TreeNode* rem = pq.front();
            pq.pop();
            if(rem ->left != nullptr)
            {
                cq.push(rem->left);
            }

            if(rem->right != nullptr)
            {
                cq.push(rem->right);
            }
        }

        queue<TreeNode*>tmp = pq;
        pq = cq;
        cq = tmp;
    }

    while(pq.size()>0)
    {
        TreeNode* node = pq.front();
        pq.pop();
        TreeNode* l = node->left;
        TreeNode* r = node->right;

        node->left = new TreeNode(val);
        node->right = new TreeNode(val);

        node->left->left = l;
        node->right->right = r;

    }


    return root;
}