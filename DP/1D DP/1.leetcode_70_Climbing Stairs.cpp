
class Solution {
public:
/*
here we're using memoization,that means going form top to bottom,
for n=2 if we jump 1 ,we'll go back (n-1) means 2-1=1th index,if we jump 2 will go back (n-2) means 2-2=0th index .
That means this is something like fibonnaci numbers

*/
    int fibo(int n,vector<int>&dp)
    {
        if(n<=1)//this is calld edge case
        {
            return n;
        }
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        fibo(n,dp);

    return dp[n]+dp[n-1];
    }
};
