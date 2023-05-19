
//Construct Binary Search Tree FromInOrder Traversal
//https://www.youtube.com/watch?v=UAsLKuEMhsQ&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=16&ab_channel=Pepcoding
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


TreeNode* dfs(vector<int> &in, int start, int end)
{
    if(start>end)
    {
        return nullptr;
    }

    int mid = start+ (end-start)/2;

    TreeNode* root = new TreeNode(in[mid]);
    root->left = dfs(in,start,mid-1);
    root->right = dfs(in,mid+1,end);

    return root;
}

TreeNode* BSTfromInorder(vector<int> &in)
{
    return dfs(in,0,in.size()-1);
}

int main()
{
    //file_in_out();

    int n;
    cin>>n;
    
    vi in(n);
    
    REP(i,0,n){cin>>in[i];}

    TreeNode* root = BSTfromInorder(in);
    
    display(root);
}




