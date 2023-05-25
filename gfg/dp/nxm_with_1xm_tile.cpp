/https://practice.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1

int mod = 1e9+7;
int countWays(int n, int m)
{
    int dp[n+1];

    for(int i=1; i<=n; i++)
    {
        if(i<m)
        {
            dp[i] = 1;
        }
        else if(i==m)
        {
            dp[i] = 2;
        }
        else 
        {
            dp[i] = (dp[i-1] + dp[i-m])%mod;
        }
    }

    return dp[n];
}
