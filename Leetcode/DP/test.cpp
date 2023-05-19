

//largest sub matrix with 0 sum(gfg motivated)
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

class pairs
{
public:
    int largestSubArrSize,startingIdx,endingIdx;
    pairs(int i,int j, int k)
    {
        largestSubArrSize = i;
        startingIdx = j;
        endingIdx = k;
    }
};

pairs largestSubarrZeroSum(vector<int>&A, int n)
{   
    int globalMx = 0;
    int endingIdx= -1;
    int startingIdx = -1;
    unordered_map<int,int>umap;
    //sum,startingIdx

    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += A[i];

        //we dont need this case
        //corner case
        // if(A[i]==0 and globalMx==0)
        // {
        //     globalMx = 1;
        // }

        // corner case
        if(sum==0)
        {
            globalMx = i+1;
    
            startingIdx = 0;
            endingIdx = i;
           
            
            
        }

        if(umap.find(sum) == umap.end())
        {
            umap[sum] = i;
            
          
        }
        else 
        {
            int old = globalMx;
            globalMx = max(globalMx,i-umap[sum]);

            if(old < globalMx)
            {
                startingIdx = umap[sum]+1;//umap[sum]+1;
                endingIdx = i;
            }
            
            
        }
    }
    
    return pairs(globalMx, startingIdx, endingIdx);
}


vector<vector<int>> sumZeroMatrix(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();

    if(n==1 or m==1)
    {
        vector<vector<int>>t={{-1}};
        return t;
    }

    int x_top_left,y_top_left,x_bottom_right,y_bottom_right;
    int area = 0;
    int oldsubarraysize = 0;
    for(int row = 0; row<n; row++)
    {
        vector<int> C(m,0);
        for(int r = row; r<n; r++)
        {
            for(int c = 0; c<m; c++)
            {
                C[c] += arr[r][c];

            }

            //<largestSubArrSize, startingIndex, endingIndex>
            pairs p  = largestSubarrZeroSum(C,m);
            int tmparea = (p.endingIdx-p.startingIdx+1)*(r-row+1);

        
        
          
            
            if(p.largestSubArrSize<=oldsubarraysize and tmparea == area)
            {
                continue;
            }
            if(p.largestSubArrSize>0 and tmparea>=area)
            {
                area = tmparea;
                oldsubarraysize = p.largestSubArrSize;
                x_top_left = row;
                y_top_left = p.startingIdx;

                x_bottom_right = r; 
                y_bottom_right = p.endingIdx;

            }        
        }
    }


    if(area == 0)
    {
        vector<vector<int>>t={{-1}};
        return t;
    }


    vector<vector<int>>ans;
    for(int i=x_top_left; i<=x_bottom_right; i++)
    {
        vector<int>t;
        for(int j=y_top_left; j<=y_bottom_right; j++)
        {
            t.push_back(arr[i][j]);
        }
        ans.push_back(t);
    }


    return ans;
}



int main()
{
    file_in_out();

    // int N = 8;
    // vi A = {15,-2,2,-8,1,7,10,23};

    // int N = 4;
    // vi A = {-1,1,-1,1};

   int n, m;
   cin>>n>>m;
   vii arr(n,vi(m));
   for(int i=0; i<n; i++)
   {
    for(int j=0; j<m; j++)
    {
        cin>>arr[i][j];
    }
   }

    vector<vector<int>>res = sumZeroMatrix(arr);

    if(res.size()==0) 
    {
        cout<<-1<<endl;
        return 0;
    }
    for(auto x:res)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}




