//Floor in a Sorted Array
//https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
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



int findFloor(vector<long long> arr, long long n, long long x)
{
    ll lo = 0, hi = n-1;

    while(lo<=hi)
    {
        ll mid = lo + (hi-lo)/2;
        if(arr[mid]==x)
        {
            return mid-1;
        }
        else if(arr[mid]>x and arr[mid-1]<x)
        {
            return mid-1;
        }
        else if(arr[mid]<x and arr[mid+1]>x)
        {
            return mid;
        }
        else if(arr[mid]<x)
        {
            lo = mid+1;
        }
        else 
        {
            hi = mid -1;
        }
    }


    if(lo==0) return -1;
    if(lo==n) return n-1;
    return lo;
}



int main()
{
    file_in_out();

    ll n;
    cin>> n;
    vector<ll> v(n);
    for(ll i=0; i<n; i++){cin>>v[i];}
    ll x;
    cin>>x;

    cout<<findFloor(v,n,x)<<endl;


}
