

bool sortCol(vector<int>&a, const vector<int>&b)
{
    return a[1]<b[1];
}

struct pairs
{
  
    int lastdep;
    int mxtrain;
    pairs()
    {
      
        lastdep = 0;
        mxtrain = 0;
    }
};

int maxStop(vector<vector<int>> &trains, int n, int m)
{
    sort(trains.begin(),trains.end(),sortCol);



    unordered_map<int,pairs>umap;

        
    for(int i=0 ;i<n; i++)
    {
        
      if(trains[i][0]>= umap[trains[i][2]].lastdep)
      {
        umap[trains[i][2]].mxtrain +=1;
        umap[trains[i][2]].lastdep = trains[i][1];

      }
        
    }

        
       

     int sum = 0;
    for (auto it = umap.begin(); it != umap.end(); it++)
        {
            sum += it->second.mxtrain;
        }

    return sum;

}   



***********************
following code gives TLE (no idea why)


bool sortCol(vector<int>&a, const vector<int>&b)
{
    return a[1]<b[1];
}

int maxStop(vector<vector<int>> &trains, int n, int m)
{
    sort(trains.begin(),trains.end(),sortCol);

    int mxtrains =0;
 
    
    for(int plat=1; plat<=m; plat++)
    {
        int lastdept;
        int lastdeptIdx;
        
        for(int i=0; i<n ; i++)
        {
            if(trains[i][2]==plat)
            {
                lastdept = trains[i][1];
                lastdeptIdx = i;
                mxtrains++;
                
                break;
            }
        }

        
        for(int i=lastdeptIdx+1 ;i<n; i++)
        {
            
            if(trains[i][2]==plat and trains[i][0]>=lastdept)
            {
                mxtrains++;
         
                lastdept = trains[i][1];
              
            }
          
        }
  
        
       
    }

    return mxtrains;

}   
