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




void solve(vector<ll>&points)
{
    ll last=0;
    ll first =0, second = 0;
    vector<ll>firstvec,secondvec;
    ll n = points.size();


    for(ll i=0; i<points.size(); i++)
    {
        if(i==n-1)
        {
            last = points[i];
          
        }

        if(points[i]<0)
        {
            second += abs(points[i]);
            secondvec.push_back(abs(points[i]));
           
         
        }
        else 
        {
            first += abs(points[i]);
            firstvec.push_back(abs(points[i]));
        
        }
    }
    
    if(first==second and firstvec == secondvec)
    {
            
        if(last>=0)
        {
            cout<<"first"<<endl;
        }
        else  
        {
            cout<<"second"<<endl;
        }
    }
    else if(first==second )
    {
        int i=0,j=0;
        while(i<firstvec.size() or j<secondvec.size())
        {
            if(firstvec[i]==secondvec[j])
            {
                i++;
                j++;
            }
            else 
            {
                if(firstvec[i]>secondvec[j])
                {
                    cout<<"first"<<endl;
                }
                else 
                {
                    cout<<"second"<<endl;
                }
                break;
            }
        }
    }
    else if(first>second)
    {
        cout<<"first"<<endl;
    }
    else 
    {
         cout<<"second"<<endl;
    }
}


int main()
{
    file_in_out();

    ll n;
    cin>>n;
    vector<ll>points(n);
    REP(i,0,n){cin>>points[i];}

    solve(points);


}
