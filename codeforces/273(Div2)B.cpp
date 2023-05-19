//https://codeforces.com/problemset/problem/478/B
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
#include<numeric>


#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vd vector<double>
#define vdll vector<long double>
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






void solve(ll &a, ll &b)
{
    
    
    ll kmax = ((a-b)+1)*(a-b)/2;
    
    if(b==1)
    {
        cout<<kmax<<" "<<kmax<<endl;
        return;
    }

    ll separateone = a/b;
    ll howManytogetherPairs = a%b;
    //one group having separateone no members each
    ll ans1 = (separateone*(separateone-1))/2;
    //another groups having separateone+1 no of members each
    ll ans2 = ((separateone+1)*separateone)/2;
    
    ll kmin = ans1*(b-howManytogetherPairs)+ans2*(howManytogetherPairs);
    
    cout<<kmin<<" "<<kmax<<endl;

}


int main()
{
    file_in_out();

    ll a,b;
    cin>>a>>b;
    solve(a,b);

  

}
