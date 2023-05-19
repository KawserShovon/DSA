

//Path in ZigZag labelled Binary tree || Leetcode

 vector<int> pathInZigZagTree(int n)
 {
    int llv = 1;
    int ctval = 0;
    while(ctval<n)
    {
        ctval += llv;
        llv = llv*2;
    }

    llv /=2;

    vector<int>ans;
    while(n!= 1)
    {
        ans.push_back(n);
        int complement = (3*llv-n-1);
        int parent = (complement/2);
        n = parent;
        llv /=2;
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    return ans; 
 }