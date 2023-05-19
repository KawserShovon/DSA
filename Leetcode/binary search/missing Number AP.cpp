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




int missingNoArithmaticProgression(vi &arr)
{
    int lo=0, hi = arr.size()-1;
    int n = arr.size();
    int diff = (arr[n-1]-arr[0])/n;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        
        if(arr[mid+1]-arr[mid] != diff)
        {
            return arr[mid]+diff;
        }

        if(mid>0 and arr[mid]-arr[mid-1] != diff)
        {
            return arr[mid-1]+diff;
        }

        if(arr[0]+mid*diff == arr[mid])
        {
            lo = mid+1;
        }
        else 
        {
            hi = mid-1;
        }
    }
    return -1;
}


int main()
{
    file_in_out();

    int n;
    cin>>n;

    vi arr(n);
    REP(i,0,n){cin>>arr[i];}
    cout<<missingNoArithmaticProgression(arr);
}
