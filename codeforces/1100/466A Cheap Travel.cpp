//https://codeforces.com/problemset/problem/466/A
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







int main()
{
    file_in_out();

    int n,m,a,b;
    cin>>n>>m>>a>>b;

    int usingone = n*a;

    int bym = (n/m)*b;
    int bya = (n%m)*a;

    int usingonetwo  ;
    if(b<bya)
    {
        usingonetwo = bym+b;
        // cout<<bym+b<<endl;
    }
    else 
    {
        // cout<<bym+bya<<endl;
        usingonetwo = bym+bya;
    }

    cout<<min(usingone,usingonetwo)<<endl;
    
  

}
