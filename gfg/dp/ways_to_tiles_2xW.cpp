
//https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1

    long long mod = 1e9+7;
    long long numberOfWays(long long N) {
        long long dp[N+1];
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=N; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        
        return dp[N];
        
    }