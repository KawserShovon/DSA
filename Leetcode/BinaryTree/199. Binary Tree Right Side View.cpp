


//right view of binary tree
//199. Binary Tree Right Side View
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






void rightview(TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);

    while(q.size()>0)
    {
        int count = q.size();
        for(int i=0; i<count; i++)
        {
            TreeNode *node = q.front();
            if(i==count-1)
            {
               cout<<node->val<<" "; 
            }
            
            q.pop();

            if(node->left != nullptr)
            {
                q.push(node->left);
            }

            if(node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        cout<<endl;

    }
}


vector<int> rightSideView(TreeNode* root)
{
    vector<int> ans;
    if(root==nullptr) return ans;

    queue<TreeNode*> q;
    q.push(root);


    while(q.size()>0)
    {
        int count=q.size();

        for(int i=0; i<count; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node != nullptr and i==count-1)
            {
                ans.push_back(node->val);
            }

            if(node != nullptr and node->left != nullptr)
            {
                q.push(node->left);
            }


            if(node != nullptr and node->right != nullptr)
            {
                q.push(node->right);
            }
        }
    }

    return ans;
}

void display(TreeNode* node) {
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->val) : ".";
  str += " <- " + to_string(node->val) + " -> ";
  str += node->right != nullptr ? to_string(node->right->val) : ".";
  cout << str << endl;
  display(node->left);
  display(node->right);
}

int main()
{
    file_in_out();

    int n;
    cin>>n;
    vector<int> arr(n);

    REP(i,0,n){cin>>arr[i];}


    TreeNode *root = buildTree(arr);

    rightview(root);



}
