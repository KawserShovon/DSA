

//rat in a maze
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
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


bool isValid(int i, int j, vector<vector<int>> m, int n,vector<vector<bool>>&visited)
{
    if(i<0 or i>=n or j<0 or j>=n or m[i][j]==0 or visited[i][j]==1)
    {
        return false;
    }

    return true;
}


void helper(int i, int j, vector<vector<int>> &m, int n,vector<string> &ans, string curr,vector<vector<bool>>&visited)
{
    if(i==n-1 and j==n-1)
    {
        ans.push_back(curr);
        return;
    }
   
   //visited[i][j] = true ; is wrong here
   //it will return false if we visit here
   //we check if it is valid, then visit the cell

    if(isValid(i,j,m,n,visited))
    {
        //remember to visit here 
        visited[i][j] = true;
        helper(i,j+1,m,n,ans,curr+"R",visited);//right
        helper(i,j-1,m,n,ans,curr+"L",visited); //left
        helper(i-1,j,m,n,ans,curr+"U",visited);//up
        helper(i+1,j,m,n,ans,curr+"D",visited);//down

        //backtracking
        visited[i][j] = false;
        curr.pop_back();

    }

}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,0));

    if(m[n-1][n-1]==0)
    {
        vector<string> t;
        t.push_back("-1");
        return t;
    }


    helper(0,0,m,n,ans,"",visited);
    return ans;

}





int main()
{
    file_in_out();

   int n = 4;
   vector<vector<int>> m =  {{1, 0, 0, 0},
                            {1, 1, 0, 1}, 
                            {1, 1, 0, 0},
                            {0, 1, 1, 1}};

    vector<string> ans = findPath(m,n);
    for(auto x:ans){cout<<x<<endl;}                   
  

}
