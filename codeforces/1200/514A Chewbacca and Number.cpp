


//https://codeforces.com/problemset/problem/514/A

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




void solve(ll digit)
{
    if(digit<10)
    {
        cout<<digit<<endl;
        return;
    }
    
    ll temp = digit;
    string s = "";
    while(temp>0)
    {
        int singledigit = temp%10;
        temp = temp/10;
        if(9-singledigit<singledigit)
        {
            s += to_string(9-singledigit);
        }
        else 
        {
            s += to_string(singledigit);
        }
    }
    

    reverse(s.begin(),s.end());
    if(s[0]=='0')
    {
        s[0] = '9';
    }
    cout<<s<<endl;
}


int main()
{
    file_in_out();

    ll digit;
    cin>>digit;

    solve(digit);


}
