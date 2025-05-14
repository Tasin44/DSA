//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int f(int k,int idx,vector<int>&heights, vector<int>&dp)
    {
        if(idx==0)return 0;

        if(dp[idx]!=-1)return dp[idx];

        int mn=INT_MAX;

        for(int j=1;j<=k && idx-j>=0;j++)
        {
            int right = f(k,idx-j,heights,dp)+abs(heights[idx]-heights[idx-j]);
            mn=min(right,mn);
        }

      return dp[idx]=mn;
    }

    int minimizeCost(int k, vector<int>& arr) {

       int n=arr.size();
       vector<int>dp(n+1,-1);

       return f(k,n-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
