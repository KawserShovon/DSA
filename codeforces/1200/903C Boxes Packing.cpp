

//https://codeforces.com/problemset/problem/903/C
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



void solve(int n, vector<int>&arr)
{

    map<int,int>mp;
    for(int i=0; i<arr.size() ;i++)
    {
        mp[arr[i]]++;
    }

    int tmpmx = INT_MIN;
    int res = 0;
    for(auto it = mp.rbegin(); it !=mp.rend(); it++)
    {
        // cout<<it->first<<" "<<it->second<<endl;
        if(it->second>tmpmx)
        {
            tmpmx = it->second;
        }
    }

    cout<<tmpmx<<endl;


}



int main()
{
    file_in_out();

    int n;
    cin>>n;
   
    vi arr(n);
    REP(i,0,n){cin>>arr[i];}
  
    solve(n,arr);

}
