
///https://leetcode.com/problems/count-number-of-nice-subarrays/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

      return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int>& nums, int k)
    {
        int l=0,r=0,n=nums.size(),cnt=0,ans=0;

        while(r<n)
        {
           cnt+=(nums[r]%2);

           /*
            the inner part won't works for "if(cnt>k and l<=r)"" instead of while loop,because
            both odd & even present here,so if we only remove the first element which may be even,
            so removal of a first single element can't be impactful for us,so we need to check all the
            odd element from the begining of the array & remove till the conditon is valid
           */
           while(cnt>k) //and l<=r
           {
               cnt-=(nums[l]%2);
               l++;
           }
           ans+=r-l+1;
         r++;
        }

    return ans;
    }
};
/*
Time Complexity:

Overall: O(N)
Breakdown:
numberOfSubarrays: O(N) due to a single call to atmost with input size N.
atmost: O(N) for the nested loops iterating through the nums vector.
Outer loop (while(r < n)): Iterates N times in the worst case.
Inner loop (while(cnt > k)): This loop might not execute at all for some subarrays,
or it might run up to N times in the worst case (when every element is odd and k is 0).
However, the average number of iterations within the inner loop is constant across all subarrays,
so its overall contribution to the time complexity is considered constant on average.

Space Complexity:
Overall: O(1)
No additional data structures are created within the functions.
*/




