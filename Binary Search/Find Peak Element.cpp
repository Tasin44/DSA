
///https://leetcode.com/problems/find-peak-element/description/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r)
        {
           int mid=l+(r-l)/2;
           if((mid==0||nums[mid-1]< nums[mid]) and ((mid==n-1)|| nums[mid]>nums[mid+1]))
           return mid;
           else if(nums[mid]<nums[mid+1])
           l=mid+1;
           else r=mid-1;
        }
        return l;

    }
};
/*
If arr[i] > arr[i-1]: we are in the left half(in Increasing part),
then the answer will be some where in the right half
If arr[i] > arr[i+1]: we are in the right half.(in decreasing part),
then the answer will be some where in the left half
//if didn't understand these lines,will watch video diagram (from 14th minute)
*/
