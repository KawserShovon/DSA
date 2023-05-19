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


int maxLen(vector<int>&A, int n)
{   
    int globalMx = 0;

    unordered_map<int,int>umap;
    //sum,startingIdx

    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += A[i];

        //we dont need this case
        //corner case
        // if(A[i]==0 and globalMx==0)
        // {
        //     globalMx = 1;
        // }

        // corner case
        if(sum==0)
        {
            globalMx = i+1;
        }

        if(umap.find(sum) == umap.end())
        {
            umap[sum] = i;
            continue;
          
        }
        else 
        {
            globalMx = max(globalMx,i-umap[sum]);
        }
    }
    
    return globalMx;
}




int main()
{
    file_in_out();

    // int N = 8;
    // vi A = {15,-2,2,-8,1,7,10,23};

    // int N = 4;
    // vi A = {-1,1,-1,1};

    int N;
    cin>>N;
    vi A(N);
    REP(i,0,N){cin>>A[i];}

    cout<<maxLen(A,N)<<endl;

}
