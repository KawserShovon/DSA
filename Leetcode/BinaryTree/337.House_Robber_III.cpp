

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
    int data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int data)
    {
        this->data = data;
    
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

class housePair
{
public:
    int withRobbery = 0;
    int withoutRobbery = 0;

    housePair(int withRobbery, int withoutRobbery)
    {
        this->withRobbery = withRobbery;
        this->withoutRobbery = withoutRobbery;
    }
};


housePair* HouseRobber_helper(TreeNode * root)
{
    if (root == nullptr) return new housePair(0,0);

    housePair *lp = HouseRobber_helper(root->left);
    housePair* rp = HouseRobber_helper(root->right);
    housePair* mp = new housePair(0,0);

    mp->withRobbery = lp->withoutRobbery + rp->withoutRobbery + root->data;
    mp->withoutRobbery = max(lp->withRobbery, lp->withoutRobbery) + max(rp->withRobbery, rp->withoutRobbery);

    return mp;
}

int HouseRobber(TreeNode* root)
{
    housePair* ans = HouseRobber_helper(root);

    return max(ans->withoutRobbery,ans->withRobbery);
}

int main()
{
    file_in_out();

    int n;
    cin>>n;
    vi arr(n);
    REP(i,0,n){cin>>arr[i];}

    TreeNode* root = buildBinaryTree(arr);

    cout<<HouseRobber(root);

}
