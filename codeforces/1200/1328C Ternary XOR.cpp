

//https://codeforces.com/problemset/problem/1328/C
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




void solve(int n, string &s)
{
    bool prev0inOne = false;

    string s1="1",s2="1";
    // considering s1>s2 when single 1 is available

    for(int i=1; i<n; i++)
    {
           
        if(s[i]=='2' and prev0inOne==false)
        {
            
            s1+='1';
            s2+='1';
        }
        else if(s[i]=='1' and prev0inOne==false)
        {
            s1 +='1';
            s2 +='0';
            prev0inOne = true;
        }
        else 
        {
            s1 += '0';
            s2 += s[i];
        }
    }

    cout<<s1<<endl;
    cout<<s2<<endl;
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
        string s;
        cin>>s;
        solve(n,s);
    }


}
