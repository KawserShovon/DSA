 
static int maxTime ;
//the burnTree fn is like printKLevelsDown fn
void burnTree(TreeNode* root, TreeNode* blockNode, int time)
{
    if(root == nullptr or root == blockNode) return;

    maxTime = max(maxTime,time);

    burnTree(root->left,blockNode,time+1);
    burnTree(root->right,blockNode,time+1);
}


int dfs(TreeNode* root, int firenode)
{
    if(root == nullptr) return -1;

    if(root->val == firenode)
    {
        burnTree(root,nullptr,0);
        return 1;
    }

    int leftTime = dfs(root->left,firenode);
    if(leftTime != -1)
    {
        burnTree(root,root->left,leftTime);
        return leftTime+1;
    }


    int rightTime = dfs(root->right,firenode);
    if(rightTime != -1)
    {
        burnTree(root,root->right,rightTime);
        return rightTime+1;
    }

    return -1;
}

int Solution::solve(TreeNode* root, int firenode) {
    maxTime = 0;
    dfs(root,firenode);
    return maxTime;
}
