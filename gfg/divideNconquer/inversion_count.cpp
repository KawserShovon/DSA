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

long long cnt = 0;

vector<long long> merge2sorted(vector<long long> left, vector<long long>right)
{
    vector<long long>res(left.size()+right.size());
    int i=0, j=0, k=0;

    while(i<left.size() and j<right.size())
    {
        if(left[i]<=right[j])
        {
            res[k] = left[i];
            k++;
            i++;
        }
        else 
        {
            cnt += left.size()-i;
            res[k] = right[j];
            k++;
            j++;
        }
    }

    while(i<left.size())
    {
        res[k++] = left[i++];
    }

    while(j<right.size())
    {
        res[k++] = right[j++];
    }

    return res;
}

vector<long long> mergeSort(long long arr[], long long lo, long long hi, long long N)
{
    if(lo==hi)
    {
        vector<long long>temp(1);
        temp[0] = arr[lo];
        return temp;
    }

    long long mid = lo + (hi-lo)/2;

    vector<long long> fsh = mergeSort(arr,lo,mid,N);
    vector<long long> ssh = mergeSort(arr,mid+1,hi,N);
    vector<long long> fsa = merge2sorted(fsh,ssh);

    return fsa;
}


long long int inversionCount(long long arr[], long long N)
{
    //remember hi index is upto N-1 not upto N
    //size is still N
    vector<long long> ans = mergeSort(arr,0,N-1,N);
    return cnt;
}


int main()
{
    file_in_out();

   ll N = 5;
   ll arr[] = {2, 4, 1, 3, 5};
  
  cout<<inversionCount(arr,N);

}
