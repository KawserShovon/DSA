#include <bits/stdc++.h> 

pair<int,int> largestSubarrZeroSum(vector<int>&A, int n)
{   
    int globalMx = 0;
    int endingIdx= -1;

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
            endingIdx = i;
        }

        if(umap.find(sum) == umap.end())
        {
            umap[sum] = i;
            continue;
          
        }
        else 
        {
            int old = globalMx;
            globalMx = max(globalMx,i-umap[sum]);
            if(old<globalMx)
            {
               endingIdx = i; 
            }
            
        }
    }
    
    return {globalMx,endingIdx};
}


int largestSubmatrixWithSumZero(vector<vector<int>> &arr, int n, int m)
{
   if(n==1 and m==1)
    {
        if(arr[0][0]==0)
		{
			return 1;
		}
		return 0;
    }
	   if(n==1)
    {
        int sum =0;
        int idx = 0;
        bool everZero = false;
        for(int i=0 ;i<m; i++)
        {
            sum += arr[0][i];
            if(sum==0)
            {
                everZero = true;
                idx = i;
            }
        }

        if(everZero)
        {
            return idx+1;
        }
        return 0;
    }

    if(m==1) 
    {
        int sum = 0;
        int idx = 0;
        bool everZero = false;
        for(int i=0 ;i<n; i++)
        {
            sum += arr[i][0];
            if(sum==0)
            {
                everZero = true;
                idx = i;
            }
        }
        if(everZero)
        {
            return idx+1;
        }
        return 0;
    }



    int x_top_left,y_top_left,x_bottom_right,y_bottom_right;
    int area = 0;
    int oldsubarrSize = 0;
	int len = INT_MIN;
    for(int row = 0; row<n; row++)
    {
        vector<int> C(m,0);
        for(int r = row; r<n; r++)
        {
            for(int c = 0; c<m; c++)
            {
                C[c] += arr[r][c];

            }

            //<largestSubArrSize,endingIndex>
            pair<int,int> p = largestSubarrZeroSum(C,m);
            int tmparea = p.first*(r-row+1);
			len = max(len,p.first);

            if(p.first <= oldsubarrSize and tmparea == area)
            {
                continue;
            }

            if(p.first > 0 and tmparea>= area )
            {
                
                area = tmparea;
                oldsubarrSize = p.first;

                x_top_left = row;
                y_top_left = p.second-p.first+1;

                x_bottom_right = r;
                y_bottom_right = p.second;

                
            }
            
        }
    }


    // if(area == 0)
    // {
    //     vector<vector<int>>t={{-1}};
    //     return t;
    // }


    // vector<vector<int>>ans;
    // for(int i=x_top_left; i<=x_bottom_right; i++)
    // {
    //     vector<int>t;
    //     for(int j=y_top_left; j<=y_bottom_right; j++)
    //     {
    //         t.push_back(arr[i][j]);
    //     }
    //     ans.push_back(t);
    // }

	if(len == 0) return 0;
	

    return area;
}
