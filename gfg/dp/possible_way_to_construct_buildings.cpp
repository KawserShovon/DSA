class Solution{
    
    public:
    long long mod = 1000000007;
    int TotalWays(int N)
    {
        int dp0[N+1];
        int dp1[N+1];
        
        dp0[0]= dp1[0] = 0;
        dp0[1] = dp1[1] = 1;
        
        for(int i=2 ; i<=N; i++)
        {
            dp0[i] = (dp0[i-1] + dp1[i-1])%mod; //means consecutive 0's allowed 
            dp1[i]  = dp0[i-1];
        }
        
        long long sum = (dp0[N]+ dp1[N])%mod;
        
        return (sum*sum)%mod;
    }
};
