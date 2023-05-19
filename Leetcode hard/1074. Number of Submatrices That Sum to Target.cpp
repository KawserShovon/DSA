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
#include <numeric>

#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vd vector<double>
#define vdll vector<long double>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPeq(i,a,b) for(int i=a; i<=b; i++)


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




int subarraySum(vector<int>& nums, int k)
{
    int count = 0;
    unordered_map<int,int>umap;
    umap[0] = 1;
    int sum = 0;
    

    for(int i=0; i<nums.size(); i++)
    {
        sum += nums[i];
        if(umap.find(sum-k) != umap.end())
        {
            count += umap[sum-k];
            
        }
      
        umap[sum]++;
       
    }
    return count;
}



int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
{
    int n= matrix.size();
    int m = matrix[0].size();



    for(int i=0; i<n; i++)
    {
        for(int j=1 ; j<m; j++)
        {
            matrix[i][j] += matrix[i][j-1];
        }
    }

    int ans = 0;

    for (int col1 = 0; col1<m; col1++)
    {
        for(int col2 = col1 ; col2<m; col2++)
        {
            int sum = 0;
            unordered_map<int,int>freq;
            freq[0] = 1;

            for(int row = 0; row<n; row++)
            {
                int rowSubarrSum = matrix[row][col2]-(col1-1>=0 ? matrix[row][col1-1]:0);
                sum += rowSubarrSum;
                if(freq.find(sum-target) != freq.end())
                {
                    ans += freq[sum-target];
                }
                freq[sum]++;
            }
        }
    }
    return ans;
}

int main()
{
    file_in_out();

    int n;
    cin>>n;
    vi arr(n);
    REP(i,0,n){cin>>arr[i];}
    int k;
    cin>>k;

    cout<<subarraySum(arr,k)<<endl;
  

}
