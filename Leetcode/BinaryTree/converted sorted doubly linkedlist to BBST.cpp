
//Convert Sorted Doubly Linked List To Binary Search Tree
// https://www.youtube.com/watch?v=aluZgmD0b44&list=PL-Jc9J83PIiF5VDJpx6ZIgE7CaPY0RT0J&index=36&ab_channel=Pepcoding

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



TreeNode* constructFromInorder(vector<int>&arr, int si, int ei)
{
    if(si>ei) return nullptr;

    int mid = si + (ei-si)/2;

    TreeNode* root = new TreeNode(arr[mid]);
    root->left = constructFromInorder(arr,si,mid-1);
    root->right = constructFromInorder(arr,mid+1,ei);

    return root;
}

TreeNode* constructFromInorder(vector<int> &arr)
{
    return constructFromInorder(arr,0,arr.size()-1);
}




TreeNode* getMidNode(TreeNode* node)
{
    if(node == nullptr or node->right ==nullptr)
    {
        return node;
    }

    TreeNode *fast = node;
    TreeNode *slow = node;

    while(fast->right != nullptr and fast->right->right != nullptr)
    {
        slow = slow->right;
        fast = fast->right->right;
    }

    return slow;
}

TreeNode* sortedListToBST(TreeNode* head)
{
    if(head == nullptr or head->right == nullptr)
    {
        return head;
    }

    TreeNode *root = getMidNode(head);
    TreeNode *leftNode = head == root ? nullptr:head;
    TreeNode *rightNode = root->right;

    if(root->left != nullptr)
    {
        root->left->right = nullptr;
    }

    root->left = root->right = rightNode->left = nullptr;
    root->left = sortedListToBST(leftNode);
    root->right = sortedListToBST(rightNode);

    return root;
}


TreeNode* makeList(int n) 
{
    TreeNode* dummy = new TreeNode(-1);
    TreeNode* prev = dummy;
    while (n-- > 0) {
        int val; cin >> val;
        TreeNode* node = new TreeNode(val);
        prev->right = node;
        node->left = prev;
        prev = prev->right;
    }

    TreeNode* head = dummy->right;
    head->left = dummy->right = nullptr;

    return head;
}


void solve()
{
    int n;
    cin >> n;
    TreeNode* head = makeList(n);
    
    head = sortedListToBST(head);
    display(head);
}

int main()
{
    file_in_out();

    
    solve();
    
  
    
}









