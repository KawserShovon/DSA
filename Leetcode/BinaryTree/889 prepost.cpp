
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


TreeNode* buildTreeHelper(vector<int>&preorder,int preStart, int preEnd, vector<int>&postorder,int postStart, int postEnd)
{
    if(preStart>preEnd) return nullptr;

    TreeNode *root = new TreeNode(preorder[preStart]);

    if(preStart == preEnd) return root;

    int postIndex = postStart;
    while(postorder[postIndex] != preorder[preStart+1])
    {
        postIndex++;
    }

    int len = postIndex-postStart+1;
    root->left = buildTreeHelper(preorder,preStart+1,preStart+len, postorder, postStart,postIndex);
    root->right = buildTreeHelper(preorder,preStart+len+1,preEnd,postorder,postIndex+1,postEnd-1);
    return root;
}

TreeNode* constructFromPrePost(vector<int> &preorder, vector<int>&postorder)
{
    return buildTreeHelper(preorder,0,preorder.size()-1,postorder, 0, preorder.size()-1);
}

int main()
{
    file_in_out();

    int n;
    cin>>n;
    
    vi pre(n);
    vi post(n);
    
    REP(i,0,n){cin>>post[i];}
    REP(i,0,n){cin>>pre[i];}
    TreeNode* root = constructFromPrePost(pre,post);
    
    display(root);
}




