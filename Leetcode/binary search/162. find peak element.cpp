class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==1)
        {
            return 0;
        }

 
     
        int lo=0, hi = nums.size()-1;
        int mid;
        while(lo<=hi)
        {
            mid = lo + (hi-lo)/2;

            if(mid>0 and mid<nums.size()-1)
            {
                if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
                {
                    break;

                }
                else if(nums[mid+1]>nums[mid])
                {
                    lo = mid+1;
                }
                else 
                {
                    hi = mid-1;
                }
            }
            else if(mid==0) 
            {
                if(nums[0]>nums[1])
                {
                    return 0;
                }
                else 
                {
                    return 1;
                }


            }
            else 
            {
                if(nums[nums.size()-1]>nums[nums.size()-2])
                {
                    return nums.size()-1;
                }
                else 
                {
                    return nums.size()-2;
                }
            }

        }

        return mid;


    }
};