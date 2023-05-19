class Solution {
public:

    int helper(int idx, vector<int>&nums, vector<int>&dp)
    {
        if(idx >= nums.size()) return 0;
        if(idx == nums.size()-1) return nums[idx];

        if(dp[idx] != -1) return dp[idx];


      
        int select = nums[idx] + helper(idx+2,nums,dp);
        int notselect = helper(idx+1,nums,dp);

        return dp[idx] = max(select,notselect);
    }
    int rob(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        vector<int>dp;

        // vector<int>temp1;// = {nums.begin()+1,nums.end()};
        // vector<int> temp2;// = {nums.begin(),nums.end()-1};


        vector<int>temp1 = {nums.begin()+1,nums.end()};
        vector<int> temp2 = {nums.begin(),nums.end()-1};

        // for(int i=0; i<nums.size(); i++)
        // {
        //     if(i != 0) temp1.push_back(nums[i]);
        //     if(i != nums.size()-1) temp2.push_back(nums[i]);
        // }


        dp.assign(temp1.size(),-1);
        int ans1 = helper(0,temp1,dp);

        dp.assign(temp2.size(),-1);
        int ans2 = helper(0,temp2,dp);
        return max(ans1,ans2);
    }
};