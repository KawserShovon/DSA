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

bool isValid(int i, int j, int n, int m)
{
    if(i<0 or i>=n or j<0 or j>=m)
    {
        return false;
    }

    return true;
}

int helper(int i, int j, int n, int m, vector<vector<int>>&M, vector<vector<int>>&memo)
{
    if(!isValid(i,j,n,m)) return 0;
    if(j==m-1 and isValid(i,j,n,m)) return M[i][j];

    if(memo[i][j] !=-1)
    {
        return memo[i][j];
    }

    int mx ;
    
    mx = M[i][j]+ max({helper(i-1,j+1,n,m,M,memo),helper(i,j+1,n,m,M,memo),helper(i+1,j+1,n,m,M,memo)});
   
    return  memo[i][j] = mx;
}



int maxGold(int n, int m, vector<vector<int>> M)
{
    vector<vector<int>>memo(n,vector<int>(m,-1));

    
    if(n==1)
    {
        int sum = 0;
        for(int i=0; i<m; i++)
        {
            sum += M[0][i];
        }
       
        return sum;
    }

    int mx = 0;
    for(int i=0; i<n; i++)
    {
        int hval = helper(i,0,n,m,M,memo);

        mx = max(mx,hval);
    }
    return mx;

}


int main()
{
    file_in_out();
    // int  n = 3, m = 3;
    // vector<vector<int>> M = {{1, 3, 3},
    //                         {2, 1, 4},
    //                         {0, 6, 4}};


    // int n = 4, m = 4;
    // vii M = {{1, 3, 1, 5},
    //  {2, 2, 4, 1},
    //  {5, 0, 2, 3},
    //  {0, 6, 1, 2}};

        int n, m;
   
    cin>>n>>m;

     vii M(n,vi(m));
    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>M[i][j];
        }
    }

    cout<<maxGold(n,m,M)<<endl;
}
