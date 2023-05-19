
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


TreeNode* bstFromLevelorder(vector<int>&level)
{
    if(level.size()==0)
    {
        return nullptr;
    }

    TreeNode* root = new TreeNode(level[0]);

    vector<int>left,right;
    for(int i=1;i<level.size(); i++)
    {
        if(level[i]<level[0])
        {
            left.push_back(level[i]);
        }
        else
        {
            right.push_back(level[i]);
        }
    }

    root->left = bstFromLevelorder(left);
    root->right = bstFromLevelorder(right);

    return root;
}

int main()
{
    file_in_out();

    int n;
    cin>>n;
    
    vi level(n);
    
    REP(i,0,n){cin>>level[i];}

    TreeNode* root = bstFromLevelorder(level);
    
    display(root);
}


















