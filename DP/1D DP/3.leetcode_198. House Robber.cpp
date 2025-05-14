#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int robber(int idx, vector<int>& dp, vector<int>& nums) {
        if (idx == 0) return nums[idx];// Base cases
        if (idx < 0) return 0;

        if (dp[idx] != -1) return dp[idx];

         // Choose the current element or skip it, and take the maximum

        int take = nums[idx] + robber(idx - 2, dp, nums);
        int notake = 0 + robber(idx - 1, dp, nums);

        return dp[idx] = max(take, notake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // `dp` size is `n`
        return robber(n - 1, dp, nums);
    }
};

int main() {
    vector<int> arr{2, 1, 4, 9};
    Solution obj; // Create an instance of `Solution`
    cout << obj.rob(arr) << endl; // Call the `rob` function and print the result
    return 0;
}



//Complexity Analysis
//
//Time Complexity: O(N)
//
//Reason: The overlapping subproblems will return the answer in constant time O(1).
//Therefore the total number of new subproblems we solve is ‘n’.
//Hence total time complexity is O(N).
//
//
//Space Complexity: O(N)
//
//Reason: We are using a recursion stack space(O(N)) and an array (again O(N)).
//Therefore total space complexity will be O(N) + O(N) ≈ O(N)





///tabulation

class Solution {
public:
    int robber(int n,vector<int>&dp,vector<int>&nums)
    {
        dp[0]= nums[0];

        for(int i=1;i<n;i++)
        {
            int take=nums[i];
            if(i>1)
            take+=dp[i-2];
            int notake=dp[i-1];

            dp[i]=max(take,notake);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {

        int n=nums.size();
        vector<int>dp(n,0);

        return robber(n,dp,nums);
    }
};


//Time Complexity: O(N)
//
//Reason: We are running a simple iterative loop
//
//Space Complexity: O(N)
//
//Reason: We are using an external array of size ‘n+1’.










