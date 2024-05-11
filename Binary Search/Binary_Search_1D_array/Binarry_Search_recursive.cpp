
#include<bits/stdc++.h>
using namespace std;

int f(int l, int r, int target, vector<int>& nums) {
        if (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                return f(mid + 1, r, target, nums);
            else
                return f(l, mid - 1, target, nums);
        }
        return -1; // If target is not found
    }

    int search(vector<int>& nums, int target) {
        return f(0, nums.size() - 1, target, nums);
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>v(n);

    for(int i=0;i<n;i++)
    cin>>v[i];

    sort(v.begin(),v.end());

    cout<<f(0,n-1,target,v)<<endl;

}











