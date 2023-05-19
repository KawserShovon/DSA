//Find the only repeating element in a sorted array of size n
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



int FindRepeatingElement(vector<int>& nums)
{
    int lo = 0;
    int hi = nums.size()-1;


    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;

        if(nums[mid]<=mid)
        {
            hi = mid-1;
        }
        else 
        {
            lo = mid+1;
        }

    }

    return lo;
}



int main()
{
    file_in_out();

    int n;
    cin>>n;
    vi arr(n);
    REP(i,0,n){cin>>arr[i];}

    cout<<FindRepeatingElement(arr)<<endl;


}
