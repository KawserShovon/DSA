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



void chocola_chocolate(int m, int n, vector<int>& xaxis, vector<int>&yaxis)
{
    sort(xaxis.begin(),xaxis.end(),greater<int>());
    sort(yaxis.begin(),yaxis.end(),greater<int>());

    // for(auto x:xaxis){cout<<x<<" ";}cout<<endl;
    // for(auto x:yaxis){cout<<x<<" ";}cout<<endl;
    // x taan dile hz bare
    // y taan dile vertical bare
    int hzpieces = 1, vertpieces = 1;

    
    int i=0,j=0;
    int cost = 0;

    while(i<m and j<n)
    {
        if(xaxis[i]>yaxis[j])
        {
            cost += (xaxis[i]*vertpieces);
            hzpieces++;
            i++;
        }
        else 
        {
            cost += (yaxis[j]*hzpieces);
            vertpieces++;
            j++;
        }
    }
  
    while(i <=m-1)
    {
        
        cost += vertpieces*xaxis[i];
        i++;
    }



    while(j <=n-1)
    {
        cost += hzpieces*yaxis[j];

        j++;
    }
      
   

    cout<<cost<<endl;
}



int main()
{
    file_in_out();

    int t;
    cin>>t;

    while(t--)
    {
        int m,n;
        cin>>m>>n;
        m--;n--;
        vector<int>xaxis(m),yaxis(n);
        REP(i,0,m){cin>>xaxis[i];}
        REP(i,0,n){cin>>yaxis[i];}
        

        chocola_chocolate(m,n,xaxis,yaxis);
    }


}
