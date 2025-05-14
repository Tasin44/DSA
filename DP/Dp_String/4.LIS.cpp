
class Solution {
public:
//tabulation 2nd approach (Easy to understand)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,1);

        for(int i=0;i<n;i++)
        {
          for(int prev=0;prev<=i;prev++)//prev always should be before i
          {
            if(nums[prev]<nums[i])
            dp[i]=max(dp[i],1+dp[prev]);
          }
        }
        return *max_element(dp.begin(), dp.end());
    }

};
/*
Time Complexity: O(N*N)

Reason: There are two nested loops.

Space Complexity: O(N)

Reason: We are only using two rows of size ‘N’.

*/







//memoization

class Solution {
public:

    int f(int i, int prev, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == n) return 0;

        if (dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }
        /*If prev is -1, and if we directly
        use it as an index,means dp[i][-1],which is an
        invalid index and can lead to RTE
        */
        int len = 0;

        if (prev == -1 || nums[i] > nums[prev]) {
            len = max(len, 1 + f(i + 1, i, n, nums, dp));
        }

        len = max(len, f(i + 1, prev, n, nums, dp));

        return dp[i][prev+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, -1, n, nums, dp);
    }
};
/*
no need to use n+1 for the second dp vector(previous index vector)
because of -1,it will turn into 0,n-2 it will turn into
n-1,and when prev_index=n-1,then i must be n,then f will return 0.
So,because of prev_index=n-1,the f will not go ahead.


Time Complexity: O(N*N)

Reason: There are N*N states therefore at max ‘N*N’ new problems will be solved.

Space Complexity: O(N*N) + O(N)

Reason: We are using an auxiliary recursion stack space(O(N)) (see the recursive tree, in the worst case we will go till N calls at a time) and a 2D array ( O(N*N+1)).
*/






//tabulation 1st approach
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1;i>=0;i--)
        {
          for(int prev=i-1;prev>=-1;prev--)//prev always should be before i
          {
            int len = 0;
            len = dp[i + 1][prev+1];
            if(prev == -1 || nums[i] > nums[prev])
            {
                len = max(len, 1 + dp[i + 1][i+1]);
            }

             dp[i][prev+1] = len;
          }
        }
        return dp[0][0];
    }

};
/*
Time Complexity: O(N*N)

Reason: There are two nested loops.

Space Complexity: O(N*N)
*/




///Best Approach


//LIS using binary search (lower bound)


class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.emplace_back(nums[0]);
        int len=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>ans.back())
            {
                ans.emplace_back(nums[i]);
                len++;
            }
            else
            {
                int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                /*without sorting the main array,we can easily do lower bound here,because
                ans vector will always be sorted*/
                ans[idx]=nums[i];
            }
        }

        return len;
    }
};
/*
Time Complexity: O(N*logN)

Reason: We iterate over the array of size N and in every iteration,
we perform a binary search which takes logN time.

Space Complexity: O(N)

Reason: We are using an extra array of size N
*/





/*
Explanation of the lower bound approach:

Example Input:

nums = [10, 9, 2, 5, 3, 7, 101, 18]

Step-by-Step Execution:

Initialization:
        ans = [] (to store potential LIS values)
        Add the first element: ans = [10]
        Set len = 1 (length of LIS so far).

Iterate Over Array:

i = 1, nums[i] = 9:

    9 is not greater than ans.back() = 10.
    Use lower_bound to find the first position in ans where 9 can replace an element
    (to keep ans sorted).
    Replace 10 with 9: ans = [9].
    Length (len) stays 1.

i = 2, nums[i] = 2:

    2 is not greater than ans.back() = 9.
    Use lower_bound to find where 2 can replace an element. Replace 9 with 2:
    ans = [2].
    Length (len) stays 1.

i = 3, nums[i] = 5:

    5 is greater than ans.back() = 2.
    Append 5 to ans:
    ans = [2, 5].
    Length (len) increases to 2.

i = 4, nums[i] = 3:

    3 is not greater than ans.back() = 5.
    Use lower_bound to find where 3 can replace an element. Replace 5 with 3:
    ans = [2, 3].
    Length (len) stays 2.

i = 5, nums[i] = 7:

    7 is greater than ans.back() = 3.
    Append 7 to ans:
    ans = [2, 3, 7].
    Length (len) increases to 3.

i = 6, nums[i] = 101:

    101 is greater than ans.back() = 7.
    Append 101 to ans:
    ans = [2, 3, 7, 101].
    Length (len) increases to 4.

i = 7, nums[i] = 18:

    18 is not greater than ans.back() = 101.
    Use lower_bound to find where 18 can replace an element. Replace 101 with 18:
    ans = [2, 3, 7, 18].
    Length (len) stays 4.

Final ans:

ans = [2, 3, 7, 18]

The length of the LIS is len = 4.


Key Observations:

    ans Always Sorted:
    The ans vector remains sorted because we either append to it or replace an element
    using lower_bound.

    Binary Search for Efficiency:
        lower_bound ensures the algorithm runs in O(nlog⁡n)O(nlogn).
        No need to sort the original array because ans inherently maintains order.

Explanation of Code Lines:

    Appending to ans:
    When nums[i] > ans.back(), we extend the LIS.

    Using lower_bound:
    When nums[i] is smaller than or equal to some elements in ans,
    replace the smallest element greater than or equal to nums[i] to
    maintain the smallest ending values for LIS.

    Why len Works:
    len tracks the size of the ans vector, which directly corresponds to the length of the LIS.



*/




