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

bool cmp(vector<int>&a, vector<int>&b)
{
    return a[1]>b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    vector<int>deadline(jobs.size());
    vector<int>profit(jobs.size());
    int mxdeadline = INT_MIN;

    sort(jobs.begin(),jobs.end(),cmp);
    for(int i=0; i<jobs.size(); i++)
    {
        deadline[i] = jobs[i][0];
        profit[i] = jobs[i][1];
        mxdeadline = max(mxdeadline,deadline[i]);
    }

    vector<bool>trackdays(mxdeadline+1,0);
    int days = mxdeadline;
    int totalprofits = 0;
    for(int i=0; i<jobs.size(); i++)
    {

        if(!trackdays[deadline[i]])
        {
            trackdays[deadline[i]] = true;
            totalprofits += profit[i];
        }
        else 
        {
           
            int day = deadline[i];
          
            while(day>=1)
            {
                    
                if(trackdays[day] == false)
                {
                  
                    trackdays[day] = true;
                    totalprofits += profit[i];
                    break;
                }
                day--;
            }
        }
        
    }

    return totalprofits;

}



int main()
{
    file_in_out();

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> jobs(n,vector<int>(2));
        for(int j=0 ;j<2; j++)
        {
            for(int i=0; i<n; i++)
            {
                cin>>jobs[i][j];
            }
        }
        cout<<jobScheduling(jobs)<<endl;

      
    }


}
