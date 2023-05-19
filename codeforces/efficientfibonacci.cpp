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

const ll M = 1e9+7;


ll mod(ll a)
{
    return (((a%M)+M)%M);
}

map<ll,ll> F;
ll fibonacci(ll n)
{
    if(F.count(n)) return F[n];

    ll k = n/2;

    if(n%2==0)
    {
        return F[n] = mod(fibonacci(k)*fibonacci(k) + fibonacci(k-1)*fibonacci(k-1));
    }
    else 
    {
        return F[n] = mod(fibonacci(k)*fibonacci(k-1) + fibonacci(k-1)*fibonacci(k));
    }
}

int main()
{
    file_in_out();

   int n;
   cin>>n;
   F[0]=F[1] = 1;
   cout<<fibonacci(10)<<endl;
  

}