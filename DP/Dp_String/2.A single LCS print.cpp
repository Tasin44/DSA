

//For single lCS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Include this for std::reverse
using namespace std;

class Solution {
public:
    void lcs(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Filling the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Reconstructing the LCS
        string ans;
        int i = n, j = m; // Initialize i and j to the bottom-right corner of the DP table
        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                ans += s[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        //The constructed LCS is in reverse order,because we store lcs from last to first
        reverse(ans.begin(), ans.end());

        // Printing the result
        cout << "LCS: " << ans << endl;
    }
};

int main() {
    string s = "abaaa", t = "baabaca";

    Solution obj;
    obj.lcs(s, t); // Call the `lcs` function

    return 0;
}


















