///https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

///using uppper bound and lower bound function
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int ub=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(lb==ub)
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        else
        {
            v.push_back(lb);
            v.push_back(ub-1);
        }

      return v;
    }
};



///using binary search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int>result={-1,-1};
        int l=0,r=nums.size()-1;
        //for first occurrence
        while(l<=r)
        {
          int mid=l+(r-l)/2;
          if(nums[mid]==target)
          {
            result[0]=mid;
            //if we find the target,we need to move more left to find first occurrence
            r=mid-1;
          }
          else if(nums[mid]<target)
          l=mid+1;
          else r=mid-1;

        }
        l=0,r=nums.size()-1;
        //for last occurrence
        while(l<=r)
        {
          int mid=l+(r-l)/2;
          if(nums[mid]==target)
          {
            result[1]=mid;
            l=mid+1;
            //if we find the element,we need to move more right to find last occurrence
          }
          else if(nums[mid]<target)
          l=mid+1;
          else r=mid-1;

        }

    return result;
    }
};

// time complexity O(log n)
// space complexity O(1)




