
//https://codeforces.com/problemset/problem/1385/C
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
    int pos = n-1;
    while(pos>0 and arr[pos]<=arr[pos-1])
    {
        pos--;
    }

    while(pos>0 and arr[pos]>=arr[pos-1])
    {
       pos--;
    }

    cout<<pos<<endl;
    
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

        solve(n,arr);
    }


}
