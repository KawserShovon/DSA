class Solution {
public:
void dfs(TreeNode *root, vector<string>&res, string psf)
{
    if(root->left == nullptr and root->right == nullptr)
    {
        psf = psf + to_string(root->val);
        res.push_back(psf);
      
        return;
    }

    psf = psf + to_string(root->val)+"->";
   
    if(root->left != nullptr)
    {
      dfs(root->left,res,psf);  
    }
    
    if(root->right != nullptr)
    {
      dfs(root->right,res,psf);  
    }
    
}

vector<string>binaryTreePaths(TreeNode *root)
{
    vector<string> res;
   
    dfs(root,res,"");

    return res;
}
};