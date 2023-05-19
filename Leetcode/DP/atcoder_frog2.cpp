//frog jump
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




int helper(int idx,int n,int k, vector<int> &heights, vector<int>&dp)
{
    if(idx==n-1)
    {
        return 0;
    }

 

    // if(idx == n-2)
    // {
    //     return abs(heights[idx]-heights[idx+1]);
    // }

    if(dp[idx] != -1) return dp[idx];

  
    int mn = INT_MAX;
    // int height1 = abs(heights[idx]-heights[idx+1])+helper(idx+1,n,heights,dp);
    // int height2 = abs(heights[idx]-heights[idx+2]) + helper(idx+2,n,heights,dp);

    for(int i=1; i<=k;i++)
    {
        if(idx+i<=n-1)
        {
            int jump = abs(heights[idx]-heights[idx+i])+ helper(idx+i,n,k,heights,dp);
            mn = min(mn,jump);
        }
        
    }

   

    return dp[idx] = mn;
}

int frogJump(int n,int k, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    return helper(0,n,k,heights,dp);
}



int main()
{
    file_in_out();

   int n;
   cin>>n;
   int k;
   cin>>k;
   vi arr(n);
   REP(i,0,n){cin>>arr[i];}

   cout<<frogJump(n,k,arr)<<endl;
  

}
