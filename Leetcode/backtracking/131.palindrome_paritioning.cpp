

//131. Palindrome Partitioning
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

bool isPal(string &s, int start, int end)
{
    while(start<=end)
    {
        if(s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void helper(int idx, string s,vector<string> curr, vector<vector<string>>&ans)
{
   if(idx == s.length())//no string remaining
   {
    ans.push_back(curr);
    return;
   }

   for(int i = idx; i<s.length(); i++)
   {
        if(isPal(s,idx,i))
        {
            curr.push_back(s.substr(idx,i-idx+1));
            helper(i+1,s,curr,ans);
            curr.pop_back();
        }
   }

}

vector<vector<string>> partition(string s)
{
    vector<vector<string>>ans;
    vector<string> curr;
    helper(0,s,curr,ans);
    return ans;
}


int main()
{
    file_in_out();

    string s;
    cin>>s;

  vector<vector<string>> ans = partition(s);
  for(auto x:ans)
  {
    for(auto y:x)
    {
        cout<<y<<" ";
    }
    cout<<endl;
  }

}
