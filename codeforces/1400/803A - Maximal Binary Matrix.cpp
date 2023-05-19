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


void solve(int n, int k)
{
    vii ans(n,vi(n,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0 ;j<n; j++)
        {
            if(k>0 and i==j)
            {
                ans[i][j]=1;
                k--;
            }
            else 
            {
                if(k>1 and ans[i][j]==0 and ans[j][i]==0)
                {
                    ans[i][j]=1;
                    ans[j][i]=1;
                    k = k-2;
                }
            }
        }
    }

    if(k>0)
    {
        cout<<-1<<endl;
        return;
    }
    
    for(auto x:ans)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}



int main()
{
    file_in_out();

    int n;
    cin>>n;
    int k;
    cin>>k;

    solve(n,k);

}
