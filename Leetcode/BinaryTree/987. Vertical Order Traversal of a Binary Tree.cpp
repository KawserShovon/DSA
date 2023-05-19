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

void width(TreeNode* root, int hl, vector<int>&arr)
{
    if(root == nullptr) return ;

    arr[0] = min(arr[0],hl);
    arr[1] = max(arr[1],hl);

    width(root->left,hl-1,arr);
    width(root->right,hl+1,arr);
}

//passes interview bit and pepcoding I (order doesn't matter)
vector<vector<int>> verticalOrderTraversal(TreeNode* root)
{
    if(root == nullptr)
    {
        vector<vector<int>>t;
        return t;
    }
    
    vector<int>range(2);
    width(root,0,range);


    unordered_map<int,vector<int>> umap;
    queue<pair<TreeNode*,int>>q;
    q.push({root,abs(range[0])});

    while(q.size()>0)
    {
        int size = q.size();

        for(int i=0; i<size; i++)
        {
            TreeNode* node = q.front().first;
            int cur_idx = q.front().second;
            q.pop();

            umap[cur_idx].push_back(node->val);
    

            if(node->left)
            {
                q.push({node->left,cur_idx-1});
            }

            if(node->right)
            {
                q.push({node->right,cur_idx+1});
            }

        }
    }

    int n = umap.size();
    vector<vector<int>> ans(n);


    
    for(auto it = umap.begin(); it!= umap.end(); it++)
    {
        int i = it->first;
        vector<int> vec;
        for(int j=0; j<it->second.size(); j++)
        {
           
            vec.push_back(it->second[j]);
           
        }
        ans[i]=(vec);
      
    }
    return ans;

}



int main()
{
    file_in_out();

    
    int n;
    cin>>n;
    vector<int> arr(n);
    REP(i,0,n){cin>>arr[i];}

    TreeNode *root = buildTree(arr);

    vector<vector<int>> ans = verticalOrderTraversal(root);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<i<<" -> ";
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }



}

