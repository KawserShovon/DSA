//https://codeforces.com/problemset/problem/1335/C
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



void solve(vi &arr)
{
    int n = arr.size();

    unordered_map<int,int>umap;
    for(int i=0; i<n; i++)
    {
        umap[arr[i]]++;
    }

    int mostRepeated = INT_MIN;
    int tempfreq = INT_MIN;
    for(auto it = umap.begin(); it != umap.end(); it++)
    {
        if(tempfreq<it->second)
        {
            tempfreq = it->second;
            mostRepeated = it->first;
        }
    }

    unordered_set<int>uset;

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] != mostRepeated)
        {
            uset.insert(arr[i]);
        }
    }

    int setsize = uset.size();

    int val;
    if(setsize>=tempfreq)
    {
        val = tempfreq;
    }
    else 
    {
       val = min(setsize+1,tempfreq-1); 
    }
    
    
    if(val == 0 and n!=1)
    {
        cout<<1<<endl;
    }
    else 
    {
        cout<<val<<endl;
    }
}



int main()
{
    file_in_out();

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vi arr(n);
        REP(i,0,n){cin>>arr[i];}

        solve(arr);
    }


}
