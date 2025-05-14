
#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:

   int f(int idx,vector<int>&heights, vector<int>&dp)
   {
      if(idx==0)return 0;//in that index,energy cost is 0

      if(dp[idx]!=-1)return dp[idx];

      int left = f(idx-1,heights,dp)+abs(heights[idx]-heights[idx-1]);

      int right = INT_MAX;

      if(idx>1)
      right=f(idx-2,heights,dp)+abs(heights[idx]-heights[idx-2]);


      return dp[idx]=min(left,right);
   }

    int minimumEnergy(vector<int>& height, int n) {

        vector<int>dp(n+1,-1);

        return f(n-1,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
}
    return 0;
}


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



/*
//Tabulation approach

class Solution {
  public:

   int f(int n,vector<int>&heights, vector<int>&dp)
   {

//      Set an iterative loop that traverses the array( from index 1 to n-1) and
//      for every index calculate jumpOne and jumpTwo and set dp[i] = min(jumpOne, jumpTwo).

      for(int i=1;i<n;i++)
      {
          int left = dp[i-1]+abs(heights[i]-heights[i-1]);

        int right = INT_MAX;
          if(i>1)
         right = dp[i-2]+ abs(heights[i]-heights[i-2]);

          dp[i]=min(left,right);
      }

      return dp[n-1];
   }

    int minimumEnergy(vector<int>& height, int n) {

        vector<int>dp(n,0);
        dp[0]=0;//First, initialize the base condition values, i.e dp[0] as 0.
        return f(n,height,dp);
    }
};



//Time Complexity: O(N)
//
//Reason: We are running a simple iterative loop
//
//Space Complexity: O(N)
//
//Reason: We are using an external array of size ‘n+1’.
*/




/*
//This solution will be accepted for any number of jumps

class Solution {
  public:

   int f(int idx,vector<int>&heights, vector<int>&dp)
   {
      if(idx==0)return 0;//in that index,energy cost is 0

      if(dp[idx]!=-1)return dp[idx];
      int mn=INT_MAX;
      for(int j=1;j<=2 && idx-j>=0;j++)//j<=2 means we can do atmost 2 jumps in this problem
      {
          int left = f(idx-j,heights,dp)+abs(heights[idx]-heights[idx-j]);
          mn=min(mn,left);
      }


      return dp[idx]=mn;
   }

    int minimumEnergy(vector<int>& height, int n) {

        vector<int>dp(n+1,-1);

        return f(n-1,height,dp);
    }
};




*/






















