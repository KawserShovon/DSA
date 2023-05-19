
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

template<typename T>
void display1d(T text)
{
    for(auto x:text)
    {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
}

template<typename T>
void display2d(std::vector<std::vector<T>> vec)
{
    for(auto x:vec)
    {
        for(auto y:x)
        {
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}


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



// int idx = 0;
// TreeNode* buildBinaryTree(vi arr)
// {
//     if(arr[idx] == -1)
//     {
//         idx++;
//         return nullptr;
//     }

//     TreeNode* node = new TreeNode(arr[idx++]);
//     node->left = buildBinaryTree(arr);
//     node->right = buildBinaryTree(arr);
//     return node ;
// }


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

int PreIndex = 0;

TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int is, int ie)
{
    if(is>ie) return nullptr;

    TreeNode* root = new TreeNode(preorder[PreIndex]);
    PreIndex++;

    int inIndex;
    for(int i=is; i<=ie; i++)
    {
        if(inorder[i]== root->val)
        {
            inIndex = i;
            break;
        }
    }

    root->left = buildTreeHelper(preorder,inorder,is,inIndex-1);
    root->right = buildTreeHelper(preorder,inorder,inIndex+1,ie);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    return buildTreeHelper(preorder,inorder,0,preorder.size()-1);
}  


int main()
{
    file_in_out();

    int n;
    cin>>n;
    vi pre(n);
    vi in(n);
    REP(i,0,n){cin>>pre[i];}
    REP(i,0,n){cin>>in[i];}

    TreeNode* root = buildTree(pre,in);
    
    display(root);
}




