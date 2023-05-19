
//smallest number on left
//next smallest number on left
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


vector<int> leftSmaller(int n, int arr[])
{
    vector<int> ans(n);
    ans[0] = -1;
    stack<int>st;
    st.push(arr[0]);

    for(int i=1; i<n; i++)
    {
        if(arr[i]>st.top())
        {
            ans[i] = st.top();
            st.push(arr[i]);
        }
        else 
        {
            while(st.size()>0 and st.top()>=arr[i])
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
  int arr[n];
  REP(i,0,n){cin>>arr[i];}

   vector<int> ans = leftSmaller(n,arr);
   for(auto x:ans){cout<<x<<" ";}cout<<endl;
  

}





