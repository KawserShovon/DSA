int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    int sum = INT_MIN;
     
    for(int rr=0; rr<R; rr++)
    {
       vector<int>t(C,0);
      
        for(int r=rr; r<R; r++)
        {
            for(int c=0; c<C; c++)
            {
               
                    t[c] += M[r][c];
             
            }
            // for(auto x:t){cout<<x<< " ";}cout<<endl;

            int tsum = 0;
            
            for(auto x:t)
            {
                tsum +=x;

                sum = max(tsum,sum);
                //if the tsum <0 not x<0
                if(tsum<0)
                {
                    tsum =0;
                    
                    continue;
                }
                
                
                
                // cout<<"sum: "<<sum<<endl;
            }
        }
    }

    return sum;
}
