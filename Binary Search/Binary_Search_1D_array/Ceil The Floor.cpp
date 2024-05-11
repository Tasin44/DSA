
//problem link : https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401
//coding ninja
/*
Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.

Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.(which is lower bound)
*/
#include<bits/stdc++.h>
using namespace std;
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    pair<int, int> mp;
    int lb = lower_bound(a.begin(), a.end(), x) - a.begin(); // Ceiling index

    int l = 0, r = n - 1, ans = -1; // Initialize ans to a value smaller than any possible element

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= x) {
            ans = a[mid]; // You're going to the right, whatever value you'll get will always be greater than previous
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    int f1, f2;

    if (lb == n) {
        f2 = -1; // No ceiling
    } else {
        f2 = a[lb]; // Ceiling is at lb
    }

    if (ans == -1) {
        f1 = -1; // No floor
    } else {
        f1 = ans; // Floor is the maximum value found during binary search
    }

    mp = make_pair(f1, f2);
    return mp;
}

int main() {
    // Test cases
    vector<int> a1 = {3, 4, 4, 7, 8, 10};
    int n1 = a1.size();
    int x1 = 2;
    pair<int, int> result1 = getFloorAndCeil(a1, n1, x1);
    cout << "Floor and Ceiling of " << x1 << ": " << result1.first << " " << result1.second << endl;

    vector<int> a2 = {3, 4 ,4 ,7 ,8 ,10};
    int n2 = a2.size();
    int x2= 8;
    pair<int, int> result2 = getFloorAndCeil(a2, n2, x2);
    cout << "Floor and Ceiling of " << x2 << ": " << result2.first << " " << result2.second << endl;

    return 0;
}



