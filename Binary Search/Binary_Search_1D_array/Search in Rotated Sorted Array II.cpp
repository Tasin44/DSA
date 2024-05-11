
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                ++l;
                --r;
             //in this case,we cannot compare that which part of the array is sorted
            //corner case: 1,0,1,1,1 target: 0

            }
            ///if the left half is sorted
            else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target <= nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            //if the right half is sorted
            else {
                if (nums[mid] <= target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    cout << "Output: " << (solution.search(nums, target) ? "true" : "false") << endl; // Output: true

    target = 3;
    cout << "Output: " << (solution.search(nums, target) ? "true" : "false") << endl; // Output: false

    return 0;
}
