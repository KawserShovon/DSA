class Solution {
public:

    int dphelper(int n,  vector<int> &dp)
    {
        if(n<0) return 0;
         if(n==0) return 1;
        if(dp[n] != -1) return dp[n];
        int count1 = dphelper(n-1,dp);
        int count2 = dphelper(n-2,dp);
        
        return dp[n] = count1+count2;

    }
    int climbStairs(int n) {
         vector<int>dp(n+1,-1);
         return dphelper(n,dp);

    }
};