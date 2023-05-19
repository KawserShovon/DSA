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


void solve(ll c, ll m, ll x)
{
    ll l = 0;
    ll r = min(c,m);

    ll total = c+m+x;
    ll ans;
    while(l<=r)
    {
        ll mid = l + (r-l)/2;

        if(total-2*mid>=mid)
        {
            ans = mid;
            l = mid+1;
        }
        else 
        {
            r = mid-1;
        }
    }

    cout<<ans<<endl;
}




int main()
{
    file_in_out();

     int q;
     cin>>q;
     while(q--)
     {
        ll c,m,x;
        cin>>c>>m>>x;

        solve(c,m,x);
     }
  

}
