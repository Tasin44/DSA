
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int robber(int idx, vector<int>& dp, vector<int>& nums) {

        if (idx < 0) return 0;

        if (idx == 0) return nums[idx];// Base case: no houses left to rob

        if (dp[idx] != -1) return dp[idx];

        // Choose the current element or skip it, and take the maximum

        int take = nums[idx] + robber(idx - 2, dp, nums);// Rob current house
        int notake = 0 + robber(idx - 1, dp, nums);// Skip current house

        return dp[idx] = max(take, notake);
    }

   int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0]; // Only one house to rob
        if (n == 2) return max(nums[0], nums[1]); // Two houses, take the maximum

        // First subproblem: Rob from house 0 to n-2
        vector<int> dp(n, -1); // `dp` size is `n`

        int robfirst= robber(n - 2, dp, nums);

        // Second subproblem: Rob from house 1 to n-1

        vector<int> dp2(n, -1);
        vector<int>numssecond(nums.begin()+1,nums.end());

        int robsecond =robber(n-2,dp2,numssecond);


        // Return the maximum of the two cases
        return max(robfirst,robsecond);
    }
};



int main() {
    vector<int> arr{1,2,3};
    Solution obj; // Create an instance of `Solution`
    cout << obj.rob(arr) << endl; // Call the `rob` function and print the result
    return 0;
}









