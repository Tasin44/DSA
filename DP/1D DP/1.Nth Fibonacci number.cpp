

//using Memoization (Top Down approach)

/*
#include<iostream>
#include <vector>
using namespace std;

int fibonacci(int n,vector<int>&dp)
{
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];

    return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);//reason behind n+1 is we've to start from 0 & continue till n

    cout<<fibonacci(n,dp)<<endl;

  return 0;
}
*/

/*
TC: O(n)
Only one depth call from n to 1 so this is linear pattern

SC:
Recursion stack space + vector space /size
=O(n) + O(n)

*/


//using tabulation
/*
#include<iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1);

    dp[0]=0, dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<dp[n]<<endl;

  return 0;
}
*/
/*
TC: O(n)
Only because of for loop

SC:
vector space /size { no Recursion stack space used}
=O(n)

*/





//using space optimization
#include<iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int prev=1,prev2=0,cur;

    for(int i=2;i<=n;i++)
    {
        cur= prev2+prev;
        prev2=prev;
        prev=cur;
    }

    cout<<cur<<endl;

    return 0;
}




















