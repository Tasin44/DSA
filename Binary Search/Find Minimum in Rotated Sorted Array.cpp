

///https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include <iostream>
#include <vector>
#include <climits> // Include this header for INT_MAX
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
       int l = 0, r = nums.size() - 1,ans=INT_MAX;
       while (l <= r) {
          int mid = l + (r - l) / 2;
            //search space is already sorted
           //then arr[low] will always be
          //the minimum in that search space:
          if(nums[l] <= nums[r])
          {
            ans = min(ans,nums[l]);
            break;
          }
          if (nums[l] <= nums[mid])
          {
            ans = min(ans, nums[l]);
            l = mid + 1;
            //  left part is sorted.So,pick the leftmost element i.e.arr[low].
           //  Now,compare it with 'ans' and update 'ans' with the smaller value .
          //  Now, eliminate this left half(i.e. low = mid+1).
          }

          else
          {
            ans = min(ans, nums[mid]);
            r = mid - 1;
            // The right half is sorted.So,pick the leftmost element i.e. arr[mid].
           // Now,compare it with 'ans' and update 'ans' with the smaller value.
          // Now, we will eliminate this right half(i.e. high = mid-1).
          }
       }
       return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element: " << sol.findMin(nums) << endl; // Output: 0

    nums = {3, 4, 5, 1, 2};
    cout << "Minimum element: " << sol.findMin(nums) << endl; // Output: 1

    return 0;
}
