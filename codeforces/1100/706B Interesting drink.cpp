

//https://codeforces.com/problemset/problem/706/B
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


ll precompute[10000001];

void buildSoln(vector<ll> &arr)
{
    sort(arr.begin(),arr.end());
    ll n = arr.size()-1;
    ll mx = arr[n];

    for(ll i=0;i<arr.size();i++)
    {
        precompute[arr[i]]++;
    }

    for(ll i=1; i<10000001;i++)
    {
        if(i<=mx)
        {
            precompute[i] += precompute[i-1];
        }
        else 
        {
            precompute[i] = precompute[mx];
        }
    }

}


int main()
{
    file_in_out();

   ll n;
   cin>>n;
   vector<ll> arr(n);
   for(ll i=0 ;i<n; i++)
   {
    
    cin>>arr[i];
    }

    memset(precompute,0,sizeof(precompute));
    buildSoln(arr);
   
   ll q;
   cin>>q;

    vector<ll>qrr(q);
  for(ll i=0; i<q; i++)
  {
    cin>>qrr[i];
  }
  for(ll i=0; i<q; i++)
  {
    if(qrr[i]>1e5)
    {
        cout<<n<<endl;
    }
    else 
    {
       cout<<precompute[qrr[i]]<<endl; 
    }
    
  }

}
