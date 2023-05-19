#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_map>
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
#include<numeric>
#define vi vector<int>
#define vii vector<vi>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPeq(i,a,b) for(int i=a; i<=b; i++)
#define ll long long int 
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


void helper(int idx, vector<int>& nums,vector<vector<int>>& ans )
{
    if(idx==nums.size())
    {

        ans.push_back(nums);
        
    }

    for(int i=idx; i<nums.size(); i++)
    {
        swap(nums[i],nums[idx]);
        helper(idx+1,nums,ans);
        swap(nums[i],nums[idx]);
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ans;
    helper(0,nums,ans);
    return ans;

}



int main()
{
    file_in_out();

   int n;
   cin>>n;
   vector<int> nums(n);
   REP(i,0,n){cin>>nums[i];}

   vii ans = permute(nums);
   for(auto x:ans)
   {
    for(auto y:x)
    {
        cout<<y<<" ";
    }
    cout<<endl;
   }
  

}
