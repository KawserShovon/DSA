
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
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};




void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

static int idx = 0;
TreeNode* bstFromPreorder(vector<int>&preorder, int lr, int rr)
{
    if(idx >=preorder.size() or preorder[idx]<lr or preorder[idx]>rr)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[idx++]);
    root->left = bstFromPreorder(preorder,lr,root->val);
    root->right = bstFromPreorder(preorder,root->val,rr);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder)
{
    int n = preorder.size();
    int lr = INT_MIN;
    int rr = INT_MAX;

    return bstFromPreorder(preorder,lr,rr);
}

int main()
{
    file_in_out();

    int n;
    cin>>n;
    
    vi pre(n);
    
    REP(i,0,n){cin>>pre[i];}

    TreeNode* root = bstFromPreorder(pre);
    
    display(root);
}













