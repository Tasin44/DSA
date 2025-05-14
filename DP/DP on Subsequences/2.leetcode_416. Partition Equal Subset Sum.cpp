
/*
We need to partition the array(say S) into two subsets(say S1 and S2).

According to the question:

    Sum of elements of S1 + sum of elements of S2 = sum of elements of S.
    Sum of elements of S1 = sum of elements of S2.

These two conditions imply that S1 = S2 = (S/2).


Now,

    If S (sum of elements of the input array) is odd ,
    there is no way we can divide it into two equal halves, so we can simply return false.

    If S is even, then we need to find a subsequence in the input array whose sum is equal
    to S/2 because if we find one subsequence with sum S/2,
    the remaining elements sum will be automatically S/2. So,
    we can partition the given array. Hence we return true.

*/
//MEMOIZATION
#include <iostream>     // For standard I/O operations
#include <vector>       // For using the `vector` container
#include <numeric>      // For `accumulate` function
using namespace std;

class Solution {
public:

    bool partition(int idx,vector<vector<int>>&dp,vector<int>& nums,int sum)
    {
        if(sum==0)return true;// Base case: If the target sum is 0, we found a valid partition

    // Base case: If we have considered all elements and the target is still not 0, return false
        if(idx==0)
        return (nums[idx]==sum);

        if(idx<0)return false;

        if(dp[idx][sum]!=-1)return dp[idx][sum];

        bool take=false;

        if(nums[idx]<=sum) //Include the current element if it doesn't exceed the target
        take=partition(idx-1,dp,nums,sum-nums[idx]);

        bool notake=partition(idx-1,dp,nums,sum);

    return dp[idx][sum]=take|notake; // Store the result in the DP table and return
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum;


        sum=accumulate(nums.begin(),nums.end(),0);

        if(sum&1)return false;

        else{

            sum=sum/2;
            vector<vector<int>>dp(n,vector<int>(sum+1,-1));

            return partition(n-1,dp,nums,sum);

        }
    }
};

int main() {
    vector<int> arr{1,5,11,5};
    int target=9;
    vector<int> arr2{1,2,3,5};
    Solution obj; // Create an instance of `Solution`
    cout << obj.canPartition(arr) << endl; // Call the `isSubsetSum` function and print the result
    cout << obj.canPartition(arr2) << endl;
    return 0;
}





/*
Complexity Analysis

Time Complexity: O(N*K) + O(N)

Reason: There are N*K states therefore at max ‘N*K’ new problems
will be solved and we are running a for loop for ‘N’ times to calculate the total sum


Space Complexity: O(N*K) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).
*/





//Tabulation

class Solution {
public:

    bool canPartition(vector<int>& nums) {
            int n=nums.size(),sum;
            sum=accumulate(nums.begin(),nums.end(),0);

            if(sum&1)return false;

            sum=sum/2;
            vector<vector<int>>dp(n,vector<int>(sum+1,0));

            for(int i=0;i<n;i++)
            {
                dp[i][0]=true;
            }
            if(nums[0]<=sum)dp[0][nums[0]]=true;


            for(int idx=1;idx<n;idx++)
            {
                for(int target=1;target<=sum;target++)
                {
                    bool take=false;
                    if(nums[idx]<=target)
                    take=dp[idx-1][target-nums[idx]];
                    bool notake = dp[idx-1][target];

                    dp[idx][target]=take|notake;
                }
            }

        return dp[n-1][sum];
    }
};














