///https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // sort(nums.begin(),nums.end());

        int l=0,r=nums.size()-1,ans=-1;

        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(nums[mid]==target)
            {
              ans=mid;
              break;
            }
            else if(nums[l]<=nums[mid])
            {
               if(nums[l]<=target && nums[mid]>=target)
                r=mid-1;
                else l=mid+1;
            }
            else
            {
                if(nums[mid]<=target && nums[r]>=target)
                {
                    l=mid+1;
                }
                else r=mid-1;
            }

        }

      return ans;
    }
};

// First,we identify the sorted half of the array.

// Once found,we determine if the target is located within this sorted half.

// If not,we eliminate that half from further consideration.

// Conversely,if the target does exist in the sorted half, we eliminate the other half.
