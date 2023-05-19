vector<vector<int>> kSumHelper(vi arr, int target, int k, int si)
{
   if(k==2)
   {
    return twoSum(arr,target,si);
   }
    int n = arr.size();

    vector<vector<int>> res;
    if(n-si<0)
    {
        return res;
    }

    for(int i=si; i<=n-k; i++)
    {
        if(i!=si and arr[i]==arr[i-1])
        {
            continue;
        }

        int val1 = arr[i];
        vector<vector<int>>subRes = kSumHelper(arr,target-val1,k-1, i+1);
        for(vector<int> list:subRes)
        {
            list.push_back(val1);
            res.push_back(list);
        }
    }

    return res;
}





vector<vector<int>> kSum(vi arr, int target, int k)
{
    sort(arr.begin(),arr.end());
    return kSumHelper(arr,target,k,0);
}
