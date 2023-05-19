
//5 cases (considering each node as root)
//1.include the root,left,right
//2.from left side upto root
//3.from right side upto root
//4.only the root
//5.max (only left,only right)
pairSum maxPathSumbetweenAny2Nodes(TreeNode* root)
{
    if(root == nullptr)
    {
        pairSum p =  pairSum(INT_MIN,0);
        return p;
    } 

    pairSum lp = maxPathSumbetweenAny2Nodes(root->left);
    pairSum rp = maxPathSumbetweenAny2Nodes(root->right);

    pairSum myAns = pairSum();
    int RTN_maxSum = max({lp.RTN_MaxSum,rp.RTN_MaxSum,0})+root->val;
    int NTN_maxSum = max({lp.NTN_MaxSum,rp.NTN_MaxSum,lp.RTN_MaxSum+root->val+rp.RTN_MaxSum,RTN_maxSum});

    myAns.RTN_MaxSum = max(RTN_maxSum,root->val);
    myAns.NTN_MaxSum = NTN_maxSum;

    return myAns;

}

int maxPathSum(TreeNode* root)
{
    if(root == nullptr) return 0;
    return maxPathSumbetweenAny2Nodes(root).NTN_MaxSum;
}