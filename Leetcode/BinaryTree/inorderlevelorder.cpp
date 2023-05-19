
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


TreeNode* buildTreeHelper(vector<int>&inorder, vector<int>&levelorder,int si, int ei)
{
    if(si>ei)
    {
        return nullptr;
    }
    
    set<int>inset;
    for(int i=si;i<=ei; i++)
    {
        inset.insert(inorder[i]);
    }

    vector<int>tmp;
    for(int i=0; i<levelorder.size(); i++)
    {
        if(inset.find(levelorder[i]) != inset.end())
        {
            tmp.push_back(levelorder[i]);
        }
    }
    

    TreeNode *root = new TreeNode(tmp[0]);


    // tmp.clear();
    // inset.clear();

    int inIdx;
    for(int i=si; i<=ei; i++)
    {
        if(root->val == inorder[i])
        {
            inIdx = i;
            break;
        }
    }

    root->left = buildTreeHelper(inorder,levelorder,si,inIdx-1);
    root->right = buildTreeHelper(inorder,levelorder,inIdx+1,ei);
    
    return root;
}

TreeNode* buildTree(vector<int> &inorder, vector<int>&levelorder)
{
    return buildTreeHelper(inorder,levelorder,0,inorder.size()-1);
}

int main()
{
    file_in_out();

    int n;
    cin>>n;
    
    vi in(n);
    vi level(n);
    
    REP(i,0,n){cin>>in[i];}
    REP(i,0,n){cin>>level[i];}
    TreeNode* root = buildTree(in,level);
    
    display(root);
}




