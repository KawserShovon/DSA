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




void solve(int a, int b, int n)
{
    int val= a;
    int cnt = 1;
     bool iftrue = false;
    val = val*10;
    
    int j;
    for( j=0; j<=9; j++)
    {
        val +=1;
        if(j==0)
        {
            val--;
        }
        if(val%b==0)
        {
            iftrue = true;
            break;
        }
    
    }
        
    string ans ="";
    if(iftrue)
    {
        ans += to_string(val);
        for(int i=0 ;i<n-1; i++)
        {
            ans +='0';
        }
        cout<<ans<<endl;
        return;
    }

    
    cout<<-1<<endl;
}



int main()
{
    file_in_out();

    int a,b,n;
    cin>>a>>b>>n;

    solve(a,b,n);


}
