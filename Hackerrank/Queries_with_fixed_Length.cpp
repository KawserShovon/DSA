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


void add(deque<int>&q, int new_element)
{
    while(!q.empty() and q.back() < new_element)
    {
        q.pop_back();
    }
    q.push_back(new_element);
}

void remove(deque<int>&q, int remove_element)
{
    if(!q.empty() and q.front()==remove_element )
    {
        q.pop_front();
    }
}

vector<int> solve(vector<int> arr, vector<int> queries) 
{       
    vector<int> ans;
    int mx ;
    for(int i=0; i<queries.size(); i++)
    {
        int q = queries[i];
        vector<int> tempans;
        deque<int>d;

        for(int j=0; j<q; j++)
        {
            add(d,arr[j]);
        }
        tempans.push_back(d.front());
        

        for(int j=q, k=0; j<arr.size(); j++,k++)
        {
            remove(d,arr[k]);
            add(d,arr[j]);
            tempans.push_back(d.front());
        }
        
        mx = INT_MIN;
        mx = *min_element(tempans.begin(),tempans.end()); 
        ans.push_back(mx);
        
    }

    return ans;
}



int main()
{
    file_in_out();

    int n,q;
    cin>>n>>q;
    vi arr(n);
    vi query(q);
    REP(i,0,n){cin>>arr[i];}
    REP(i,0,q){cin>>query[i];}

    vector<int>ans = solve(arr,query);
    for(auto x:ans){cout<<x<<endl;}
  

}
