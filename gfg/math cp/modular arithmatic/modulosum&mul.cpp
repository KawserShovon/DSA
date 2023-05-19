// sum of array elements under modulo 10^9+7;
//get factorial under modulo 10^9+7
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <list>
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




const int MOD = 1000000007;

long long getsum(vector<long long> &arr, int n)
{
    int res = 0;
    for(int i=0; i<arr.size(); i++)
    {
        //res = (res+arr[i])%MOD; //wrong
        res = (res%MOD + arr[i]%MOD)%MOD;
    }
    return res;
}


int factorial(long long n)
{
    int res = 1;
    for(long long i=2; i<=n; i++)
    {
        res = ((res)*(i%MOD))%MOD;
    }

    return res;
}


int main()
{
    file_in_out();

   int n;
   cin>>n;
   vector<long long> arr(n);
   for(int i=0; i<n;i++)
   {
    cin>>arr[i];
   }
   cout<<getsum(arr,n)<<endl;
  
  cout<<factorial(n)<<endl;

}
