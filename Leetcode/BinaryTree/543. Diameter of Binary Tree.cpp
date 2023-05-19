
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


int height(TreeNode* root)
{
    if(root==nullptr) return -1; //considering edge

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight,rightHeight)+1;
  

}

//O(N^2)
int diameter(TreeNode* root)
{
    if(root == nullptr) return 0;

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    int lh = height(root->left);
    int rh = height(root->right);

    int mydiameter = lh+rh+2;

     return max(max(ld,rd),mydiameter);
}


//O(N)
//diameter, height
pair<int,int>diameter_02(TreeNode* root)
{
    if(root == nullptr) return {0,-1};

    pair<int,int> lpair = diameter_02(root->left);
    pair<int,int> rpair = diameter_02(root->right);

    pair<int,int>mydiameter;
    mydiameter.first = max(max(lpair.first,rpair.first),lpair.second+rpair.second+2);
    mydiameter.second = max(lpair.second,rpair.second)+1;
    return mydiameter;

}

int diameterOfBinaryTree(TreeNode* root)
{
//    int myans = diameter(root);
   pair<int,int> ans = diameter_02(root);
   int myans = ans.first;
   return myans;
}

int main()
{
    file_in_out();

    
    int n;
    cin>>n;
    vector<int> arr(n);
    REP(i,0,n){
    
    string s;
    cin>>s;

    if(s=="n")
    {
        arr[i] = -1;
    }
    else 
    {
        arr[i] = stoi(s);
    }
}   


    TreeNode *root = buildTree(arr);

    cout<<diameterOfBinaryTree(root);

  


}