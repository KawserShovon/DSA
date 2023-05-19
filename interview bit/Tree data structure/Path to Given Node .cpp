 bool nodeToRootPathHelper(TreeNode* root, int data,vector<int>&ans)
 {
     if(root == nullptr) return false;
     if(root->val == data) 
     {
         ans.push_back(root->val);
         return true;
     }
     bool res = nodeToRootPathHelper(root->left,data,ans) or nodeToRootPathHelper(root->right,data,ans);
     if(res)
     {
         ans.push_back(root->val);
     }
     
     return res;
 }
 
vector<int> Solution::solve(TreeNode* root, int data) {
    
    vector<int>ans;
    nodeToRootPathHelper(root,data,ans);
    reverse(ans.begin(),ans.end());
    return ans;

}
