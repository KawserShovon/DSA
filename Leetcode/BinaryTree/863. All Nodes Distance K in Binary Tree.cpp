/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

        vector<TreeNode*> FindnodeTorootpath(TreeNode* root, int data)
{
    if(root == nullptr)
    {
        vector<TreeNode*>base;
        return base;
    }

    if(root->val == data)
    {
        vector<TreeNode*> ans;
        ans.push_back(root);
        return ans;
    }

    vector<TreeNode*> left = FindnodeTorootpath(root->left,data);
    if(left.size() !=0)
    {
        left.push_back(root);
        return left;
    }

    vector<TreeNode*> right = FindnodeTorootpath(root->right,data);
    if(right.size() !=0)
    {
        right.push_back(root);
        return right;
    }

    vector<TreeNode*>base;
    return base;

    
}


void printKLevelsDown(TreeNode* root, int k, TreeNode* blocker,vector<int>&ans)
{
    if(root == nullptr or k<0 or root == blocker)
    {
        return;
    }

    if(k==0)
    {
        // cout<<root->val<<endl;
        ans.push_back(root->val);
    }

    printKLevelsDown(root->left,k-1,blocker,ans);
    printKLevelsDown(root->right,k-1,blocker,ans);
}



vector<int> distanceK(TreeNode* root,TreeNode* val, int k)
{
    int data = val->val;
    vector<int>ans;

    vector<TreeNode*> path = FindnodeTorootpath(root,data);
    for(int i=0; i<path.size(); i++)
    {
        TreeNode *blocker;
        if(i==0)
        {
            blocker = nullptr;
        }
        else 
        {
            blocker = path[i-1];
        }
        printKLevelsDown(path[i],k-i,blocker,ans);
    }

    return ans;
}

    
};