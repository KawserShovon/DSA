

// max area of Island

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

#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vd vector<double>
#define vdll vector<long double>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPeq(i,a,b) for(int i=a; i<=b; i++)

template<typename T>
void display1d(T text)
{
    for(auto x:text)
    {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
}

template<typename T>
void display2d(std::vector<std::vector<T>> vec)
{
    for(auto x:vec)
    {
        for(auto y:x)
        {
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}


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


bool isValid(vector<vector<int>>&grid,int i, int j)
{
    if(i>=0 and i<grid.size() and j>=0 and j<grid[0].size())
    {
        return true;
    }
    return false;
}
int cnt = 0;
int mxcnt = 0;
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

void dfs(vector<vector<int>>&grid, vector<vector<bool>>&visited, int i, int j)
{
    
    
    if(isValid(grid,i,j) and visited[i][j] == 0 and grid[i][j]==1)
    {
        // cout<<"visiting: "<<i<<" "<<j<<endl;
        cnt++;
        visited[i][j] = 1;

        for(int d=0; d<4; d++)
        {
            dfs(grid,visited,i+dx[d],j+dy[d]);
        }
        // dfs(grid,visited,i+1,j);
        // dfs(grid,visited,i-1,j);
        // dfs(grid,visited,i,j+1);
        // dfs(grid,visited,i,j-1);
       
    }
    // // writing the following line actually gives outupt
    // //after moving only one direction each
    // cout<<"cnt: "<< cnt<<endl;
    // mxcnt = max(mxcnt,cnt);
    // cnt = 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    vector<vector<bool>> visited (grid.size(),vector<bool>(grid[0].size(),0));
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0 ;j<grid[0].size(); j++)
        {
            if(visited[i][j] == 0 and grid[i][j] == 1)
            {
                dfs(grid,visited,i,j);
                

                //give output after moving along 4 directions
                mxcnt = max(mxcnt,cnt);
                cnt = 0;
                
            }
            
        }
    }
    return mxcnt ;

}





int main()
{
    file_in_out();


    vii Grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0}, 
                {0,0,0,0,0,0,0,1,1,1,0,0,0}, 
                {0,1,1,0,1,0,0,0,0,1,0,0,0}, 
                {0,1,0,0,1,1,0,0,1,0,1,0,0}, 
                {0,1,0,0,1,1,0,0,1,1,1,0,0}, 
                {0,0,0,0,0,0,0,0,1,0,1,0,0}, 
                {0,0,0,0,0,0,0,1,1,1,0,0,0}, 
                {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    cout<<maxAreaOfIsland(Grid);
    

}
