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


void merge(vector<int>&count, vector<pair<int,int>>&v, int left, int mid, int right)
{
    vector<pair<int,int>>temp(right-left+1);
    int i = left;
    int j = mid+1;
    int k = 0;

    while(i<=mid and j<=right)
    {
        //reverse sorting
        if(v[i].first<=v[j].first)
        {
            temp[k++] = v[j++];
        }
        else 
        {
            count[v[i].second] += right-j+1;
            temp[k++] = v[i++];
        }
    }
    
    while(i<=mid)
    {
        temp[k++] = v[i++];
    }

    while(j<=right)
    {
        temp[k++] = v[j++];
    }

    for(int i=left; i<=right; i++)
    {
        v[i] = temp[i-left];
    }
}

void mergeSort(vector<int>&count, vector<pair<int,int>>&v, int left, int right)
{
    if(left<right)
    {
        int mid = left + (right-left)/2;
        mergeSort(count,v,left,mid);
        mergeSort(count,v,mid+1,right);
        merge(count,v,left,mid,right);
    }
}

vector<int>countSmaller(vector<int>&nums)
{
   int n = nums.size();
   vector<pair<int,int>>v(n);
   for(int i=0; i<n; i++)
   {
        pair<int,int>p;
        p.first = nums[i];
        p.second = i;
        v[i] = p;
   }

   vector<int> count(n,0);
   mergeSort(count,v,0,n-1);
   return count;
}


int main()
{
    file_in_out();

   vector<int>nums = {5,2,6,1};
  
  vi res = countSmaller(nums);
  for(auto x:res){cout<<x<<" ";}cout<<endl;


}
