

//https://codeforces.com/problemset/problem/363/B

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




void solve(vector<int>&arr, int k)
{
    vector<int>psum(arr.size(),0);
    psum[0] = arr[0];
    for(int i=1; i<arr.size(); i++)
    {
        psum[i] = psum[i-1]+arr[i];
    }
// for (auto x:psum){cout<<x<<" ";}cout<<endl;

    int i=0, j= k-1;
    int idx;
    int minsum = INT_MAX;
   
    for(int i=0; i<arr.size()-k+1; i++,j++)
    {
        int tsum = psum[j]- (i-1>=0?psum[i-1]:0); 
        // cout<<"tsum: "<<tsum<<endl;
        if(tsum<minsum)
        {
            
            minsum = tsum;
            idx = i+1;
        }
    }

    cout<<idx<<endl;
}


int main()
{
    file_in_out();

   int n;
   cin>>n;
   int k;
   cin>>k;
   vector<int>arr(n);
   
   REP(i,0,n){cin>>arr[i];}

    if(n==k)
    {
        cout<<1<<endl;
    }
    else if (k==1)
    {
        int tidx;
        int tmin = INT_MAX;
        for(int i=0 ;i<n; i++)
        {
            if(arr[i]<tmin)
            {
                tmin= arr[i];
                tidx = i+1;
            }
        }
        cout<<tidx<<endl;

    }
    else if(n==1 or n==2)
    {
        // cout<<1<<endl;
        int tidx;
        int tmin = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(arr[i]<tmin)
            {
                tmin = arr[i];
                tidx = i+1;
            }
        }
        cout<<tidx<<endl;
        
    }

    else 
    {
        // cout<<"else:<"<<endl;
        solve(arr,k);
    }
    

}
