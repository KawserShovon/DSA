// 1277. Count Square Submatrices with All Ones

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



int countSquares(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0; i<n; i++)
    {
        dp[i][0] = matrix[i][0];
    }

    for(int i=0; i<m; i++)
    {
        dp[0][i] = matrix[0][i];
    }

    int ans = 0;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(matrix[i][j]==1)
            {
                dp[i][j]= 1+ min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
              
            }
      
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m;j++)
        {
            ans += dp[i][j];
        }
    }
    
    return ans;
}



int main()
{
    file_in_out();

    vii matrix = {{0,1,1,1},
                    {1,1,1,1},
                    {0,1,1,1}
                };


   cout<<countSquares(matrix)<<endl;

}
