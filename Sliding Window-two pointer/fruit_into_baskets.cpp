
///link:https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1?

//This problem comes to amazon
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        map<int,int>cnt;

        int l=0,r=0,mxlen=0;

        while(r<N)
        {

         cnt[fruits[r]]++;

         if(cnt.size()>2)
         {
              while(cnt.size()>2)
             {
                 cnt[fruits[l]]--;
                 if(cnt[fruits[l]]==0)cnt.erase(fruits[l]);//if the fruits is completely removed

                 l+=1;
             }
         }
         else
         {
             mxlen=max(mxlen,r-l+1);
         }


         r++;
        }


    return mxlen;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

/*
Test:
11
3 3 3 1 2 1 1 2 3 3 4
output:5
*/


/*
Time Complexity

Outer While Loop: while (r < N)
 iterates from r = 0 to r = N-1. Thus, it runs N times.

Updating the Map:
  Within each iteration of the outer loop, you add one element to the cnt map.
  Inserting or updating an element in a map is an O(log K) operation,
  where K is the size of the map.
  Since the map can hold at most 3 distinct fruits (before you remove one in the inner while loop),
  this is O(log 3), which simplifies to O(1).

Inner While Loop:
  The inner while (cnt.size() > 2)
  loop shrinks the window from the left side until the map contains at most 2 distinct fruits.
  This loop can potentially iterate up to N times across the entire run of the algorithm,
  but each element is added and removed from the map exactly once, resulting in N operations in total.
  Removing an element from the map or decrementing the count is also an O(log K) operation,
  which again is O(1) because K can be at most 3.

Overall, every operation inside the loops (both outer and inner) is O(1),
and since the loops iterate N times in total, the time complexity is:

Time Complexity: O(N)


Space Complexity

cnt Map:
 The cnt map holds the counts of fruit types.
 At most, it can contain 3 distinct fruit types before you remove one.
 Therefore, the space required for the map is O(3), which simplifies to O(1).

Other Variables:
  The integer variables l, r, and mxlen require O(1) space.

Input Vector:
  The input vector fruits does not count towards additional space complexity
        as it is provided as input and not allocated within the function.

Space Complexity: O(1)


*/







