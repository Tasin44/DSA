



//f(2,5) means lcs between s1[0...2] and s2[0....5]

///memoization
class Solution {
public:
    int f(int idx1,int idx2,string &s,string &t,vector<vector<int>>&dp)
    {
        if(idx1<0||idx2<0)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if(s[idx1]==t[idx2])
        return dp[idx1][idx2]=1+f(idx1-1,idx2-1,s,t,dp);

        return dp[idx1][idx2]=max(f(idx1-1,idx2,s,t,dp),f(idx1,idx2-1,s,t,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

     return f(n-1,m-1,text1,text2,dp);
    }
};
/*
Memoization technique:
TC-O(n*m)
SC-for storage in dp vector(O(n*m))+recursion stack space (auxilarly stack space O(n*m))
*/


/*

if we do the code like:


if(text1[i]==text2[j])
    return dp[i][j]=1+subsequence(i-1,j-1,dp,text1,text2);

else
    return dp[i][j]=max(subsequence(i-1,j,dp,text1,text2),subsequence(i,j-1,dp,text1,text2));



With else:

Unnecessary Recursive Calls:

Even when text1[i] == text2[j], the function proceeds to the else block,
making unnecessary recursive calls to subsequence(i-1,j,dp,text1,text2)
and subsequence(i,j-1,dp,text1,text2).

Reduced Memoization Efficiency: While the dp matrix is still used,
the extra recursive calls can lead to more subproblems being computed,
potentially increasing the time complexity.


Why else Leads to TLE:

The additional recursive calls introduced by the else statement can significantly increase
the number of function calls, especially for larger input strings.
This can lead to a time complexity that is closer to exponential,
resulting in Time Limit Exceeded (TLE) errors.

*/







//Tabulation

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        int i,j;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));//because here we'll store 0 to n, 0 to m


          //base case like (idx1<0||idx2<0) return 0
          //So, for i, j : if any of them are 0, then dp[i][j]=0;
          for(i=0;i<=n;i++)
          dp[i][0]=0;

          for(j=1;j<=m;j++)//j should be start from 1 ,else it'll rewrite the previous for loop 0th column
          dp[0][j]=0;



        for(i=1;i<=n;i++)
        {
          for(j=1;j<=m;j++)
          {
              //take
              if(text1[i-1]==text2[j-1])dp[i][j]=1+dp[i-1][j-1];

              //notake
              else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
          }
        }

     return dp[n][m];//here dp[n][m] will contains the value of dp[n-1][m-1]
    }
};
/*
Tabulation technique:
TC-O(n*m)
SC-for storage in dp vector(O(n*m))+no auxilarly stack space will required
*/



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        int i,j;
        vector<int>prev(m+1,0);
        vector<int>cur(m+1,0);


        for(i=1;i<=n;i++)
        {
          for(j=1;j<=m;j++)
          {
              if(text1[i-1]==text2[j-1])cur[j]=1+prev[j-1];//cur=dp[i],prev=dp[i-1]
              else cur[j]=0+max(prev[j],cur[j-1]);
          }
          prev=cur;
        }

     return prev[m];
    }
};
/*
space optimization technique:
TC-O(n*m)
SC-for storage in vector(O(m))+no auxilarly stack space will required
*/






