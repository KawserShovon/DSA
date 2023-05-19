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




ll pickingUPchicks(ll n, ll k, ll b, ll t, vector<ll>&locations, vector<ll>&speeds)
{
    ll swapsreq =0;
    ll totalswaps = 0;
    ll chickspassed = 0;
    for(ll i=n-1; i>=0; i--)
    {
        ll distCanCover = speeds[i]*t;
        ll totaldist = distCanCover+locations[i];
        // cout<<"total dist: "<<totaldist<<endl;
        // ll distance = b-locations[i];
        // ll canCover = t*speeds[i];

        if(totaldist>=b)
        // if(distance<=canCover)
        {
            chickspassed++;
            totalswaps +=swapsreq;
        }
        else 
        {
            swapsreq++;
        }
        if(chickspassed>=k)
        {
            break;
        }
    }
    if(chickspassed>=k)
    {
        return totalswaps;
    }
    return -1;
}


int main()
{
    file_in_out();

    ll t;
    cin>>t;
    ll tests = 1;
    while(t--)
    {
        ll n,k,b,t;
        cin>>n>>k>>b>>t;
        vector<ll>locations(n);
        vector<ll>speeds(n);
        for(ll i= 0; i<n; i++){cin>>locations[i];}
        for(ll i=0; i<n; i++){cin>>speeds[i];}


        cout<<"Case #"<<tests<<": ";
        ll ans = pickingUPchicks(n,k,b,t,locations,speeds);
        
        if(ans>=0)
        {
            cout<<ans<<endl;
        }
        else 
        {
            cout<<"IMPOSSIBLE"<<endl;
        }

        tests++;


    }


}
