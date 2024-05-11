

///https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456?

///formula:
/*
1.if upper bound== lower bound,that means the number is not present in the array
2.if present ,then total number of occurrence will be upper_bound-lower_bound
*/
int count(vector<int> &arr, int n, int x) {
  int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

  int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
  int ans;
  if (lb == ub)
    ans = 0;
  else
    ans = (ub - lb);

  return ans;
}
