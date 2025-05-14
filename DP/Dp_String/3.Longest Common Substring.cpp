
//Tabulation approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {

        int n=s1.size();
        int m=s2.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));//because we've to use 0 to nth index of the dp array

        //we know nth index means n-1th index

        // for(int i=0;i<=n;i++)dp[i][0]=0;//there is no necessary to do like this
        // for(int j=1;j<=m;j++)dp[0][j]=0;//there is no necessary to do like this


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {

                if(s1[i-1]==s2[j-1])
                {

                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans, dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }


     return ans;
    }
};


int main() {
    int t=1;
    //cin >> t;
//    while (t--) {
        string s1 = "ABCDGH", s2 = "ACDGHR";
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
//    }
}


/*
Note: dp[n][m] will not give us the answer; rather the maximum value in the entire dp array
will give us the length of the longest common substring.
This is because there is no restriction that the longest common substring is present at the
end of both the strings.

Complexity Analysis

Time Complexity: O(N*M)

Reason: There are two nested loops

Space Complexity: O(N*M)

Reason: We are using an external array of size ‘N*M)’. Stack Space is eliminated.

*/




