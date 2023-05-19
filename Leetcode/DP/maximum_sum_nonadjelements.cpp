


// Maximum sum of non-adjacent elements
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





int helper(int idx, vector<int>&nums, vector<int> &dp)
{
    if(idx >=nums.size()) return 0;
    if(idx==nums.size()-1 ) return nums[idx];

  
    if(dp[idx] != -1) return dp[idx];

    int maxsum = INT_MIN;
    int sum1 = 0;
    int sum2 = 0;

    sum1 = nums[idx] + helper(idx+2,nums,dp); 
    
    sum2 = helper(idx+1,nums,dp);
 

   maxsum = max(sum1,sum2);

    return dp[idx] = maxsum;
}


int maximumNonAdjacentSum(vector<int> &nums){
    vector<int>dp(nums.size(),-1);
    return helper(0,nums,dp);


}


int main()
{
    file_in_out();

   int t;
   cin>>t;


   while(t--)
   {
    int n; cin>>n;
    vector<int> nums(n);
    REP(i,0,n){cin>>nums[i];}
   
    cout<<maximumNonAdjacentSum(nums)<<endl;

   }
  

}

//94 11 70 72 44
//1 3 5 7 10
//0 2 4 6 9