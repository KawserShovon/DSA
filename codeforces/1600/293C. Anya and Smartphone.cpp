
// C. Anya and Smartphone
#include <iostream>
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

void solve(ll n, ll m, ll k, vector<ll> &arr, vector<ll> & icons, vector<ll> &aux)
{
    ll cost = 0;
    
    for(ll i=0; i<m; i++)
    {
        ll idx = aux[icons[i]];
        cost += (idx/k+1 );
        
        if(idx-1>=0)
        {
            //this swap has to perform first
            //otherwise arr[idx] value will change
            swap(aux[arr[idx]],aux[arr[idx-1]]);
            swap(arr[idx],arr[idx-1]);
            
        }

    }
    cout<<cost<<endl;
}

int main()
{
    file_in_out();

    ll n, m, k;
    cin>>n>>m>>k;

    vector<ll> arr(n);
    vector<ll> aux(n+1,0);
    REP(i,0,n){cin>>arr[i];aux[arr[i]]= i;}
    vector<ll> icons(m);
    REP(i,0,m){cin>>icons[i];}

    solve(n,m,k,arr,icons,aux);

}
