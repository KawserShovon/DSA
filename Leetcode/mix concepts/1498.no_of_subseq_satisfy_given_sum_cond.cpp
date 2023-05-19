1498. Number of Subsequences That Satisfy the Given Sum Condition
#define mod 1000000007
class Solution {
public:

long long helper(int base, int pow)
{
    if(pow == 1) return base;
    if(pow == 0) return 1;

    long long ans = 1;

    if(pow%2==0)
    {
        ans = helper(base,pow/2);
        ans *= ans;
    }
    else 
    {
        ans = helper(base,pow-1);
        ans *= base;
    }

    return ans%mod;
}

int numSubseq(vector<int>& nums, int target)
{
    sort(nums.begin(),nums.end());
    int i=0,j=nums.size()-1;


    long long cnt = 0;
    while(i<=j)
    {
        if(nums[i]+nums[j]<=target)
        {
            cnt += helper(2,j-i);
            cnt = (cnt%mod);
            i++;
        }
        else 
        {
            j--;
        }
    }
    return cnt%mod;

}
};