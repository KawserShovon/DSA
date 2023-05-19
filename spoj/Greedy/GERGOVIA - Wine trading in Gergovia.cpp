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

// ll abs(ll t)
// {
//     if(t<0)
//     {
//         return t*-1LL;
//     }

//     return t;
// }

void Gergovia(vector<ll>&houses)
{
    ll buy=0, sell=0;
    for(ll k=0; k<houses.size(); k++)
    {
        if(houses[k]>=0)
        {
            buy = k;
            break;
            
        }
    }

    for(ll k=0; k<houses.size(); k++)
    {
        if(houses[k]<0)
        {
            sell = k;
            break;
        }
    }

    cout<<"buy id start "<<buy<<" sell id start "<<sell<<endl;

    ll cost = 0; 
    bool buyflag = false;
    bool sellflag = false;
    
    while(buy<houses.size() or sell<houses.size())
    {
        cout<<"before "<<endl;
        cout<<"houses[buy]: "<<houses[buy]<<endl;
        cout<<"house[sell]: "<<houses[sell]<<endl;
        ll temp = 0;
        if(abs(houses[buy])>=abs(houses[sell]))
        {
            temp = abs(houses[sell]);
            houses[buy] -=temp;
            houses[sell] +=temp;
        }
        else 
        {
            temp = abs(houses[buy]);
            houses[buy] -=temp;
            houses[sell] += temp;
        }
        cout<<"temp : "<<temp<<endl;
        cout<<"buy: "<<buy<<" sell "<<sell<<endl;
        cost += abs(buy-sell)*temp;
        
        cout<<"houses[buy]: "<<houses[buy]<<endl;
        cout<<"houses[sell]: "<<houses[sell]<<endl;
        cout<<"cost: "<<cost<<endl<<endl;
       
        // buy++;sell++;
        if(houses[buy]<=0)
        {
            buy++;
        }

        if(houses[sell]>=0)
        {
            sell++;
        }

        while(houses[buy]<0 and buy<houses.size())
        {
            buy++;
        }

        while(houses[sell]>=0 and sell<houses.size())
        {
            sell++;
        }
    }

    cout<<"Endcost "<<cost<<endl;






}


int main()
{
    file_in_out();

    ll n;
    while(cin>>n)
    {
        vector<ll>houses(n);
        REP(i,0,n){cin>>houses[i];}
        for(auto x:houses){cout<<x<<" ";}cout<<endl;
        Gergovia(houses);
        
    }
    
   
  

    
}
