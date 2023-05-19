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

vi precompute;
void precomputeArr(string &s)
{
    for(int i=1; i<precompute.size(); i++)
    {
        if(s[i-1]==s[i])
        {
            precompute[i] = precompute[i-1]+1;
        }
        else 
        {
            precompute[i] = precompute[i-1];
        }
    }
}

void solve(string &s,int l, int r)
{
    int val = precompute[r]-(l>=0?precompute[l]:0);
    cout<<val<<endl;
}


int main()
{
    file_in_out();

   string s;
   cin>>s;
    precompute.assign(s.length()+1,0);
    precomputeArr(s);
    // for(auto x:precompute){cout<<x<<" ";}cout<<endl;
    int q; 
    cin>>q;

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        solve(s,l,r);
    }
  

}
