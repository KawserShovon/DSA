
// Maximum Width Of Binary Tree

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



int widthOfBinaryTree(TreeNode* root)
{
    if(root == nullptr) return 0;
   int mx = 0;

    //tracking the node number also (2*i+1) = left , (2*i+2)=right
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});

    int leftMax = root->val;
    int rightMax = root->val;

    while(q.size()>0)
    {
        int size = q.size();
        int mmin = q.front().second; //to avoid overflow
        for(int i=0; i<size; i++)
        {
           // subtraction of mmin is not necessary 
            int cur_id = q.front().second-mmin;
            TreeNode* node = q.front().first;
            q.pop();

            if(i==0)
            {
                leftMax = cur_id; 
            }

            if(i==size-1)
            {
                rightMax = cur_id;
            }

            if(node->left)
            {
                q.push({node->left,(long long)cur_id*2+1});
            }

            if(node->right)
            {
                q.push({node->right, (long long)cur_id*2+2});
            }
        }

        mx = max(mx,rightMax-leftMax+1);
    }
    return mx;
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

    cout<<widthOfBinaryTree(root)<<endl;



}















