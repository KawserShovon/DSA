
//https://codeforces.com/problemset/problem/617/B

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




void solve(vector<int>&arr, int n)
{
    ll ans = 1;
    stack<int>st;

    for(int i=0; i<n; i++)
    {
        if(arr[i]==1)
        {
            if(st.size()>0)
            {
                ll dist = i-st.top();
                ans *= dist;
            }
             st.push(i);
        }
       
    }

    cout<<ans<<endl;
}


int main()
{
    file_in_out();

   int n;
   cin>>n;
  
    int total_nut = 0;
    vector<int>arr(n);
    REP(i,0,n){cin>>arr[i]; total_nut += arr[i];}
    if(total_nut==0)
    {
        cout<<0;
        return 0;
    }
    else 
    {
        solve(arr,n);
    }



}
