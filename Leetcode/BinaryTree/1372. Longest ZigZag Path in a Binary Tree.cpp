
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


int idx = 0;
TreeNode* buildBinaryTree(vi arr)
{
    if(arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    TreeNode* node = new TreeNode(arr[idx++]);
    node->left = buildBinaryTree(arr);
    node->right = buildBinaryTree(arr);
    return node ;
}


class Pair
{
public:
    int forwardslope = -1; //return as no. of edges
    int backwardslope = -1;
    int maxLen = 0;

    Pair(int forwardslope,int backwardslope )
    {
        this->forwardslope = forwardslope;
        this->backwardslope = backwardslope;
    }


};

Pair* longestZigZag_helper(TreeNode* root) {
    if(root==nullptr) return  new Pair(-1,-1);

    Pair* left = longestZigZag_helper(root->left);
    Pair* right = longestZigZag_helper(root->right);

    Pair* myAns = new Pair(-1,-1);

    myAns->maxLen = max(max(left->maxLen,right->maxLen),max(left->backwardslope,right->forwardslope)+1);
    myAns->forwardslope = left->backwardslope+1;
    myAns->backwardslope = right->forwardslope+1;
    return myAns;
}


int longestZigZag(TreeNode* root) {
    Pair* ans = longestZigZag_helper(root);
    return ans->maxLen;
}

int main()
{
    file_in_out();

    int n;
    cin>>n;
    vi arr(n);
    REP(i,0,n){cin>>arr[i];}

    TreeNode* root = buildBinaryTree(arr);
    cout<<longestZigZag(root)<<endl;
  

}
