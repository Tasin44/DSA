
///https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        return  atmost(nums,goal)-atmost(nums,goal-1);
    }

    int atmost(vector<int>& nums, int goal)
    {
        int r=0,l=0,n=nums.size(),sum=0,result=0;
        while(r<n)
        {
          sum+=nums[r];
          while(sum>goal and l<=r)
          {
            sum-=nums[l];
            l++;
          }
          result+=r-l+1;
          r++;
        }
        return result;
    }
};







