

//51. N-Queens (method I)
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

bool isSafe(int row, int col, vector<string> board, int n)
{
    int storerow= row;
    int storecol = col;

    //check upper left diagonal
    while(row>=0 and col>=0)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }
        row --; col--;
    }

    //check left side of row
    row = storerow;
    col = storecol;
    while(col>=0)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }


    //check down diagonal left
    row = storerow;
    col = storecol;
    while(row<n and col>=0)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }

        row++;col--;
    }

    return true;
}

void solve(int col,vector<string> &board, vector<vector<string>> &ans, int n)
{
    if(col == n)
    {
        ans.push_back(board);
        return;
    } 

    for(int row = 0; row<n; row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col] = 'Q';
            solve(col+1,board,ans,n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0; i<n; i++)
    {
        board[i] = s;
    }

    solve(0,board,ans,n);

    return ans;
}



int main()
{
    file_in_out();

   int n;
   cin>>n;

   vector<vector<string>>ans = solveNQueens(n);
   for(auto x:ans)
   {
    for(auto y:x)
    {
        cout<<y<<endl;
    }
    cout<<endl;
   }
  

}









//51. N-Queens (method II)
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

bool isSafe(int row, int col, vector<string> board, int n)
{
    int storerow= row;
    int storecol = col;

    //left upper diagonal (since filling row wise)
    while(row>=0 and col>=0)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    //just up (filling row wise , so checking upper row)
    row = storerow;
    col = storecol;
    while(row>=0)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }
        row--;
    }

    //right upper digaonal(since filing row wise)
    row = storerow;
    col = storecol;
    while(row>=0 and col<n)
    {
        if(board[row][col]=='Q')
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

void solve(int row,vector<string> &board, vector<vector<string>> &ans, int n)
{
    if(row == n)
    {
        ans.push_back(board);
        return;
    }

    for(int col=0; col<n; col++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col] = 'Q';
            solve(row+1,board,ans,n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0; i<n; i++)
    {
        board[i] = s;
    }

    solve(0,board,ans,n);

    return ans;
}



int main()
{
    file_in_out();

   int n;
   cin>>n;

   vector<vector<string>>ans = solveNQueens(n);
   for(auto x:ans)
   {
    for(auto y:x)
    {
        cout<<y<<endl;
    }
    cout<<endl;
   }
  

}









