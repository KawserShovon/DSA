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

//no need of global variable here
// int globalMx = 0;
bool isValid(int i, int j, int n, int m,vector<vector<int>>&grid,vector<vector<bool>>&visited)
{
    if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0 or visited[i][j]==1)
    {
        return false;
    }

    return true;
}

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int helper(int i, int j, int n, int m, vector<vector<int>>&grid, vector<vector<bool>>&visited)
{
    if(!isValid(i,j,n,m,grid,visited)) return 0;

    visited[i][j] = true;

    // int left  = helper(i,j-1,n,m,grid,visited);
    // int right = helper(i,j+1,n,m,grid,visited);
    // int up = helper(i-1,j,n,m,grid,visited);
    // int down = helper(i+1,j,n,m,grid,visited);

    int tmp = 0;
    for(int k=0; k<4; k++)
    {
        int newx = i + dx[k];
        int newy = j + dy[k];
        int newVal = helper( newx,newy,n,m,grid,visited);
        tmp = max(tmp,newVal);
    }

    // int t = max({left,right,up,down});
    // int mx = grid[i][j]+t;

    int mx = grid[i][j]+tmp;


    //wrong concept the following comment
    // globalMx = max(globalMx,mx);

    visited[i][j] = false;
    //wrong concept the following comment
    // mx -=t;

    return mx;

}

int getMaximumGold(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int mx = 0;

    

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]!= 0)
            {
                vector<vector<bool>>visited(n,vector<bool>(m,0));
                int tval = helper(i,j,n,m,grid,visited);
                
                mx = max(mx,tval);
           
               

            }
        }
    }

    return mx;
}


int main()
{
    file_in_out();

   vii grid = {{0,6,0},{5,8,7},{0,9,0}};
    cout<<getMaximumGold(grid)<<endl;

}
