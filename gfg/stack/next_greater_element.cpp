//Next Greater Element
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

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans(n);
    ans[n-1]= -1;

    stack<long long>st;
    st.push(arr[n-1]);

    for(int i=n-2;i>=0; i--)
    {
        if(arr[i]<st.top())
        {
            ans[i] = st.top();
            st.push(arr[i]);
        }
        else 
        {
            while(st.size()>0 and arr[i]>=st.top())
            {
                st.pop();
            }
            if(st.size()==0)
            {
                ans[i] = -1;
            }
            else 
            {
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
    }

    return ans;

}





int main()
{
    file_in_out();

   int n;
   cin>>n;
   vector<ll> arr(n);
   REP(i,0,n){cin>>arr[i];}

    vector<ll> ans = nextLargerElement(arr,n);
    for(auto x:ans)
    {
    cout<<x<<" ";
    }
  

}
