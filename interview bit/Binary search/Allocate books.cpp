

//Allocate Minimum Number Of Pages
//https://www.youtube.com/watch?v=okP-e2VpI_g&ab_channel=Pepcoding
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


bool isPossible(int mid, int students,vector<int>&pages)
{
    int sum = 0;
    int curStudent = 1;
    
    for(int i=0 ;i<pages.size(); i++)
    {
        sum +=pages[i];
        if(sum>mid)
        {
            sum = pages[i];
            curStudent++;
        }

        if(curStudent>students)
        {
            return false;
        }
        
    }
    return true;
}

int allocateMinNoOfPages(int n, vector<int>&pages, int students)
{
    int n = pages.size();

    if(students>n)
    {
        return -1;
    }

  
    int lo = *max_element(pages.begin(),pages.end());
    int hi = accumulate(pages.begin(),pages.end(),0);

    

    int ans = INT_MAX;
    
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
     
        if(isPossible(mid,students,pages))
        {
            ans =mid;
            hi= mid-1;    
        }
        else 
        {
            lo = mid+1;
        }
    }

    return ans;
  
}


int main()
{
    file_in_out();

    int n;
    cin>>n;

    vector<int>pages(n);
    REP(i,0,n){cin>>pages[i];}

    int students;
    cin>>students;

    // cout<<allocateMinNoOfPages(n,pages,students)<<endl;
    if(allocateMinNoOfPages(n,pages,students)==INT_MAX)
    {
        cout<<-1<<endl;
    }
    else 
    {
        cout<<allocateMinNoOfPages(n,pages,students)<<endl;
    }


}
