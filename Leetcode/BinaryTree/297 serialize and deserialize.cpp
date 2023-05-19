
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

int Idx = 0;
TreeNode* buildTree(vector<int>&arr)
{
    if(arr[Idx]==-1 or Idx==arr.size())
    {
        Idx++;
        return nullptr;
    }

    TreeNode *root = new TreeNode(arr[Idx++]);
    root->left = buildTree(arr);
    root->right = buildTree(arr);
    return root;

}

//inorder traversal
void serialize_(TreeNode *root, string &ans)
{
    if(root==nullptr)
    {
        ans += ("-1001");
        ans +=" ";
        return;
    }

    ans +=to_string(root->val)+" ";

    serialize_(root->left,ans);
    serialize_(root->right,ans);
}

string serialize(TreeNode *root)
{
    string ans="";
    serialize_(root,ans);
    return ans;
}




//just like build tree
int idx = 0;

TreeNode* deserialize_(vector<int> &dstr)
{
    if(idx == dstr.size())
    {
        return nullptr;
    }
    if(dstr[idx]==-1001 )
    {
        idx++;
        return nullptr;
    }
  
    TreeNode *root = new TreeNode(dstr[idx++]);
    root->left = deserialize_(dstr);
    root->right = deserialize_(dstr);
    return root;
}

TreeNode* deserialize(string s)
{
   vector<int> tstr ;
   for(int i=0,j=0; i<s.length(); i++)
   {
        if(s[i]==' ')
        {
            string t = s.substr(j,i-j+1);
            j=i;
            tstr.push_back(stoi(t));
        }
        else if(i==s.length()-1)
        {
            string t = s.substr(j,i-j);
            tstr.push_back(stoi(t));
        }
   }


    return deserialize_(tstr);
}

int main()
{
    file_in_out();

    int n;
    cin>>n;
    
    vi level(n);
    
    REP(i,0,n){cin>>level[i];}

    TreeNode* root = buildTree(level);
    string t = serialize(root);

    // root = deserialize(t);
    // display(root);
    display(deserialize(t));
}