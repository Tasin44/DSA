

///https://leetcode.com/problems/max-consecutive-ones-iii/submissions/1283102042/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,zero=0,mxlen=0;
        while(r<nums.size())
        {
          if(nums[r]==0)zero++;

          if(zero<=k)
          {
            mxlen=max(mxlen,r-l+1);
          }
    while (zero > k) {// when cnt becomes more than k we reduce our window
            if (nums[l] == 0) {
               zero--;
            }
            l++;
        }
          r++;
        }
     return  mxlen;
    }
};
// Main function for testing
int main() {
    Solution solution;
    vector<int> nums;
    int n, k, temp;

    cout << "Enter the number of elements in the array: ";//11100011110
    cin >> n;

    cout << "Enter the elements of the array (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }

    cout << "Enter the maximum number of 0s that can be flipped: ";//2
    cin >> k;

    int result = solution.longestOnes(nums, k);
    cout << "Maximum number of consecutive 1's: " << result << endl;//6

    return 0;
}
/*
Time Complexity: O(n+k) or O(n+n)=O(2n)=O(n), where n is the length of the input array nums.

Both the left and right pointers only move in one direction from the beginning to the end of the array.
The left pointer never moves backward, and the right pointer keeps advancing.

The while (right < nums.length) loop iterates through each element of the array once,
incrementing the right pointer in each iteration. The left pointer may move forward,
but it never moves backward due to the conditions in the code.

While it is true that the left pointer may traverse the array more than once,
it doesn't happen for every element in the array.
The overall number of operations is linear with respect to the length of the array,
making the time complexity O(n).

In the worst case,
the left pointer moves from the beginning to the end of the array,
and the right pointer also moves from the beginning to the end of the array,
resulting in a total of O(2n) operations.
However, in big O notation, constants are dropped, so it is still considered O(n).

The outer while loop iterates through the array once,
and the inner while loop adjusts the window size by moving the left pointer.
The total number of iterations of both loops combined is at most 2n,
making the time complexity linear, O(n).

Space Complexity: O(1), because the space used by the variables l, r, zeroCount,
and maxLen does not depend on the size of the input array.
*/

