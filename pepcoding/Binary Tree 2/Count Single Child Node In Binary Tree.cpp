
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <list>
#include <queue>
#include <deque>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
#include <map>
#include<limits>
#include <cfloat>
#include <sstream>

#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vd vector<double>
#define vdll vector<long double>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPeq(i,a,b) for(int i=a; i<=b; i++)


using namespace std;

void file_in_out()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}



class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode()
    {
        val = 0;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
    }

    TreeNode(int val)
    {
        this-> val = val;
    }

    TreeNode(int val, TreeNode *left, TreeNode* right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};



int idx = 0;
TreeNode* buildTree(vector<int> &arr)
{
    if(idx == arr.size())
    {
        return nullptr;
    }

    if(arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[idx++]);
    root->left = buildTree(arr);
    root->right = buildTree(arr);

    return root;
}


//method -1 
 int cnt = 0;
void countExactlyOneChild_(TreeNode* root)
{

    if(root == nullptr or (root->left == nullptr and root->right==nullptr))
    {
        return ;
    }

    if(root->left ==nullptr or root->right == nullptr)
    {
        cnt++;
    }
    
    countExactlyOneChild_(root->left);
   countExactlyOneChild_(root->right);

   
}




// method -2 
int countExactlyOneChild(TreeNode *root)
{

    if(root == nullptr or (root->left == nullptr and root->right==nullptr))
    {
        return 0;
    }


    int left = countExactlyOneChild(root->left);
    int right = countExactlyOneChild(root->right);
    int ans = left + right;

    if(root->left == nullptr or root->right==nullptr)
    {
        ans++;
    }
    return ans;
}



int main()
{
    file_in_out();

    
    int n;
    cin>>n;
    vector<int> arr(n);
    REP(i,0,n){cin>>arr[i];}   
    int data; 
    cin>>data;

    TreeNode *root = buildTree(arr);

    
    cout<<countExactlyOneChild(root);
    
  

}
