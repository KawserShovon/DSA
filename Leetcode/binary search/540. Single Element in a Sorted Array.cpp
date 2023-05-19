// 540. Single Element in a Sorted Array
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



int singleNonDuplicate(vector<int>& nums)
{
    if(nums.size()==1)return nums[0];
    int lo = 0, hi = nums.size()-1;
    int mid ;
    while(lo<=hi)
    {
        mid = lo + (hi-lo)/2;

        if(mid&1)
        {
            if(nums[mid]==nums[mid-1])
            {
                lo = mid+1;
            }
            else 
            {
                hi = mid -1;
            }
        }
        else 
        {
            if(nums[mid]==nums[mid+1])
            {
                lo = mid + 1;
            }
            else 
            {
                hi = mid -1 ;
            }
        }
    }

    return nums[lo];

}


int main()
{
    file_in_out();

    int n;
    cin>>n;
    vi arr(n);
    REP(i,0,n){cin>>arr[i];}

    cout<<singleNonDuplicate(arr)<<endl;

}
