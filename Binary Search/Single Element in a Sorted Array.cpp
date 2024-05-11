
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

    int n=nums.size();
    int l=0,r=n-1,mid,ans;
    if(nums.size()==1)return nums[0];

    while(l<=r)
    {
       mid=l+(r-l)/2;
       if(mid==0 and nums[mid]!=nums[mid+1])
       {
         ans= nums[mid];break;
       }
       else if(mid==n-1 and nums[mid]!=nums[mid-1])
       {
         ans=nums[mid];break;
       }
       else
       {
          if(nums[mid]==nums[mid+1])
          {
            if((mid)&1)r=mid-1;
            else l=mid+1;

          }
          else if(nums[mid]==nums[mid-1])
          {
            if((mid-1)&1)r=mid-1;
            else l=mid+1;

          }
          else
          {
             ans=nums[mid];break;
          }

       }


    }

    return ans;
   }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 3};
    cout << "Single element: " << sol.singleNonDuplicate(nums) << endl;
    return 0;
}
/*
If you take right as mid - 1, then while condition will be left <= right.
If you take right as mid, then while condition will be left < right.
Both can be used.

*/
