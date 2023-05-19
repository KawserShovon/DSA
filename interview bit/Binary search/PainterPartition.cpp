


//Painter Partition problem (working code without multiplying unitTime)
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


ll mod = 10000003;
bool isPossible(int mid, int noOfPainters,  vector<int>&arr)
{
    int currPaintNo = 1;
    int currTime = 0;
    
    for(int i=0; i<arr.size(); i++)
    {
     
        currTime += arr[i];
        
        if(currTime>mid)
        {
            
            currTime = arr[i];
            currPaintNo++;
           
        }
        
        if(currPaintNo>noOfPainters)
        {
            return false;
        }
    }
  

    return true;
}


int PainterPartition(int noOfPainters, int unitTime, vector<int>& arr)
{
    int lo = *max_element(arr.begin(),arr.end());
    int hi = accumulate(arr.begin(),arr.end(),0);
   
    int ans ;

    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
   
        if(isPossible(mid,noOfPainters,arr))
        {
     
            ans = mid;
            hi = mid-1;
         
             
        }
        else 
        {            
            lo = mid+1;
            
        }
    }
    ans = ((ans%mod * unitTime%mod)% mod);
    return ans; 
}

int main()
{
    file_in_out();

    int noOfPainters, unitTime;
    cin>>noOfPainters>>unitTime;
    int N;
    cin>>N;
    vector<int>arr(N);
    REP(i,0,N){cin>>arr[i];}

    cout<<PainterPartition(noOfPainters,unitTime,arr)<<endl;


}

