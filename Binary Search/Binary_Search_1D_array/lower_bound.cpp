#include <iostream>
#include <vector>
using namespace std;

/*
//procedure 1
int lowerBound(vector<int>& arr, int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
*/

//procedure 2
int lowerBound(vector<int>& arr, int n, int x) {
    int l = 0, r = n - 1, ans=n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x) {
            ans=min(ans,mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}


int main() {
    // Example usage
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int x = 9;
    cout << "Lower bound of " << x << " in the array is: " << lowerBound(arr, n, x) << endl;
    return 0;
}
