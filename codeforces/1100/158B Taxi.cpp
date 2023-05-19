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





void solve(vi &arr)
{
    vi tarr(5,0);
    for(int i=0; i<arr.size(); i++)
    {
        tarr[arr[i]]++;
    }
    // for(auto x:tarr){cout<<x<<" ";}cout<<endl;
    //tarr[4] add
    int mn = min(tarr[1],tarr[3]);
    int cnt13 = mn;//add
    int cnt1r = tarr[1]-mn; //count 1 remaining

    int cnt3r = tarr[3]-mn;//add
    int cnt2 = tarr[2]/2;//add
    int cnt2r = tarr[2]-(cnt2*2);

    int cnt1;
    if(cnt1r>4)
    {
        cnt1 = cnt1r/4; //add
    }

    int r = ceil((cnt1r + cnt2r*2)/4.0);

    // cout<<"cnt13: "<<cnt13<<endl;
    // cout<<"cnt3r: "<<cnt3r<<endl;
    // cout<<"cnt1r: "<<cnt1r<<endl;
    // cout<<"cnt2: "<<cnt2<<endl;
    // cout<<"r: "<<r<<endl;
    cout<<tarr[4]+cnt13+cnt3r+cnt2+r<<endl;


    
}

int main()
{
    file_in_out();

   int n;
   cin>>n;
   vector<int> arr(n);
   REP(i,0,n){cin>>arr[i];}
  
    solve(arr);
    
    
}
