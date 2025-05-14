
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:

    bool sub_sum(int idx,vector<int>& arr,int target,vector<vector<int>>&dp )
    {
      if(target==0)return true;//after reducing target by target-arr[idx], if it becomes 0, that means it's possible

      if(idx==0)return(arr[idx]==target);

      if(dp[idx][target]!=-1)return dp[idx][target];

      bool take=false;

      if(arr[idx]<=target)
      take=sub_sum(idx-1,arr,target-arr[idx],dp);

      bool notake=sub_sum(idx-1,arr,target,dp);


     return dp[idx][target]=take|notake;
    }

    bool isSubsetSum(vector<int>& arr, int target) {

        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return sub_sum(n-1,arr,target,dp);
    }
};

int main() {
    vector<int> arr{3, 34, 4, 12, 5, 2};
    int target=9;
    vector<int> arr2{3, 34, 4, 12, 5, 2};
    int target2=30;
    Solution obj; // Create an instance of `Solution`
    cout << obj.isSubsetSum(arr,target) << endl; // Call the `isSubsetSum` function and print the result
    cout << obj.isSubsetSum(arr2,target2) << endl;
    return 0;
}













