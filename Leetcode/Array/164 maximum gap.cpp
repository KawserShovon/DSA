#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <list>
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
#include <sstream>

#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vd vector<double>
#define vdll vector<long double>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPeq(i,a,b) for(int i=a; i<=b; i++)


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




int maximumGap(vector<int>& nums) 
{
    if(nums.size()<=1) return 0;
    int n = nums.size();
    int mn = INT_MAX;
    int mx  = INT_MIN;
    vector<int> maxbucket(n-1,INT_MIN);
    vector<int> minbucket(n-1,INT_MAX);

    for(int num:nums)
    {
        mn = min(mn,num);
        mx = max(mx,num);
    }
    int interval  = int(ceil((mx-mn+0.0)/(nums.size()-1)));


    for(int i =0; i<nums.size(); i++)
    {
        if(nums[i] == mx or nums[i]==mn)
        {
            continue;
        }

        int index = (nums[i]-mn)/interval;

        if(maxbucket[index]== -1)
        {
            maxbucket[index] = nums[i];
        }
        else 
        {
            maxbucket[index] = max(maxbucket[index],nums[i]);
        }


        if(minbucket[index] == INT_MAX)
        {
            minbucket[index] = nums[i];
        }
        else
        {
            minbucket[index] = min(minbucket[index],nums[i]);
        }
    }

    int prev_val = mn;
    int max_gap = 0;

    for(int i=0 ; i<n-1; i++)
    {
        if(maxbucket[i] == INT_MIN)
        {
            continue;
        }

        max_gap = max(max_gap,minbucket[i]-prev_val);
        prev_val = maxbucket[i];
    }
    
    max_gap = max(max_gap,mx-prev_val);
    return max_gap;

}


int main()
{
    file_in_out();

    int n;
    cin>>n;

    vi arr(n);
    REP(i,0,n){cin>>arr[i];}

    cout<<maximumGap(arr);

  

}
