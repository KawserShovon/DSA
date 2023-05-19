int LongestSubsetWithZeroSum(vector < int > arr)
{
    unordered_map<int,int>umap;

    int sum = 0;
    int mx= INT_MIN;
    for(int i=0; i<arr.size() ;i++)
    {
        sum += arr[i];

        if(sum==0)
        {
            mx = max(mx,i-umap[sum]+1);
        }
        else 

        {    if(umap.find(sum) != umap.end())
            {
                mx = max(mx,i-umap[sum]);
                
            }
            else 
            {
                umap[sum] = i;
            }
        }
    }
    // for(auto x:umap){cout<<x.first<<" "<<x.second<<endl;}
  
    return mx;
}
