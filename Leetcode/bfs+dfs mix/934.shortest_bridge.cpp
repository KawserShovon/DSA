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

struct pairs
{
    int r,c,level;
    pairs(int r, int c, int level)
    {
        this->r = r;
        this->c = c;
        this->level = level;
    }
};


//for multi source bfs
queue<pairs>q;
bool isValid(vector<vector<int>>&grid, vector<vector<bool>>& visited, int x, int y)
{
    if(x<0 or x>=grid.size() or y<0 or y>=grid[0].size() or grid[x][y] == 0 or visited[x][y]==true )
    {
        return false;
    }

    return true;
}

void dfs(vector<vector<int>>&grid,vector<vector<bool>>& visited,  int x, int y)
{
  
    if(isValid(grid,visited,x,y))
    {
        visited[x][y] = true;
        //multi source bfs scheme
        q.push(pairs(x,y,0));
 

        dfs(grid,visited,x+1,y);
        dfs(grid,visited,x-1,y);
        dfs(grid,visited,x,y+1);
        dfs(grid,visited,x,y-1);
    }
}

void connectedComponents(vector<vector<int>>&grid, vector<vector<bool>> &visited)
{
    bool flag = true;

    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            if(!visited[i][j] and grid[i][j] != 0)
            {
                if(flag)
                {
                
                    dfs(grid,visited,i,j);
                    flag = false;
                }              
          
            }
       
        }
    }
    
}



bool isValidComponent(vector<vector<int>>& grid,int x, int y)
{
    if(x<0 or x>=grid.size() or y<0 or y>=grid[0].size())
    {
        return false;
    }

    return true;
}

int bfs(vector<vector<int>>& grid,vector<vector<bool>> &visited)
{
    
    vector<int> dx = {1,0,-1,0};
    vector<int>dy = {0,1,0,-1};

    int max_dist;
 
    while(q.size()>0)
    {
        pairs t = q.front();
        q.pop();
        t.level++;
     
        for(int i=0; i<4; i++)
        {
            int row = t.r + dx[i];
            int col = t.c + dy[i];
  
            if(isValidComponent(grid,row,col)  and !visited[row][col])
            {              
                visited[row][col] = true;
                
                if(grid[row][col] == 1)
                {
               
                    max_dist = min(t.level,max_dist);
           
                    break;
                }
               
                q.push(pairs(row,col,t.level));
                
            }
        }
        
    }

    return max_dist;
}

int shortestBridge(vector<vector<int>>& grid)
{
    vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),0));
    connectedComponents(grid,visited);
 
    int min_dist = bfs(grid,visited);

    return min_dist;

}




int main()
{
    file_in_out();

    // vii grid = {{0,1},
    //             {1,0}};
 
    // vii grid = {{0,1,0},
    //             {0,0,0},
    //             {0,0,1}};

    vii grid = {{1,1,1,1,1},
                {1,0,0,0,1},
                {1,0,1,0,1},
                {1,0,0,0,1},
                {1,1,1,1,1}};


    // vii grid = {{0,1,0,0,0},
    //             {0,1,0,1,1},
    //             {0,0,0,0,1},
    //             {0,0,0,0,0},
    //             {0,0,0,0,0}};


    cout<<shortestBridge(grid)<<endl;

}
