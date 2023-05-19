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



long long minimumCost(vector<int> &cost, int n, int k)
{
    sort(cost.begin(), cost.end());
    int i=0, j =n-1;
    long long mincost = 0;
    while(i<=j)
    {
        mincost += (1LL*cost[i]);
        i++;
        j = j-k;
    }
    return mincost;
}

long long maximumCost(vector<int> &cost, int n, int k)
{
    sort(cost.begin(), cost.end(),greater<int>());
    int i=0, j =n-1;
    long long maxcost = 0;
    while(i<=j)
    {
        maxcost += (1LL*cost[i]);
        i++;
        j = j-k;
    }
    return maxcost;
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
        int k;
        cin>>k;
        vector<int>cost(n);
        REP(i,0,n){cin>>cost[i];}
        cout<<minimumCost(cost,n,k)<<" ";
        cout<<maximumCost(cost,n,k)<<endl;
    }


}
