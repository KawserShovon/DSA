//Delete array elements which are smaller than next or become smaller
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



vector<int> deleteElement(int arr[],int n,int k)
{
    vector<int>ans;
    stack<pair<int,int>>st;
    st.push({arr[0],0});
    for(int i = 1; i<n; i++)
    {
 

       while(st.size()>0 and arr[i]>st.top().first and k>=0)
       {
        if(k==0) break;
         arr[st.top().second] = INT_MIN;
         st.pop();
         k--;
       }
        st.push({arr[i],i});
        
    }
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] != INT_MIN)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}



int main()
{
    file_in_out();

    int arr[ ] = {20, 10, 25, 30, 40} ;
    int n = 5;
    int k = 2;

    vi ans = deleteElement(arr,n,k);
    for(auto x:ans){cout<<x<<" ";}cout<<endl;
  

}
